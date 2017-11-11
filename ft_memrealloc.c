/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:44:14 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/07 09:44:26 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline void	*ft_memrealloc(void *ptr, t_usz psz, t_usz sz)
{
	void *p;

	if (!(p = malloc(sz)))
		return (NULL);
	if (!ptr)
		return (p);
	ft_memcpy(p, ptr, psz);
	ft_memdel(&ptr);
	return (p);
}
