/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:44:20 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/07 09:44:26 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>

int main(void) {
    char str[] = "memmove can be very useful......";
    char str2[] = "memmove can be very useful......";
	write(1, str+15, 11);
	write(1, "\n", 1);
    ft_memcpy(str+20,str+15,11);
    ft_memmove(str2+20,str2+15,11);
	write(1, str, strlen(str));
	write(1, "\n", 1);
	write(1, str2, strlen(str2));
	write(1, "\n", 1);
    return EXIT_SUCCESS;
}
