/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:44:17 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/09 12:20:15 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str.h"

inline void	*ft_memrcpy(void *dst, void const *src, size_t n)
{
	while (n >= sizeof(uint64_t))
	{
		n -= sizeof(uint64_t);
		*((uint64_t *)dst + n) = *((uint64_t const *)src + n);
	}
	while (n >= sizeof(uint32_t))
	{
		n -= sizeof(uint32_t);
		*((uint32_t *)dst + n) = *((uint32_t const *)src + n);
	}
	while (n >= sizeof(uint16_t))
	{
		n -= sizeof(uint16_t);
		*((uint16_t *)dst + n) = *((uint16_t const *)src + n);
	}
	while (n)
	{
		--n;
		*((uint8_t *)dst + n) = *((uint8_t const *)src + n);
	}
	return (dst);
}
