/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft/io.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/15 18:23:29 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_IO_H
# define LIBFT_IO_H

# include <unistd.h>
# include <fcntl.h>

extern void	ft_putchar(char c);
extern void	ft_putchar_fd(char c, int fd);
extern void	ft_putendl(char const *s);
extern void	ft_putendl_fd(char const *s, int fd);
extern void	ft_putnbr(int n);
extern void	ft_putnbr_fd(int n, int fd);
extern void	ft_putstr(char const *s);
extern void	ft_putstr_fd(char const *s, int fd);

#endif
