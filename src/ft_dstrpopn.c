/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstrpopn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:53:10 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/08 13:31:11 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_usz	ft_dstrpopn(t_dstr *self, t_usz n, t_car *out)
{
	t_car *it;

	if (self->len == 0)
		return (0);
	if (n > self->len)
		n = self->len;
	it = ft_dstrend(self);
	if (out)
		ft_memcpy(out, it, n * sizeof(t_car));
	*it = '\0';
	return (n);
}
