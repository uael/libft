/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft/io.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/08 12:02:40 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_IO_H
# define LIBFT_IO_H

# include "tys.h"

extern void	ft_putchar		(t_car c);
extern void	ft_putchar_fd	(t_car c, t_i32 fd);
extern void	ft_putendl		(t_car const *s);
extern void	ft_putendl_fd	(t_car const *s, t_i32 fd);
extern void	ft_putnbr		(t_i32 n);
extern void	ft_putnbr_fd	(t_i32 n, t_i32 fd);
extern void	ft_putstr		(t_car const *s);
extern void	ft_putstr_fd	(t_car const *s, t_i32 fd);

#endif
