/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft/math.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/15 18:54:24 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MATH_H
# define LIBFT_MATH_H

# include "types.h"

# ifndef MIN
#  define MIN(a, b) (((a)<(b))?(a):(b))
# endif

# ifndef MAX
#  define MAX(a, b) (((a)>(b))?(a):(b))
# endif

# ifndef ISPOW2
#  define ISPOW2(n) (((n) != 0) && (((n) & (~(n) + 1)) == (n)))
# endif

# define I8EQ(a, b) ((t_bool)((int8_t)(a) == (int8_t)(b)))
# define U8EQ(a, b) ((t_bool)((uint8_t)(a) == (uint8_t)(b)))
# define I16EQ(a, b) ((t_bool)((int16_t)(a) == (int16_t)(b)))
# define U16EQ(a, b) ((t_bool)((uint16_t)(a) == (uint16_t)(b)))
# define I32EQ(a, b) ((t_bool)((int32_t)(a) == (int32_t)(b)))
# define U32EQ(a, b) ((t_bool)((uint32_t)(a) == (uint32_t)(b)))
# define I64EQ(a, b) ((t_bool)((int64_t)(a) == (int64_t)(b)))
# define U64EQ(a, b) ((t_bool)((uint64_t)(a) == (uint64_t)(b)))
# define ISIZEEQ(a, b) ((t_bool)((ssize_t)(a) == (ssize_t)(b)))
# define USIZEEQ(a, b) ((t_bool)((size_t)(a) == (size_t)(b)))
# define F32EQ(a, b) ((t_bool)((float)(a) == (float)(b)))
# define F64EQ(a, b) ((t_bool)((double)(a) == (double)(b)))
# define STREQ(a, b) ((t_bool)(ft_strcmp(a, b) == 0))
# define ADDREQ(a, b) ((t_bool)(&(a) == &(b)))

# define I8CMP(a, b) ((int8_t)(((a) > (b)) - ((a) < (b))))
# define U8CMP(a, b) ((int8_t)(((a) > (b)) - ((a) < (b))))
# define I16CMP(a, b) ((int8_t)(((a) > (b)) - ((a) < (b))))
# define U16CMP(a, b) ((int8_t)(((a) > (b)) - ((a) < (b))))
# define I32CMP(a, b) ((int8_t)(((a) > (b)) - ((a) < (b))))
# define U32CMP(a, b) ((int8_t)(((a) > (b)) - ((a) < (b))))
# define I64CMP(a, b) ((int8_t)(((a) > (b)) - ((a) < (b))))
# define U64CMP(a, b) ((int8_t)(((a) > (b)) - ((a) < (b))))
# define ISIZECMP(a, b) ((int8_t)(((a) > (b)) - ((a) < (b))))
# define USIZECMP(a, b) ((int8_t)(((a) > (b)) - ((a) < (b))))
# define F32CMP(a, b) ((int8_t)(((a) > (b)) - ((a) < (b))))
# define F64CMP(a, b) ((int8_t)(((a) > (b)) - ((a) < (b))))
# define ADDRCMP(a, b) ((int8_t)((&(a) > &(b)) - (&(a) < &(b))))

extern uint8_t	pow2_next8(uint8_t n);
extern uint16_t	pow2_next16(uint16_t n);
extern uint32_t	pow2_next32(uint32_t n);
extern uint64_t	pow2_next64(uint64_t n);
extern size_t	pow2_next(size_t n);

#endif
