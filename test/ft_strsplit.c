/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:44:14 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/08 11:16:21 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int main(void)
{
	t_car **r;

	r = ft_strsplit("*hello*fellow***students*", '*');
	while (*r)
	{
		write(1, *r, ft_strlen(*r));
		write(1, "\n", 1);
		++r;
	}
    return EXIT_SUCCESS;
}
