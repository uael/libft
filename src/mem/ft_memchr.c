/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:48 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/07 09:53:34 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_ptr	ft_memchr(t_cptr ptr, t_i32 c, size_t n)
{
	t_u08 const *s;

	s = (t_u08 const *)ptr;
	while (n--)
		if (*s++ == (t_u08)c)
			return (t_ptr)s;
	return (NULL);
}
