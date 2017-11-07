/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft/mem.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/07 09:53:34 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MEM_H
# define LIBFT_MEM_H

# include "tys.h"

void	ft_bzero(t_ptr ptr, t_usz n);

t_ptr	ft_memccpy(t_ptr dst, t_cptr src, t_i32 c, t_usz n);
t_ptr	ft_memchr(t_cptr s, t_i32 c, size_t n);
t_i32	ft_memcmp(t_cptr s1, t_cptr s2, t_usz n);
t_ptr	ft_memcpy(t_ptr dst, t_cptr src, t_usz n);
t_ptr	ft_memmove(t_ptr dst, t_cptr src, t_usz len);
t_ptr	ft_memset(t_ptr b, t_i32 c, t_usz len);

#endif
