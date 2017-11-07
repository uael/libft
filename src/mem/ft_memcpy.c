/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:44:17 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/07 09:44:26 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_ptr	ft_memcpy(t_ptr dst, t_cptr src, t_usz n)
{
	t_u08		*d;
	t_u08 const	*s;

	d = (t_u08 *)dst;
	s = (t_u08 const *)src;
	while (n--)
		*d++ = *s++;
	return (dst);
}
