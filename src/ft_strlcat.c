/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:53:05 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/07 09:53:34 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_usz	ft_strlcat(t_str dest, t_str src, t_usz size)
{
	t_usz	slen;
	t_usz	dlen;

	slen = (t_usz)ft_strlen(src);
	dlen = (t_usz)ft_strnlen(dest, size);
	if (dlen == size)
		return (size + slen);
	if (slen < size - dlen)
		ft_strncpy(dest + dlen, src, slen + 1);
	else
	{
		ft_strncpy(dest + dlen, src, size - dlen - 1);
		dest[size - 1] = '\0';
	}
	return (dlen + slen);
}

