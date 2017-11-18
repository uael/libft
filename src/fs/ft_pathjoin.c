/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:33 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/18 10:04:26 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/fs.h"

inline char	*ft_pathjoin(char const *p1, char const *p2)
{
	size_t	l1;
	size_t	l2;
	t_bool	ds;
	char	*r;

	l1 = ft_strlen(p1);
	if (!(l2 = ft_strlen(p2)) && !l1)
		return (NULL);
	ds = (t_bool)((!l1 || p1[l1 - 1] != '/') && (!l2 || p2[0] != '/'));
	if (!(r = malloc((l1 + l2 + ds + 1) * sizeof(char))))
		return (NULL);
	if (l1)
		ft_strcpy(r, p1);
	if (ds)
		ft_strcpy(r + l1, "/");
	if (l2)
		ft_strcpy(r + l1 + ds, p2);
	return (r);
}
