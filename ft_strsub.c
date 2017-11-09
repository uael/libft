/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:57 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/08 10:35:21 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_car	*ft_strsub(t_car const *s, t_u32 start, t_usz len)
{
	t_car *r;

	if (!s)
		return (NULL);
	if (!(r = malloc((len + 1) * sizeof(t_car))))
		return (NULL);
	r[len] = '\0';
	ft_strncpy(r, s + start, len);
	return (r);
}
