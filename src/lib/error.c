/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib/error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:44:14 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/08 14:29:11 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>

int	ft_error(int rno, int eno)
{
	if (eno <= 0 || eno > EQFULL)
	{
		errno = EINVAL;
		return (-1);
	}
	errno = eno;
	return (rno);
}