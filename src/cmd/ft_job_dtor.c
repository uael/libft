/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_job_dtor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:33 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/06 14:08:15 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/cmd.h"

inline void		ft_job_dtor(t_job *self)
{
	if (!self->av)
		return ;
	if (self->kind == JOB_EXE)
		free(self->av[0]);
	free(self->av);
	ft_vec_dtor(&self->dups, NULL);
}
