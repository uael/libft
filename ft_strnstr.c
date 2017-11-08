/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:53:18 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/08 15:24:15 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_car	*ft_strnstr(t_car const *haystack, t_car const *needle, t_usz l)
{
	t_car const	*beg;
	t_car const	*ptr;
	t_usz		n;

	if (!*needle)
		return ((t_car *)haystack);
	while (l-- && *haystack)
	{
		if (*haystack == *needle)
		{
			beg = haystack + 1;
			ptr = needle + 1;
			n = l;
			while (n-- && *ptr == *beg && *ptr)
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
