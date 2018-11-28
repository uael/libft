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

#define MIN_ALLOC ( 128)
#define TINY_MIN  (   1)
#define PAGE_SIZE (4096)

struct				s_blk
{
	struct s_bin	*page;
	uint16_t		nubit;
};

struct				s_bin
{
	struct s_blk	*blk;
	struct s_bin	*next;

	void			*mem;
	size_t			size;

	uint64_t		binmap[MIN_ALLOC / (sizeof(uint64_t) * BITSPERBYTE)];
};

struct				s_heap
{
	struct s_bin	*free;
	struct s_blk	blks[12];
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

static int bininit(struct s_bin *bin, struct s_blk *blk)
{
	const uint8_t nmap = sizeof(bin->binmap) / sizeof(*bin->binmap);
	uint8_t i;

	bin->mem = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE,
		MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (bin->mem == MAP_FAILED)
		return (-errno);
	bin->blk = blk;
	bin->size = PAGE_SIZE;
	i = 0;
	while (i < nmap)
		bin->binmap[i++] = 0xffffffffffffffff;
	return (0);
}

static struct s_bin *blkfind(struct s_heap *heap, struct s_blk *blk, uint8_t *ppos)
{
	size_t			i;
	struct s_bin	*bin;

	if ((bin = binfind(blk->page, ppos)))
		return (bin);
	if (!heap->free)
	{
		bin = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE,
			MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
		if (bin == MAP_FAILED)
			return (NULL);
		i = 0;
		while (i + sizeof(struct s_bin) < PAGE_SIZE)
		{
			*bin = (struct s_bin){ };
			bin->next = heap->free;
			heap->free = bin;
			++bin;
			i += sizeof(struct s_bin);
		}
	}
	bin = heap->free;
	heap->free = bin->next;
	bin->next = blk->page;
	*ppos = 0;
	return (bininit(bin, blk) ? NULL : (blk->page = bin));
}

static void			*alloc(struct s_heap *heap, size_t sz)
{
	struct s_blk	*blk;
	struct s_bin	*bin;
	uint64_t		bit;
	uint8_t			pos;

	if (sz == 00 || sz > 2048)
		return (NULL);
	if (sz <= 2)
		blk = heap->blks + (sz - 1);
	else
		blk = heap->blks + (32 - __builtin_clz(sz));
	bin = blkfind(heap, blk, &pos);
	if (bin == NULL)
		return (NULL);
	bit = bin->binmap[pos] & -bin->binmap[pos];
	bin->binmap[pos] ^= bit;
	pos *= (sizeof(uint64_t) * BITSPERBYTE);
	pos += (64 - (__builtin_clzll(bit) + 1));
	return (bin->mem + (TINY_MIN * pos));
}

int main(void)
{
	void *ptr = NULL;
	struct s_heap heap = {
		.blks = {
			{ .nubit = 1 },
			{ .nubit = 2 },
			{ .nubit = 4 },
			{ .nubit = 8 },
			{ .nubit = 16 },
			{ .nubit = 32 },
			{ .nubit = 64 },
			{ .nubit = 128 },
			{ .nubit = 256 },
			{ .nubit = 512 },
			{ .nubit = 1024 },
			{ .nubit = 2048 },
		}
	};

	for (size_t i = 0; i < 2048; ++i)
	{
		ptr = alloc(&heap, i);
		ft_printf("%p\n", ptr);
	}
	(void)ptr;
	return 42;
}
