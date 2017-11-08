/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft/tys/common.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/07 09:53:34 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TYS_COMMON_H
# define LIBFT_TYS_COMMON_H

# include <stdlib.h>
# include <string.h>
# ifdef _MSC_VER
#  include <io.h>
# else
#  include <unistd.h>
# endif

# ifdef NULL
#  define NIL NULL
# else
#  define NIL ((void *) 0)
# endif

typedef char				t_car;

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

#endif
