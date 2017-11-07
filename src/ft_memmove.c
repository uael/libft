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


t_ptr	ft_memmove(t_ptr dst, t_cptr src, t_usz len)
{
	t_u08		*d;
	t_u08 const	*s;
	t_usz		n;
	t_u08		t[len];

	d = (t_u08 *)dst;
	s = (t_u08 const *)src;
	n = 0;
	while (n < len)
		t[n++] = *s++;
	n = 0;
	while (n < len)
		*d++ = t[n++];
	return (dst);
}
