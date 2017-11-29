/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft/ds/lst.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/15 18:23:29 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_DS_LST_H
# define LIBFT_DS_LST_H

# include "../str.h"
# include "../math.h"

void	clean(void *ptr)
{
	ft_pfree((void **)ptr);
}

#define SMART(type)  __attribute__ ((__cleanup__(clean))) type

typedef struct	s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	void			*val;
}				t_node;

t_node	*ft_node_ctor(t_node *self)
{
	FT_INIT(self, t_node);
	self->next = self;
	self->prev = self;
	return (self);
}

t_node	*ft_node_new(void *val)
{
	SMART(t_node) *node;

	if (!(node = malloc(sizeof(t_node))))
		return (NULL);
	ft_node_ctor(node);
	node->val = val;
	return (node);
}

t_node	*ft_node_link(t_node *self, t_node *prev, t_node *next)
{
	self->next = prev->next;
	self->prev = next->prev;
	prev->next = self;
	next->prev = self;
	return (self);
}

t_node	*ft_node_unlink(t_node *self, t_node *prev, t_node *next)
{
	next->prev = prev;
	prev->next = next;
	self->prev = self;
	self->next = self;
	return (self);
}

t_node	*ft_node_push(t_node *self, void *val)
{
	t_node *new;

	if (!(new = ft_node_new(val)))
		return (NULL);
	return (ft_node_link(new, self, self->next));
}

t_node	*ft_node_unshift(t_node *self, void *val)
{
	t_node *new;

	if (!(new = ft_node_new(val)))
		return (NULL);
	return (ft_node_link(new, self->prev, self));
}

typedef struct	s_lst
{
	t_node	*prev;
	t_node	*next;
	size_t	size;
}				t_lst;

t_lst	*ft_lst_ctor(t_lst *self)
{
	return ((t_lst *)ft_node_ctor((t_node *)self));
}

t_node	*ft_lst_front(t_lst *self)
{
	return self->next;
}

t_node	*ft_lst_back(t_lst *self)
{
	return self->prev;
}

t_lst	*ft_lst_push(t_lst *self, void *val)
{
	if (!ft_node_unshift((t_node *)self, val))
		return (NULL);
	++self->size;
	return (self);
}

#endif
