/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ofstream.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:33 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/17 09:51:01 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io/ofstream.h"

inline int	ft_ofstream_open(t_ofstream *self, char const *filename)
{
	FT_INIT(self, t_ofstream);
	if ((self->fd = open(filename, O_APPEND | O_CREAT | O_RDWR,
		S_IRUSR | S_IWUSR)) < 0)
		return (THROW(WUT));
	self->filename = filename;
	return (YEP);
}

inline int	ft_ofstream_close(t_ofstream *self)
{
	if (self->filename && self->fd > 1)
	{
		ft_ofstream_flush(self);
		if (close(self->fd) < 0)
			return (THROW(WUT));
		if (self->buf)
		{
			free(self->buf);
			self->buf = NULL;
		}
		self->filename = NULL;
	}
	return (YEP);
}
