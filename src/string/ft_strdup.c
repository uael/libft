/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:53:02 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/07 09:53:34 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_car	*ft_strdup(t_car *src)
{
	t_car	*dup;
	t_car	*sptr;
	t_car	*dptr;

	sptr = src;
	while (*sptr++)
		;
	if (!(dup = malloc(sptr - src + 1)))
		return (NULL);
	dptr = dup;
	while ((*dptr++ = *src++))
		;
	return (dup);
}
