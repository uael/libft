/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:53:23 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/07 09:53:34 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_str	ft_strstr(t_cstr str, t_cstr to_find)
{
	t_str begin;
	t_str to_find_cp;

	if (*to_find == '\0')
		return ((t_str)str);
	while (*str)
	{
		begin = (t_str)str;
		to_find_cp = (t_str)to_find;
		while (*to_find_cp == *str)
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
