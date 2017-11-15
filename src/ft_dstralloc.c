/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstralloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:53:10 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/08 13:31:11 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_u08	ft_dstralloc(t_dstr *self, t_usz n)
{
	void	*buf;

	if (self->cap == n)
		return (0);
	if (!(buf = ft_memrealloc(self->buf, self->cap, n)))
		return (1);
	self->buf = buf;
	if (self->len > (self->cap = n))
		self->len = n;
	return (0);
}
