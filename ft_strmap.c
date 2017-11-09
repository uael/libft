/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:57 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/08 10:01:32 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_car	*ft_strmap(t_car const *s, t_car (*f)(t_car))
{
	t_usz sz;
	t_car *str;
	t_car *ptr;

	if (!s || !f)
		return (NULL);
	if (!(sz = ft_strlen(s)))
		return (NULL);
	if (!(str = ft_strnew(sz)))
		return (NULL);
	ptr = str;
	while (*s)
		*ptr++ = f(*s++);
	return (str);
}
