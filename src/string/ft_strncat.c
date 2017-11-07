/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:53:10 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/07 09:53:34 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_str	ft_strncat(t_str dest, t_cstr src, t_usz nb)
{
	t_str ptr;

	ptr = dest;
	while (*ptr)
		++ptr;
	while (nb-- && (*ptr++ = *src++))
		;
	if (nb <= 0)
		*ptr = '\0';
	return (dest);
}
