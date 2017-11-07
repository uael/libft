/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft/string.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/07 09:53:34 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRING_H
# define LIBFT_STRING_H

# include "tys.h"

t_i32	ft_atoi(t_cstr str);

t_str	ft_strcat(t_str dest, t_cstr src);
t_str	ft_strchr(t_cstr s, t_i32 c);
t_i32	ft_strcmp(t_cstr s1, t_cstr s2);
t_str	ft_strcpy(t_str dest, t_cstr src);
t_usz	ft_strlcat(t_str dest, t_str src, t_usz size);
t_usz	ft_strlen(t_str str);
t_str	ft_strncat(t_str dest, t_cstr src, t_usz nb);
t_i32	ft_strncmp(t_cstr s1, t_cstr s2, t_usz n);
t_str	ft_strncpy(t_str dest, t_cstr src, t_usz n);
t_usz	ft_strnlen(t_cstr str, t_usz size);
t_str	ft_strnstr(t_cstr str, t_cstr to_find, t_usz len);
t_str	ft_strrchr(t_cstr s, t_i32 c);
t_str	ft_strstr(t_cstr str, t_cstr to_find);

#endif
