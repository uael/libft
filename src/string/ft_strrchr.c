/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:53:21 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/07 09:53:34 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_car	*ft_strrchr(t_car const *s, t_i32 c)
{
	t_car *beg;

	beg = (t_car *)s;
	while (*s)
		++s;
	if (c == 0)
		return ((t_car *)s);
	while (s >= beg)
		if (*s-- == c)
			return ((t_car *)s + 1);
	return (NULL);
}
