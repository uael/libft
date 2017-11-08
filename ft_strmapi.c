/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:57 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/08 14:14:33 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_car	*ft_strmapi(t_car const *s, t_car (*f)(t_u32 i, t_car c))
{
	t_usz	sz;
	t_car	*str;
	t_car	*ptr;

	if (!(sz = ft_strlen(s)))
		return (NULL);
	if (!(str = ft_strnew(sz)))
		return (NULL);
	ptr = str;
	sz = 0;
	while (*s)
		*ptr++ = f((t_u32)sz++, *s++);
	return (str);
}
