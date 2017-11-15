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

char	*ft_itoa_base(int n, uint8_t base)
{
	uint8_t	i;
	char	*str;

	if (base > 30)
		return (NULL);
	i = ft_digits(n, base);
	if (!(str = malloc((i + 1 + (n < 0)) * sizeof(char))))
		return (NULL);
	i = ft_strnbr(str, n, base);
	str[i] = '\0';
	return (str);
}
