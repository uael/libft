/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_ctor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:33 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/07 09:53:34 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline void	ft_vi8_ctor(t_vi8 *self)
{
	FT_INIT(self, t_vi8);
}

inline void	ft_vi16_ctor(t_vi16 *self)
{
	FT_INIT(self, t_vi16);
}

inline void	ft_vi32_ctor(t_vi32 *self)
{
	FT_INIT(self, t_vi16);
}

inline void	ft_vi64_ctor(t_vi64 *self)
{
	FT_INIT(self, t_vi64);
}
