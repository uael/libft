/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifsread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:53:28 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/07 09:53:34 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_ifsread(t_ifs *self, t_car *buf, t_usz n)
{
	ssize_t	r;
	t_usz	i;
	t_usz	j;
	t_list	*node;

	if ((r = ft_ifsbuf(self, n)) <= 0)
		return (r);
	node = self->buf;
	i = 0;
	while (i < n)
		if (!node->content_size)
			node = node->next; // todo: del/free nodes
		else if (!(j = 0))
		{
			while (i < n && j < node->content_size)
				buf[i++] = ((t_car *)node->content)[j++];
			if (j < node->content_size)
				ft_memmove(node->content, node->content + j,
					(node->content_size -= j) * sizeof(t_car));
			else
				node->content_size = 0;
		}
	self->buf = node;
	return (i);
}
