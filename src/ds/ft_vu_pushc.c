/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vu_pushc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:33 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/07 09:53:34 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ds/vec.h"

inline uint8_t	*ft_vu8_pushc(t_vu8 *self, uint8_t item)
{
	uint8_t *it;

	if (!(it = ft_vu8_push(self)))
		return (NULL);
	*it = item;
	return (it);
}

inline uint16_t	*ft_vu16_pushc(t_vu16 *self, uint16_t item)
{
	uint16_t *it;

	if (!(it = ft_vu16_push(self)))
		return (NULL);
	*it = item;
	return (it);
}

inline uint32_t	*ft_vu32_pushc(t_vu32 *self, uint32_t item)
{
	uint32_t *it;

	if (!(it = ft_vu32_push(self)))
		return (NULL);
	*it = item;
	return (it);
}

inline uint64_t	*ft_vu64_pushc(t_vu64 *self, uint64_t item)
{
	uint64_t *it;

	if (!(it = ft_vu64_push(self)))
		return (NULL);
	*it = item;
	return (it);
}
