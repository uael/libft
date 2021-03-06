/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc/ft_palloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/internal.h"

void	*ft_palloc(t_mpool pool, size_t sz)
{
	const t_mpool				p = pool ? pool : g_heap;
	const struct s_mpool_hdr	*hdr = (const struct s_mpool_hdr *)p;

	return g_ops[hdr->mid]->alloc(p, sz);
}
