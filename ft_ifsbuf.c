/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifsbuf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:53:28 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/07 09:53:34 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BUFF_SIZE (4096)
#define STATE_RUN (-2)
#define STATE_ERR (-1)

ssize_t	ft_ifsbuf(t_ifs *self, t_usz n)
{
	t_car	buf[BUFF_SIZE];
	ssize_t	state;
	t_usz	ret;
	t_list	*node;
	t_list	**tail;

	state = STATE_RUN;
	ret = 0;
	node = self->buf;
	while ((state > 0 || state == STATE_RUN) && ret < n)
		if (state < 0 && (!node || (ret += node->content_size) < n))
			state = read(self->fd, buf, BUFF_SIZE);
		else if (state > 0)
		{
			tail = node ? &node->next : &self->buf;
			if (!(*tail = ft_lstnew(buf, (t_usz) state)))
				return (STATE_ERR);
			node = *tail;
			state = STATE_RUN;
		}
	if (state == STATE_ERR)
		return (state);
	return ((ssize_t) (ret > n ? n : ret));
}
