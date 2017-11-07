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

inline t_str	ft_strdup(t_str src)
{
	t_str	dup;
	t_str	sptr;
	t_str	dptr;

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
