/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:57 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/09 11:54:02 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_car	*ft_strjoin(t_car const *s1, t_car const *s2)
{
	t_car *r;
	t_usz sz1;
	t_usz sz2;
	t_usz sz;

	sz1 = s1 ? ft_strlen(s1) : 0;
	sz2 = s2 ? ft_strlen(s2) : 0;
	sz = sz1 + sz2;
	if (!(r = malloc((sz + 1) * sizeof(t_car))))
		return (NULL);
	r[sz] = '\0';
	if (sz1)
		ft_strcpy(r, s1);
	if (sz2)
		ft_strcpy(r + sz1, s2);
	return (r);
}
