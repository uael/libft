/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:44:20 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/08 14:46:54 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline void	*ft_memmove(void *dst, void const *src, t_usz len)
{
	t_u08 buf[len];

	ft_memcpy(buf, src, len);
	ft_memcpy(dst, buf, len);
	return (dst);
}
