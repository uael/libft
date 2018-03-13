/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str/strncat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:44:14 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/08 14:29:11 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str.h"

inline char	*ft_strncat(char *dest, char const *src, size_t nb)
{
	char *ptr;

	ptr = dest;
	while (*ptr)
		++ptr;
	while (nb && (*ptr++ = *src++))
		--nb;
	if (nb <= 0)
		*ptr = '\0';
	return (dest);
}
