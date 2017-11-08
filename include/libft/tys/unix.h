/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft/tys/unix.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/07 09:53:34 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TYS_UNIX_H
# define LIBFT_TYS_UNIX_H

# include "common.h"

# ifndef _MSC_VER

typedef ssize_t				t_isz;
typedef size_t				t_usz;
#  define ISIZE_MAX SSIZE_MAX
#  define USIZE_MAX SIZE_MAX
# endif

#endif
