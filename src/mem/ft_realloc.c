/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:44:14 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/15 18:36:39 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline void	*ft_realloc(void *ptr, size_t psz, size_t sz)
{
	void *p;

	if (!(p = malloc(sz)))
		return (NULL);
	if (!ptr)
		return (p);
	ft_memcpy(p, ptr, psz);
	free(ptr);
	return (p);
}
