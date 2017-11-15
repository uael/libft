/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstrpushn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:53:10 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/08 13:31:11 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_car	*ft_dstrpushn(t_dstr *self, t_usz n)
{
	t_car *it;

	if (n == 0 || ft_dstrgrow(self, n))
		return (NULL);
	it = ft_dstrend(self);
	self->len += n;
	it[n] = '\0';
	return (it);
}
