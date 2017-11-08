/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:50 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/07 09:53:34 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_i32	ft_memcmp(void const *s1, void const *s2, t_usz n)
{
	t_u08 const	*a;
	t_u08 const	*b;

	a = (t_u08 const *)s1;
	b = (t_u08 const *)s2;
	while (n && *a == *b)
	{
		++a;
		++b;
		--n;
	}
	return (n == 0 ? 0 : *a - *b);
}
