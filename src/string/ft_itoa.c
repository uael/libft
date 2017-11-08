/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/08 11:48:24 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_car	*ft_itoa(t_i32 n)
{
	t_car *s;
	t_car *ptr;
	t_i32 pow;
	t_i32 tmp;

	if (!(s = malloc(16 * sizeof(t_car))))
		return (NULL);
	ptr = s;
	pow = 1;
	tmp = n;
	while (tmp /= 10)
		pow *= 10;
	if (n < 0)
		*ptr++ = '-';
	while (pow)
	{
		*ptr++ = (t_car)((n < 0 ? n / -pow : n / pow) + '0');
		n %= pow;
		pow /= 10;
	}
	*ptr = '\0';
	return (s);
}
