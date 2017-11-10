/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifsgetln.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:53:28 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/07 09:53:34 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BUFF_SIZE (32)

ssize_t	ft_ifsgetln(t_ifs *self, t_car **buf)
{
	ssize_t	n;

	if ((n = ft_ifsfind(self, "\n")) <= 0)
		return (n);
	if (!(*buf = malloc((n + 1) * sizeof(t_car))))
		return (-1);
	n = ft_ifsread(self, *buf, (t_usz)n);
	if ((*buf)[n - 1] == '\n')
		(*buf)[n - 1] = '\0';
	return (n);
}
