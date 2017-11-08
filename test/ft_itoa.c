/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:44:14 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/08 11:50:20 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <libft.h>

int main(void)
{
	t_car *s;

	s = ft_itoa(456789);
	assert(ft_strequ("456789", s));
	free(s);
	s = ft_itoa(-456789);
	assert(ft_strequ("-456789", s));
	free(s);
	s = ft_itoa(0);
	assert(ft_strequ("0", s));
	free(s);
	s = ft_itoa(-0);
	assert(ft_strequ("0", s));
	free(s);
    return EXIT_SUCCESS;
}
