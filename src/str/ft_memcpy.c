/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:44:17 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/07 09:44:26 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str.h"

inline void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	void *d;

	d = dst;
	while (n >= sizeof(uint64_t))
	{
		*((uint64_t *)dst)++ = *((uint64_t const *)src)++;
		n -= sizeof(uint64_t);
	}
	while (n >= sizeof(uint32_t))
	{
		*((uint32_t *)dst)++ = *((uint32_t const *)src)++;
		n -= sizeof(uint32_t);
	}
	while (n >= sizeof(uint16_t))
	{
		*((uint16_t *)dst)++ = *((uint16_t const *)src)++;
		n -= sizeof(uint16_t);
	}
	while (n)
	{
		*(uint8_t *) dst++ = *(uint8_t const *) src++;
		--n;
	}
	return (d);
}
