/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:53:16 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/07 09:53:34 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_car	*ft_strncpy(t_car *dest, t_car const *src, t_usz n)
{
	t_usz i;

	i = 0;
	while (i < n && src[i])
	{
		*(dest + i) = *(src + i);
		++i;
	}
	while (i < n)
		*(dest + i++) = '\0';
	return (dest);
}
