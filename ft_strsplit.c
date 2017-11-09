/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:57 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/09 11:59:27 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_car	**ft_strsplit(t_car const *s, t_car c)
{
	t_usz		nw;
	t_car const	*chr;
	t_car		**r;
	t_car		**ptr;

	nw = ft_strword(s, c);
	if (!(r = malloc((nw + 1) * sizeof(t_car *))))
		return (NULL);
	ptr = r;
	while (s && *s)
		if (*s == c)
			++s;
		else
		{
			chr = s;
			while (*chr && *chr != c)
				++chr;
			nw = chr - s;
			if (!(*ptr = malloc((nw + 1) * sizeof(t_car))))
				return (NULL);
			ft_strncpy(*ptr++, s, nw)[nw] = '\0';
			s += nw;
		}
	*ptr = NULL;
	return (r);
}
