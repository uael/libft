/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:57 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/08 11:23:03 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_car	**ft_strsplit(t_car const *s, t_car c)
{
	t_usz nw;
	t_car **r;
	t_car **ptr;

	nw = ft_strword(s, c);
	if (!(r = malloc((nw + 1) * sizeof(t_car *))))
		return (NULL);
	ptr = r;
	while (*s)
		if (*s == c)
			++s;
		else
		{
			nw = ft_strchr(s, (t_i32)c) - s;
			if (!(*ptr = malloc((nw + 1) * sizeof(t_car))))
			{
				while (r != ptr)
					free(*r++);
				free(r);
				return (NULL);
			}
			ft_strncpy(*ptr++, s, nw)[nw] = '\0';
			s += nw;
		}
	*ptr = NULL;
	return (r);
}
