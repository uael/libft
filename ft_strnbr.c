/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:53:08 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/07 09:53:34 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_u08	ft_strnbr(t_car *dst, t_i64 n, t_u08 base)
{
	t_u08		i;
	t_u08		mod;
	static char	digits[31] = "0123456789abcdefghijklmnopqrst";

	if (base > 30)
		return (NULL);
	i = ft_digits(n, base);
	mod = (t_u08)(n < 0);
	if (mod)
		*dst++ = '-';
	dst += i - 1;
	if (n == 0)
		*dst-- = '0';
	while (n)
	{
		*dst-- = digits[(n % base) * (mod ? -1 : 1)];
		n /= base;
	}
	return (i + mod);
}
