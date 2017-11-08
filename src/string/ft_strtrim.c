/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:57 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/08 10:51:20 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_car	*ft_strtrim(t_car const *s)
{
	t_usz sz;
	t_car *r;

	while (ft_isspace(*s))
		++s;
	if (!(sz = ft_strlen(s)))
		return (ft_strnew(0));
	while (ft_isspace(*(s + sz - 1)))
		--sz;
	if (!(r = malloc((sz + 1) * sizeof(t_car))))
		return (NULL);
	ft_strncpy(r, s, sz);
	r[sz] = '\0';
	return r;
}
