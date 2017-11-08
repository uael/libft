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

void	ft_bzero	(void *ptr, t_usz n);

void	*ft_memccpy	(void *dst, void const *src, t_i32 c, t_usz n);
void	*ft_memchr	(void const *s, t_i32 c, size_t n);
t_i32	ft_memcmp	(void const *s1, void const *s2, t_usz n);
void	*ft_memcpy	(void *dst, void const *src, t_usz n);
void	*ft_memmove	(void *dst, void const *src, t_usz len);
void	*ft_memset	(void *b, t_i32 c, t_usz len);

#endif
