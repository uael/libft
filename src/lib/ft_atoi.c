/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/15 18:30:38 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline int	ft_atoi(char const *str)
{
	int64_t	result;
	char	sign;

	result = 0;
	while (ft_isspace(*str))
		++str;
	if ((sign = *str) == '+' || sign == '-')
		++str;
	while (ft_isdigit(*str))
		result = result * 10 + *str++ - '0';
	return ((int)(sign == '-' ? -result : result));
}
