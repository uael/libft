/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/08 13:07:24 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_car	*ft_itoa_base(t_i32 n, t_u08 base)
{
	t_i32		i;
	t_i32		mod;
	t_car		*str;
	static char	digits[31] = "0123456789abcdefghijklmnopqrst";

	if (base > 30)
		return (NULL);
	i = ft_digits(n, base);
	mod = n < 0;
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
		*str-- = digits[(n % base) * (mod ? -1 : 1)];
		n /= base;
	}
	return (str + 1 - mod);
}
