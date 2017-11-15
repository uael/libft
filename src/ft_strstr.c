/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:53:23 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/08 15:24:15 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_car	*ft_strstr(t_car const *haystack, t_car const *needle)
{
	t_car const *beg;
	t_car const *ptr;

	if (!*needle)
		return ((t_car *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			beg = haystack + 1;
			ptr = needle + 1;
			while (*ptr == *beg && *ptr)
			{
				++ptr;
				++beg;
			}
			if (!*ptr)
				return ((t_car *)haystack);
		}
		++haystack;
	}
	return (NULL);
}
