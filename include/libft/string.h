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

extern t_i32	ft_atoi		(t_car const *str);

extern t_car	*ft_strcat	(t_car *dest, t_car const *src);
extern t_car	*ft_strchr	(t_car const *s, t_i32 c);
extern t_i32	ft_strcmp	(t_car const *s1, t_car const *s2);
extern t_car	*ft_strcpy	(t_car *dest, t_car const *src);
extern t_usz	ft_strlcat	(t_car *dest, t_car *src, t_usz size);
extern t_usz	ft_strlen	(t_car *str);
extern t_car	*ft_strncat	(t_car *dest, t_car const *src, t_usz nb);
extern t_i32	ft_strncmp	(t_car const *s1, t_car const *s2, t_usz n);
extern t_car	*ft_strncpy	(t_car *dest, t_car const *src, t_usz n);
extern t_usz	ft_strnlen	(t_car const *str, t_usz size);
extern t_car	*ft_strnstr	(t_car const *str, t_car const *to_find, t_usz len);
extern t_car	*ft_strrchr	(t_car const *s, t_i32 c);
extern t_car	*ft_strstr	(t_car const *str, t_car const *to_find);

#endif
