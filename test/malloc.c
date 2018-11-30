/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test/malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/malloc.h>
#include <ft/stdio.h>

int main(void)
{
	t_mpool pool;
	void *ptrs[1024], *ptr1 = NULL, *ptr2 = NULL, *begin = NULL;

	ft_mpool(g_heap_def, NULL, &pool);

	for (size_t i = 0; i < 1024; ++i) {
		ptrs[i] = ft_palloc(pool, 1024);
		ft_printf("%p\n", ptrs[i]);
		if (!begin) begin = ptrs[i];
	}

	ptr1 = ft_palloc(pool, 4000);
	ptr2 = ft_palloc(pool, 4000);

	ft_pfree(pool, ptr2);
	ft_pfree(pool, ptr1);

	for (size_t i = 0; i < 1024; ++i)
		ft_pfree(pool, ptrs[i]);

	return 42;
}
