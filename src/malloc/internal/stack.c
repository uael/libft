/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc/internal/stack.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int			stack_init(struct s_mpool *stack, void *conf)
{
	(void)stack;
	(void)conf;
	return (1);
}

static void			stack_fini(struct s_mpool *pool)
{
	(void)pool;
}

static void			*stack_alloc(struct s_mpool *stack, size_t sz)
{
	(void)stack;
	(void)sz;
	return (NULL);
}

static void			*stack_realloc(struct s_mpool *pool, void *ptr, size_t sz)
{
	(void)pool;
	(void)ptr;
	(void)sz;
	return (NULL);
}

static int			stack_free(struct s_mpool *stack, void *ptr)
{
	(void)stack;
	(void)ptr;
	return (1);
}

static struct s_mpool			g_stacks[FT_MALLOC_MAX_MPOOL];
static const struct s_mpool_def g_stack_stk = {
	.mpool_size = sizeof(struct s_mpool),
	.pools = g_stacks,
	.ops = {
		.init = stack_init,
		.fini = stack_fini,
		.alloc = stack_alloc,
		.realloc = stack_realloc,
		.free = stack_free,
	}
};

const struct s_mpool_def *g_stack_def = &g_stack_stk;
