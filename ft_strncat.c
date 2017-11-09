/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:53:10 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/09 12:23:51 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_car	*ft_strncat(t_car *dest, t_car const *src, t_usz nb)
{
	t_car *ptr;

	ptr = dest;
	while (*ptr)
		++ptr;
	while (nb && (*ptr++ = *src++))
		--nb;
	if (nb <= 0)
		*ptr = '\0';
	return (dest);
}
