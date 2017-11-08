/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft/tys/msvcx64.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/07 09:53:34 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TYS_MSVCX64_H
# define LIBFT_TYS_MSVCX64_H

# include "common.h"

# ifdef _MSC_VER
#  ifndef WIN32

typedef t_i64				t_isz;
typedef size_t				t_usz;
#   define ISZ_MAX I64_MAX
#   define USZ_MAX SIZE_MAX
#  endif
# endif

#endif
