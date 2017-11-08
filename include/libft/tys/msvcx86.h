/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft/tys/msvcx86.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/07 09:53:34 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TYS_MSVCX86_H
# define LIBFT_TYS_MSVCX86_H

# include "common.h"

# ifdef _MSC_VER
#  ifdef WIN32

typedef t_i32				t_isz;
typedef size_t				t_usz;
#   define ISZ_MAX I32_MAX
#   define USZ_MAX SIZE_MAX
#  endif
# endif

#endif
