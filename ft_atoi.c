/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/08 15:42:28 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_i32	ft_atoi(t_car const *str)
{
	t_i64	result;
	t_car	sign;

	result = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		++str;
	if ((sign = *str) == '+' || sign == '-')
		++str;
	while (ft_isdigit(*str))
		result = result * 10 + *str++ - '0';
	return ((t_i32)(sign == '-' ? -result : result));
}
