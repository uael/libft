/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <null>                             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:27:43 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/07 09:27:52 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef void				*t_ptr;
typedef char				t_car, *t_str;
typedef const void			*t_cptr;
typedef const char			*t_cstr;
typedef size_t				t_usz;
typedef ssize_t				t_isz;

typedef unsigned char		t_u08;
typedef unsigned short		t_u16;
typedef unsigned int		t_u32;
typedef unsigned long long	t_u64;

typedef signed char			t_i08;
typedef signed short		t_i16;
typedef signed int			t_i32;
typedef signed long long	t_i64;

typedef float				t_f32;
typedef double				t_f64;

t_i32						ft_atoi(t_cstr str);
void						ft_bzero(t_ptr ptr, t_usz n);
t_i32						ft_isalnum(t_i32 c);
t_i32						ft_isascii(t_i32 c);
t_i32						ft_isalpha(t_i32 c);
t_i32						ft_isdigit(t_i32 c);
t_i32						ft_isprint(t_i32 c);
t_ptr						ft_memccpy(t_ptr dst, t_cptr src, t_i32 c, t_usz n);
t_ptr						ft_memchr(t_cptr s, t_i32 c, size_t n);
t_i32						ft_memcmp(t_cptr s1, t_cptr s2, t_usz n);
t_ptr						ft_memcpy(t_ptr dst, t_cptr src, t_usz n);
t_ptr						ft_memmove(t_ptr dst, t_cptr src, t_usz len);
t_ptr						ft_memset(t_ptr b, t_i32 c, t_usz len);

#endif
