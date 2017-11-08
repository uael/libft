/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:44:20 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/07 09:44:26 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline void	*ft_memmove(void *dst, void const *src, t_usz len)
{
	t_u08		*d;
	t_u08 const	*s;

	d = (t_u08 *)dst;
	s = (t_u08 const *)src;
	if (s < d)
	{
		s += len;
		d += len;
		while (--len)
			*--d = *--s;
	}
	else if (s != d)
		while (--len)
			*++d = *++s;
	return (dst);
}
