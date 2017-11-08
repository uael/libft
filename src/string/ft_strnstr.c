/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:53:18 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/07 09:53:34 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_car	*ft_strnstr(t_car const *str, t_car const *to_find, t_usz len)
{
	t_car *begin;
	t_car *to_find_cp;
	t_usz n;

	if (*to_find == '\0')
		return ((t_car *)str);
	while (len-- && *str)
	{
		begin = (t_car *)str;
		to_find_cp = (t_car *)to_find;
		n = len;
		while (n-- && *to_find_cp == *str)
		{
			++str;
			++to_find_cp;
		}
		if (*to_find_cp == '\0')
			return (begin);
		str = begin + 1;
	}
	return (NULL);
}
