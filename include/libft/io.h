/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft/io.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/17 10:01:44 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_IO_H
# define LIBFT_IO_H

# include <unistd.h>
# include <fcntl.h>

# include "int.h"
# include "str.h"

extern ssize_t	ft_putc(int fd, char c);
extern ssize_t	ft_putl(int fd, char const *s);
extern ssize_t	ft_putn(int fd, int64_t n, uint8_t base);
extern ssize_t	ft_putu(int fd, uint64_t n, uint8_t base);
extern ssize_t	ft_puts(int fd, char const *s);

#endif
