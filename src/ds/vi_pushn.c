/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_pushn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:33 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/07 09:53:34 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ds/vec.h"

inline int8_t	*ft_vi8_pushn(t_vi8 *self, size_t n)
{
	if (!n || !ft_vi8_grow(self, n))
		return (NULL);
	self->len += n;
	return (ft_vi8_end(self));
}

inline int16_t	*ft_vi16_pushn(t_vi16 *self, size_t n)
{
	if (!n || !ft_vi16_grow(self, n))
		return (NULL);
	self->len += n;
	return (ft_vi16_end(self));
}

inline int32_t	*ft_vi32_pushn(t_vi32 *self, size_t n)
{
	if (!n || !ft_vi32_grow(self, n))
		return (NULL);
	self->len += n;
	return (ft_vi32_end(self));
}

inline int64_t	*ft_vi64_pushn(t_vi64 *self, size_t n)
{
	if (!n || !ft_vi64_grow(self, n))
		return (NULL);
	self->len += n;
	return (ft_vi64_end(self));
}
