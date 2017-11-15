/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strword.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:57 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/08 11:07:01 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_usz	ft_strword(t_car const *s, t_car c)
{
	t_usz n;

	n = 0;
	if (!s)
		return (n);
	while (*s)
		if (*s == c)
			++s;
		else if (++n && *++s)
			while (*s != c)
				++s;
	return (n);
}
