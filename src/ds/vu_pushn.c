/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vu_pushn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:33 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/07 09:53:34 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ds/vec.h"

inline uint8_t	*ft_vu8_pushn(t_vu8 *self, size_t n)
{
	if (!n || !ft_vu8_grow(self, n))
		return (NULL);
	self->len += n;
	return (ft_vu8_end(self));
}

inline uint16_t	*ft_vu16_pushn(t_vu16 *self, size_t n)
{
	if (!n || !ft_vu16_grow(self, n))
		return (NULL);
	self->len += n;
	return (ft_vu16_end(self));
}

inline uint32_t	*ft_vu32_pushn(t_vu32 *self, size_t n)
{
	if (!n || !ft_vu32_grow(self, n))
		return (NULL);
	self->len += n;
	return (ft_vu32_end(self));
}

inline uint64_t	*ft_vu64_pushn(t_vu64 *self, size_t n)
{
	if (!n || !ft_vu64_grow(self, n))
		return (NULL);
	self->len += n;
	return (ft_vu64_end(self));
}
