/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft/string.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/08 10:55:12 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRING_H
# define LIBFT_STRING_H

# include "tys.h"

extern t_i32	ft_atoi		(t_car const *str);

extern t_car	*ft_strcat	(t_car *dest, t_car const *src);
extern t_car	*ft_strchr	(t_car const *s, t_i32 c);
extern t_i32	ft_strcmp	(t_car const *s1, t_car const *s2);
extern void		ft_strclr	(t_car *s);
extern t_car	*ft_strcpy	(t_car *dest, t_car const *src);
extern void		ft_strdel	(t_car **s);
extern t_car	*ft_strdup	(t_car *src);
extern t_i32	ft_strequ	(t_car const *s1, t_car const *s2);
extern void		ft_striter	(t_car *s, void (*f)(t_car *));
extern void 	ft_striteri	(t_car *s, void (*f)(t_u32, t_car *));
extern t_car	*ft_strjoin	(t_car const *s1, t_car const *s2);
extern t_usz	ft_strlcat	(t_car *dest, t_car *src, t_usz size);
extern t_usz	ft_strlen	(t_car const *str);
extern t_car	*ft_strmap	(t_car const *s, t_car (*f)(t_car));
extern t_car	*ft_strmapi	(t_car const *s, t_car (*f)(t_u32, t_car));
extern t_car	*ft_strncat	(t_car *dest, t_car const *src, t_usz nb);
extern t_i32	ft_strncmp	(t_car const *s1, t_car const *s2, t_usz n);
extern t_car	*ft_strncpy	(t_car *dest, t_car const *src, t_usz n);
extern t_i32	ft_strnequ	(t_car const *s1, t_car const *s2, t_usz n);
extern t_car	*ft_strnew	(size_t sz);
extern t_usz	ft_strnlen	(t_car const *str, t_usz size);
extern t_car	*ft_strnstr	(t_car const *str, t_car const *to_find, t_usz len);
extern t_car	*ft_strrchr	(t_car const *s, t_i32 c);
extern t_car	**ft_strsplit(t_car const *s, t_car c);
extern t_car	*ft_strstr	(t_car const *str, t_car const *to_find);
extern t_car	*ft_strsub	(t_car const *s, t_u32 start, t_usz len);
extern t_car	*ft_strtrim	(t_car const *s);
extern t_usz	ft_strword	(t_car const *s, t_car c);

#endif
