/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:33 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/08 12:42:36 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *))
{
	t_list	*beg;
	t_list	*cur;

	if (!lst || !f)
		return (NULL);
	beg = NULL;
	cur = NULL;
	while (lst)
	{
		if (beg)
		{
			cur->next = (*f)(lst);
			cur = cur->next;
		}
		else
		{
			beg = (*f)(lst);
			cur = beg;
		}
		lst = lst->next;
	}
	return (beg);
}
