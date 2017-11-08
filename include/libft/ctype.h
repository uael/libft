/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft/ctype.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/08 10:44:53 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_CTYPE_H
# define LIBFT_CTYPE_H

# include "tys.h"

extern t_i32	ft_isalnum	(t_i32 c);
extern t_i32	ft_isascii	(t_i32 c);
extern t_i32	ft_isalpha	(t_i32 c);
extern t_i32	ft_isdigit	(t_i32 c);
extern t_i32	ft_islower	(t_i32 c);
extern t_i32	ft_isprint	(t_i32 c);
extern t_i32	ft_isupper	(t_i32 c);
extern t_i32	ft_isspace	(t_i32 c);

extern t_i32	ft_tolower	(t_i32 c);
extern t_i32	ft_toupper	(t_i32 c);

#endif
