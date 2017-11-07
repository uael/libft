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
t_i32						ft_islower(t_i32 c);
t_i32						ft_isprint(t_i32 c);
t_i32						ft_isupper(t_i32 c);
t_ptr						ft_memccpy(t_ptr dst, t_cptr src, t_i32 c, t_usz n);
t_ptr						ft_memchr(t_cptr s, t_i32 c, size_t n);
t_i32						ft_memcmp(t_cptr s1, t_cptr s2, t_usz n);
t_ptr						ft_memcpy(t_ptr dst, t_cptr src, t_usz n);
t_ptr						ft_memmove(t_ptr dst, t_cptr src, t_usz len);
t_ptr						ft_memset(t_ptr b, t_i32 c, t_usz len);
t_str						ft_strcat(t_str dest, t_cstr src);
t_str						ft_strchr(t_cstr s, t_i32 c);
t_i32						ft_strcmp(t_cstr s1, t_cstr s2);
t_str						ft_strcpy(t_str dest, t_cstr src);
t_usz						ft_strlcat(t_str dest, t_str src, t_usz size);
t_usz						ft_strlen(t_str str);
t_str						ft_strncat(t_str dest, t_cstr src, t_usz nb);
t_i32						ft_strncmp(t_cstr s1, t_cstr s2, t_usz n);
t_str						ft_strncpy(t_str dest, t_cstr src, t_usz n);
t_usz						ft_strnlen(t_cstr str, t_usz size);
t_str						ft_strnstr(t_cstr str, t_cstr to_find, t_usz len);
t_str						ft_strrchr(t_cstr s, t_i32 c);
t_str						ft_strstr(t_cstr str, t_cstr to_find);
t_i32						ft_tolower(t_i32 c);
t_i32						ft_toupper(t_i32 c);

#endif
