/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc/ft_malloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/malloc.h"
#include "ft/stdlib.h"
#include "ft/stdio.h"

#include <stdbool.h>
#include <values.h>
#include <errno.h>
#include <sys/mman.h>
#include <stdlib.h>

#define MIN_ALLOC ( 128)
#define PAGE_SIZE (4096)

struct				s_mmap
{
	void			*mem;
	size_t			size;
};

struct				s_blk
{
	struct s_bin	*bins;
	uint16_t		nbyte;
	uint64_t		freemask[MIN_ALLOC / (sizeof(uint64_t) * BITSPERBYTE)];
};

struct				s_bin
{
	struct s_blk	*blk;
	struct s_bin	*next;

	struct s_mmap	mmap;

	uint64_t		binmap[MIN_ALLOC / (sizeof(uint64_t) * BITSPERBYTE)];
};

struct				s_lrg
{
	struct s_lrg	*next;
	struct s_mmap	mmap;
};

struct				s_heap
{
	struct s_blk	blks[12];
	struct s_bin	*free_bins;
	struct s_lrg	*free_lrgs;
	struct s_lrg	*lrgs;
};

static struct s_bin *bin_find(struct s_bin *bin, uint8_t *ppos)
{
	if (bin == NULL)
		return (NULL);
	*ppos = 0;
	while (*ppos < COUNT_OF(bin->binmap))
	{
		if (bin->binmap[*ppos]) return (bin);
		++*ppos;
	}
	return (bin_find(bin->next, ppos));
}

static int nb_pages;
static int nb_free_pages;

static void			heap_init(struct s_heap *heap)
{
	uint8_t			i;
	uint8_t			j;
	uint8_t			k;

	i = 0;
	while (i < COUNT_OF(heap->blks))
	{
		heap->blks[i].bins = NULL;
		heap->blks[i].nbyte = (uint16_t)(1 << i);
		k = 0;
		j = (uint8_t)(PAGE_SIZE / (1 << i));
		while (k < COUNT_OF(heap->blks->freemask))
		{
			heap->blks[i].freemask[k++] = ~(~0ULL << j);
			j = j >= (sizeof(uint64_t) * BITSPERBYTE)
				? j - (sizeof(uint64_t) *  BITSPERBYTE) : 0;
		}
		++i;
	}
	heap->free_bins = NULL;
	heap->free_lrgs = NULL;
	heap->lrgs = NULL;
}

static void			heap_fini(struct s_heap *heap)
{
	uint8_t			i;
	struct s_bin	*bin;
	struct s_bin	*next;
	struct s_bin	*mapped_bin;

	struct s_lrg	*lrg;
	struct s_lrg	*lrg_next;
	struct s_lrg	*mapped_lrg;

	i = 0;
	mapped_bin = NULL;
	while (i < COUNT_OF(heap->blks))
	{
		bin = heap->blks[i].bins;
		heap->blks[i].bins = NULL;
		while (bin)
		{
			next = bin->next;
			munmap(bin->mmap.mem, bin->mmap.size);
			++nb_free_pages;
			if (((uintptr_t)bin % PAGE_SIZE) == 0)
			{
				bin->next = mapped_bin;
				mapped_bin = bin;
			}
			bin = next;
		}
		++i;
	}
	bin = heap->free_bins;
	heap->free_bins = NULL;
	while (bin)
	{
		next = bin->next;

		if (((uintptr_t)bin % PAGE_SIZE) == 0)
		{
			bin->next = mapped_bin;
			mapped_bin = bin;
		}

		bin = next;
	}
	while (mapped_bin)
	{
		next = mapped_bin->next;
		munmap(bin, PAGE_SIZE);
		++nb_free_pages;
		mapped_bin = next;
	}

	mapped_lrg = NULL;
	lrg = heap->lrgs;
	while (lrg)
	{
		lrg_next = lrg->next;

		munmap(lrg->mmap.mem, lrg->mmap.size);
		++nb_free_pages;

		if (((uintptr_t)lrg % PAGE_SIZE) == 0)
		{
			lrg->next = mapped_lrg;
			mapped_lrg = lrg;
		}

		lrg = lrg_next;
	}
	lrg = heap->free_lrgs;
	while (lrg)
	{
		lrg_next = lrg->next;

		if (((uintptr_t)lrg % PAGE_SIZE) == 0)
		{
			lrg->next = mapped_lrg;
			mapped_lrg = lrg;
		}

		lrg = lrg_next;
	}
	while (mapped_lrg)
	{
		lrg_next = mapped_lrg->next;
		munmap(mapped_lrg, PAGE_SIZE);
		++nb_free_pages;
		mapped_lrg = lrg_next;
	}
}

static int			bin_init(struct s_bin *bin, struct s_blk *blk)
{
	uint8_t			i;

	bin->mmap.mem = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE,
		MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (bin->mmap.mem == MAP_FAILED)
		return (-errno);
	++nb_pages;
	bin->blk = blk;
	bin->mmap.size = PAGE_SIZE;
	i = 0;
	while (i < COUNT_OF(bin->binmap))
	{
		bin->binmap[i] = blk->freemask[i];
		++i;
	}
	return (0);
}

static bool			bin_isfree(struct s_bin *bin)
{
	return (!ft_memcmp(bin->binmap, bin->blk->freemask, sizeof(bin->binmap)));
}

static struct s_bin	*blk_find(struct s_heap *heap, struct s_blk *blk,
	uint8_t *ppos)
{
	size_t			i;
	struct s_bin	*bin;

	if ((bin = bin_find(blk->bins, ppos)))
		return (bin);
	if (!heap->free_bins)
	{
		bin = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE,
			MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
		if (bin == MAP_FAILED)
			return (NULL);
		++nb_pages;
		i = 0;
		while ((i += sizeof(struct s_bin)) < PAGE_SIZE)
		{
			*bin = (struct s_bin){ };
			bin->next = heap->free_bins;
			heap->free_bins = bin;
			++bin;
		}
	}
	bin = heap->free_bins;
	heap->free_bins = bin->next;
	bin->next = blk->bins;
	*ppos = 0;
	return (bin_init(bin, blk) ? NULL : (blk->bins = bin));
}

static int			lrg_init(struct s_lrg *lrg, size_t sz)
{
	sz = (sz + PAGE_SIZE - 1) & -PAGE_SIZE;
	lrg->mmap.mem = mmap(NULL, sz, PROT_READ | PROT_WRITE,
		MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (lrg->mmap.mem == MAP_FAILED)
		return (-errno);
	++nb_pages;
	lrg->mmap.size = sz;
	return (0);
}

static void			*lrg_alloc(struct s_heap *heap, size_t sz)
{
	size_t			i;
	struct s_lrg	*lrg;

	if (!heap->free_lrgs) {
		lrg = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE,
			MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
		if (lrg == MAP_FAILED)
			return (NULL);
		++nb_pages;
		i = 0;
		while ((i += sizeof(struct s_bin)) < PAGE_SIZE)
		{
			*lrg = (struct s_lrg){ };
			lrg->next = heap->free_lrgs;
			heap->free_lrgs = lrg;
			++lrg;
		}
	}
	lrg = heap->free_lrgs;
	heap->free_lrgs = lrg->next;
	lrg->next = heap->lrgs;
	heap->lrgs = lrg;
	return (lrg_init(lrg, sz) ? NULL : lrg->mmap.mem);
}

static void			*alloc(struct s_heap *heap, size_t sz)
{
	struct s_blk	*blk;
	struct s_bin	*bin;
	uint64_t		bit;
	uint8_t			pos;

	if (sz == 0)
		return (NULL);
	if (sz > 2048)
		return (lrg_alloc(heap, sz));
	blk = heap->blks + (sz > 2 ? (31 - __builtin_clz(sz)) : (int)(sz - 1));
	bin = blk_find(heap, blk, &pos);
	if (bin == NULL)
		return (NULL);
	bit = __builtin_ctzll(bin->binmap[pos]);
	bin->binmap[pos] ^= (1 << bit);
	pos *= (sizeof(uint64_t) * BITSPERBYTE);
	pos += bit;
	return (bin->mmap.mem + (blk->nbyte * pos));
}

static struct s_lrg	**lrg_bymem(struct s_heap *heap, void *mem)
{
	struct s_lrg	*hd;
	struct s_lrg	**phd;

	phd = &heap->lrgs;
	hd = heap->lrgs;
	while (hd)
	{
		if (hd->mmap.mem <= mem && (hd->mmap.mem + hd->mmap.size) > mem)
			return (phd);
		phd = &hd->next;
		hd = hd->next;
	}
	return (NULL);
}

static struct s_bin	**bin_bymem(struct s_heap *heap, void *mem)
{
	struct s_blk	*blk;
	struct s_bin	**phd;
	struct s_bin	*hd;
	uint8_t			i;

	i = 0;
	while (i < COUNT_OF(heap->blks))
	{
		blk = heap->blks + i;
		phd = &blk->bins;
		hd = blk->bins;
		while (hd)
		{
			if (hd->mmap.mem == mem)
				return (phd);
			phd = &hd->next;
			hd = hd->next;
		}
		++i;
	}
	return (NULL);
}

static void			ft_mfree(struct s_heap *heap, void *ptr)
{
	void			*mem;
	struct s_lrg	**plrg;
	struct s_lrg	*lrg;
	struct s_bin	**pbin;
	struct s_bin	*bin;
	uint8_t			i;
	uint8_t			pos;

	if (ptr == NULL)
		return ;
	mem = (void *)((uintptr_t)ptr & -PAGE_SIZE);
	if ((plrg = lrg_bymem(heap, mem)))
	{
		lrg = *plrg;
		munmap(lrg->mmap.mem, lrg->mmap.size);
		++nb_free_pages;

		*plrg = lrg->next;
		lrg->next = heap->free_lrgs;
		heap->free_lrgs = lrg;
	}
	else if ((pbin = bin_bymem(heap, mem)))
	{
		bin = *pbin;
		pos = (uint8_t)((ptr - mem) / bin->blk->nbyte);
		i = 0;
		while (pos > (sizeof(uint64_t) * BITSPERBYTE))
		{
			++i;
			pos -= (sizeof(uint64_t) * BITSPERBYTE);
		}
		if ((bin->binmap[i] & (1 << pos))) {
			ft_fprintf(g_stderr, "Double free %p\n", ptr);
			exit(21); /* Double free */
		}
		bin->binmap[i] ^= (1 << pos);
		if (bin->blk->bins->next && bin_isfree(bin))
		{
			munmap(bin->mmap.mem, bin->mmap.size);
			++nb_free_pages;

			*pbin = bin->next;
			bin->next = heap->free_bins;
			heap->free_bins = bin;
		}
	}
}

int main(void)
{
	void *ptrs[1024], *ptr1 = NULL, *ptr2 = NULL, *begin = NULL;
	struct s_heap heap;

	heap_init(&heap);

	for (size_t i = 0; i < 1024; ++i) {
		ptrs[i] = alloc(&heap, 1024);
		ft_printf("%p\n", ptrs[i]);
		if (!begin) begin = ptrs[i];
	}

	ptr1 = alloc(&heap, 4000);
	ptr2 = alloc(&heap, 4000);

	ft_mfree(&heap, ptr2);
	ft_mfree(&heap, ptr1);

	for (size_t i = 0; i < 1024; ++i)
		ft_mfree(&heap, ptrs[i]);

	heap_fini(&heap);

	ft_printf("unmapped/mapped pages: %d/%d\n", nb_free_pages, nb_pages);

	return 42;
}
