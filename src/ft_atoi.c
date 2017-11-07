/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/07 09:53:34 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_i32	ft_atoi(t_cstr str)
{
    t_i32	result;
    t_car	sign;

    result = 0;
    if ((sign = *str) == '+' || sign == '-')
        ++str;
    while (*str >= '0' && *str <= '9')
        result = result * 10 + *str++ - '0';
    return (sign == '-' ? -result : result);
}
