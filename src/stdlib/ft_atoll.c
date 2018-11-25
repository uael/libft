/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string/ft_atoll.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/ctype.h"
#include "ft/stdlib.h"

inline long long	ft_atoll(const char *s)
{
	long long	n;
	int			c;

	n = 0;
	while (ft_isspace(*s))
		s++;
	if (*s == '-' || *s == '+')
		c = (*s++ == '-');
	while (ft_isdigit(*s))
		n = 10 * n - (*s++ - '0');
	return (c ? -n : n);
}
