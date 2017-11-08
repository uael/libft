/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:33 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/08 12:39:37 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_list	*ft_lstnew(void const *content, t_usz content_size)
{
	t_list *lst;

	if (!(lst = malloc(sizeof(t_list))))
		return (NULL);
	if (!(lst->content = malloc(content_size)))
	{
		free(lst);
		return (NULL);
	}
	ft_memcpy(lst->content, content, content_size);
	lst->content_size = content ? content_size : 0;
	lst->next = NULL;
	return (lst);
}

