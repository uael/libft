/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@strudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:08:01 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/08 12:31:08 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_LIST_H
# define LIBFT_LIST_H

# include "tys.h"

typedef struct s_list	t_list;

struct	s_list
{
	void	*content;
	t_usz	content_size;
	t_list	*next;
};

extern void				ft_lstadd(t_list **lst, t_list *new);
extern void				ft_lstdel(t_list **alst, void (*del)(void *, t_usz));
extern void				ft_lstdelone(t_list **alst, void (*del)(void *, t_usz));
extern void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
extern t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
extern t_list			*ft_lstnew(void const *content, t_usz content_size);

#endif
