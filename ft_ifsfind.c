/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifsgetln.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:53:28 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/07 09:53:34 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BUFF_SIZE (32)

ssize_t	ft_ifsfind(t_ifs *self, t_car *needles)
{
	ssize_t	r;
	t_usz	n;
	ssize_t	i;
	t_list	*node;

	n = 0;
	node = NULL;
	while ((r = ft_ifsbuf(self, BUFF_SIZE)))
		while ((node = node ? node->next : self->buf))
		{
			i = -1;
			while ((t_usz)++i < node->content_size)
			{
				++n;
				if (!((t_car *)node->content)[i] ||
					ft_strchr(needles, ((t_car *)node->content)[i]))
					return (n);
			}
		}
	return (r < 0 ? -1 : 0);
}
