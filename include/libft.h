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

#include <string.h>

typedef char				t_car,
							*t_str;
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

t_i32						ft_atoi(const t_car *str);

#endif
