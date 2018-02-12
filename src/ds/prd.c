/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:33 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/07 09:53:34 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ds.h"

inline char	*ft_sdsprd(t_sds *self, char const *items)
{
	return (ft_sdsmusht(self, items, ft_strlen(items)));
}
