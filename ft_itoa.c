/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/08 13:07:24 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_car	*ft_itoa(t_i32 n)
{
	t_i32	tmp;
	t_i32	i;
	t_i32	mod;
	t_car	*str;

	tmp = n;
	i = 1;
	mod = n < 0;
	while (tmp /= 10)
		i++;
	if (!(str = malloc((i + 1 + mod) * sizeof(t_car))))
		return (NULL);
	if (mod)
		*str++ = '-';
	str += i - 1;
	*(str + 1) = '\0';
	if (n == 0)
		*str-- = '0';
	while (n)
	{
		*str-- = (t_car)((n % 10) * (mod ? -1 : 1) + '0');
		n /= 10;
	}
	return (str + 1 - mod);
}
