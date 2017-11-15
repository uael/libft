/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:33 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/08 12:03:40 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline void	ft_putnbr_fd(int n, int fd)
{
	int pow;
	int mod;
	int tmp;

	pow = 1;
	tmp = n;
	while (tmp /= 10)
		pow *= 10;
	mod = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		mod = -1;
	}
	while (pow)
	{
		ft_putchar_fd((char)(n / pow * mod + '0'), fd);
		n %= pow;
		pow /= 10;
	}
}
