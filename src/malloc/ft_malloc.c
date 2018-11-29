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

struct				s_mmapl
{
	struct s_mmapl	*next;
	struct s_mmap	mmap;
};

struct				s_heap
{
	struct s_blk	blks[12];
	struct s_bin	*free_bins;
	struct s_mmapl	*free_mmapl;
	struct s_mmapl	*mmapl;
};

static bool binhas(struct s_bin *bin, uint8_t *ppos)
{
	const uint8_t nmap = sizeof(bin->binmap) / sizeof(*bin->binmap);

	*ppos = 0;
	while (*ppos < nmap)
	{
		if (bin->binmap[*ppos]) return (true);
		++*ppos;
	}
	return (false);
}

static struct s_bin *binfind(struct s_bin *bin, uint8_t *ppos)
{
	if (bin == NULL)
		return (false);
	if (binhas(bin, ppos))
		return (bin);
	return (binfind(bin->next, ppos));
}

static int nb_pages;
static int nb_free_pages;

static void heap_init(struct s_heap *heap)
{
	const uint8_t	nblk = sizeof(heap->blks) / sizeof(*heap->blks);
	const uint8_t	nmap = sizeof(heap->blks->freemask) / sizeof(*heap->blks->freemask);
	uint8_t			i;
	uint8_t			j;
	uint8_t			k;

	i = 0;
	while (i < nblk)
	{
		heap->blks[i].bins = NULL;
		heap->blks[i].nbyte = (uint16_t)(1 << i);
		k = 0;
		j = (uint8_t)(PAGE_SIZE / (1 << i));
		while (k < nmap)
		{
			heap->blks[i].freemask[k++] = ~(~0ULL << j);
			j = j >= (sizeof(uint64_t) * BITSPERBYTE)
				? j - (sizeof(uint64_t) *  BITSPERBYTE) : 0;
		}
		++i;
	}
	heap->free_bins = NULL;
	heap->free_mmapl = NULL;
	heap->mmapl = NULL;
}

static void heap_fini(struct s_heap *heap)
{
	const uint8_t	nblk = sizeof(heap->blks) / sizeof(*heap->blks);
	uint8_t			i;
	struct s_bin	*bin;
	struct s_bin	*next;
	struct s_bin	*mapped_bin;

	struct s_mmapl	*mmapl;
	struct s_mmapl	*mmapl_next;
	struct s_mmapl	*mapped_mmapl;

	i = 0;
	mapped_bin = NULL;
	while (i < nblk)
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

	mapped_mmapl = NULL;
	mmapl = heap->mmapl;
	while (mmapl)
	{
		mmapl_next = mmapl->next;

		munmap(mmapl->mmap.mem, mmapl->mmap.size);
		++nb_free_pages;

		if (((uintptr_t)mmapl % PAGE_SIZE) == 0)
		{
			mmapl->next = mapped_mmapl;
			mapped_mmapl = mmapl;
		}

		mmapl = mmapl_next;
	}
	mmapl = heap->free_mmapl;
	while (mmapl)
	{
		mmapl_next = mmapl->next;

		if (((uintptr_t)mmapl % PAGE_SIZE) == 0)
		{
			mmapl->next = mapped_mmapl;
			mapped_mmapl = mmapl;
		}

		mmapl = mmapl_next;
	}
	while (mapped_mmapl)
	{
		mmapl_next = mapped_mmapl->next;
		munmap(mapped_mmapl, PAGE_SIZE);
		++nb_free_pages;
		mapped_mmapl = mmapl_next;
	}
}

static int bininit(struct s_bin *bin, struct s_blk *blk)
{
	const uint8_t nmap = sizeof(bin->binmap) / sizeof(*bin->binmap);
	uint8_t i;

	bin->mmap.mem = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE,
		MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (bin->mmap.mem == MAP_FAILED)
		return (-errno);
	++nb_pages;
	bin->blk = blk;
	bin->mmap.size = PAGE_SIZE;
	i = 0;
	while (i < nmap)
	{
		bin->binmap[i] = blk->freemask[i];
		++i;
	}
	return (0);
}

static bool bin_isfree(struct s_bin *bin)
{
	return (!ft_memcmp(bin->binmap, bin->blk->freemask, sizeof(bin->binmap)));
}

static struct s_bin *blkfind(struct s_heap *heap, struct s_blk *blk, uint8_t *ppos)
{
	size_t			i;
	struct s_bin	*bin;

	if ((bin = binfind(blk->bins, ppos)))
		return (bin);
	if (!heap->free_bins)
	{
		bin = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE,
			MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
		if (bin == MAP_FAILED)
			return (NULL);
		++nb_pages;
		i = 0;
		while (i + sizeof(struct s_bin) < PAGE_SIZE)
		{
			*bin = (struct s_bin){ };
			bin->next = heap->free_bins;
			heap->free_bins = bin;
			++bin;
			i += sizeof(struct s_bin);
		}
	}
	bin = heap->free_bins;
	heap->free_bins = bin->next;
	bin->next = blk->bins;
	*ppos = 0;
	return (bininit(bin, blk) ? NULL : (blk->bins = bin));
}

static void			*alloc_lrg(struct s_heap *heap, size_t sz)
{
	size_t			i;
	struct s_mmapl	*m;

	if (!heap->free_mmapl) {
		m = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE,
			MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
		if (m == MAP_FAILED)
			return (NULL);
		++nb_pages;
		i = 0;
		while (i + sizeof(struct s_bin) < PAGE_SIZE)
		{
			*m = (struct s_mmapl){ };
			m->next = heap->free_mmapl;
			heap->free_mmapl = m;
			++m;
			i += sizeof(struct s_mmapl);
		}
	}
	m = heap->free_mmapl;
	heap->free_mmapl = m->next;
	m->next = heap->mmapl;
	heap->mmapl = m;

	sz = (sz + PAGE_SIZE - 1) & -PAGE_SIZE;
	m->mmap.mem = mmap(NULL, sz, PROT_READ | PROT_WRITE,
					   MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (m->mmap.mem == MAP_FAILED)
		return (NULL);
	++nb_pages;
	m->mmap.size = sz;
	return m->mmap.mem;
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
		return (alloc_lrg(heap, sz));
	bit = 31 - __builtin_clz(sz);
	blk = heap->blks + (sz > 2 ? ((int)bit) : (int)(sz - 1));
	bin = blkfind(heap, blk, &pos);
	if (bin == NULL)
		return (NULL);
	bit = __builtin_ctzll(bin->binmap[pos]);
	bin->binmap[pos] ^= (1 << bit);
	pos *= (sizeof(uint64_t) * BITSPERBYTE);
	pos += bit;
	return (bin->mmap.mem + (blk->nbyte * pos));
}

static struct s_mmapl	**mmaplbymem(struct s_heap *heap, void *mem)
{
	struct s_mmapl *hd;
	struct s_mmapl **phd;

	phd = &heap->mmapl;
	hd = heap->mmapl;
	while (hd)
	{
		if (hd->mmap.mem <= mem && (hd->mmap.mem + hd->mmap.size) > mem)
			return (phd);
		phd = &hd->next;
		hd = hd->next;
	}
	return (NULL);
}

static struct s_bin		**binbymem(struct s_heap *heap, void *mem)
{
	const uint8_t	nblk = sizeof(heap->blks) / sizeof(*heap->blks);
	struct s_blk	*blk;
	struct s_bin	**phd;
	struct s_bin	*hd;
	uint8_t			i;

	i = 0;
	while (i < nblk)
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
	struct s_mmapl	**pmmapl;
	struct s_mmapl	*mmapl;
	struct s_bin	**pbin;
	struct s_bin	*bin;
	uint8_t			i;
	uint8_t			pos;

	if (ptr == NULL)
		return ;
	mem = (void *)((uintptr_t)ptr & -PAGE_SIZE);
	if ((pmmapl = mmaplbymem(heap, mem)))
	{
		mmapl = *pmmapl;
		munmap(mmapl->mmap.mem, mmapl->mmap.size);
		++nb_free_pages;

		*pmmapl = mmapl->next;
		mmapl->next = heap->free_mmapl;
		heap->free_mmapl = mmapl;
	}
	else if ((pbin = binbymem(heap, mem)))
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
