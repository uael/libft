/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/09 12:18:09 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# ifdef _MSC_VER
#  include <io.h>
# else
#  include <unistd.h>
# endif

typedef char			t_car;

typedef unsigned char	t_u08;
typedef unsigned short	t_u16;
typedef unsigned int	t_u32;
typedef unsigned long	t_u64;

typedef signed char		t_i08;
typedef signed short	t_i16;
typedef signed int		t_i32;
typedef signed long		t_i64;

typedef float			t_f32;
typedef double			t_f64;

typedef size_t			t_usz;

typedef struct s_list	t_list;

struct					s_list
{
	void	*content;
	t_usz	content_size;
	t_list	*next;
};

extern t_i32			ft_isalnum(t_i32 c);
extern t_i32			ft_isascii(t_i32 c);
extern t_i32			ft_isalpha(t_i32 c);
extern t_i32			ft_isdigit(t_i32 c);
extern t_i32			ft_islower(t_i32 c);
extern t_i32			ft_isprint(t_i32 c);
extern t_i32			ft_isupper(t_i32 c);
extern t_i32			ft_isspace(t_i32 c);

extern t_i32			ft_tolower(t_i32 c);
extern t_i32			ft_toupper(t_i32 c);

extern void				ft_putchar(t_car c);
extern void				ft_putchar_fd(t_car c, t_i32 fd);
extern void				ft_putendl(t_car const *s);
extern void				ft_putendl_fd(t_car const *s, t_i32 fd);
extern void				ft_putnbr(t_i32 n);
extern void				ft_putnbr_fd(t_i32 n, t_i32 fd);
extern void				ft_putstr(t_car const *s);
extern void				ft_putstr_fd(t_car const *s, t_i32 fd);

extern void				ft_lstadd(t_list **lst, t_list *new);
extern void				ft_lstdel(t_list **l, void (*d)(void *p, t_usz s));
extern void				ft_lstdelone(t_list **l, void (*d)(void *p, t_usz s));
extern void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
extern t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
extern t_list			*ft_lstnew(void const *content, t_usz content_size);

extern void				ft_bzero	(void *ptr, t_usz n);

extern void				*ft_memalloc(t_usz sz);
extern void				*ft_memccpy(void *d, void const *s, t_i32 c, t_usz n);
extern void				*ft_memchr(void const *s, t_i32 c, size_t n);
extern t_i32			ft_memcmp(void const *a, void const *b, t_usz n);
extern void				*ft_memcpy(void *dst, void const *src, t_usz n);
extern void				ft_memdel(void **ptr);
extern void				*ft_memmove(void *dst, void const *src, t_usz len);
extern void				*ft_memrcpy(void *dst, void const *src, t_usz n);
extern void				*ft_memset(void *b, t_i32 c, t_usz len);

extern t_i32			ft_atoi(t_car const *str);
extern t_car			*ft_itoa(t_i32 n);

extern t_car			*ft_strcat(t_car *dest, t_car const *src);
extern t_car			*ft_strchr(t_car const *s, t_i32 c);
extern t_i32			ft_strcmp(t_car const *s1, t_car const *s2);
extern void				ft_strclr(t_car *s);
extern t_car			*ft_strcpy(t_car *dest, t_car const *src);
extern void				ft_strdel(t_car **s);
extern t_car			*ft_strdup(t_car const *src);
extern t_i32			ft_strequ(t_car const *s1, t_car const *s2);
extern void				ft_striter(t_car *s, void (*f)(t_car *));
extern void				ft_striteri(t_car *s, void (*f)(t_u32 i, t_car *c));
extern t_car			*ft_strjoin(t_car const *s1, t_car const *s2);
extern t_usz			ft_strlcat(t_car *dest, t_car *src, t_usz size);
extern t_usz			ft_strlen(t_car const *str);
extern t_car			*ft_strmap(t_car const *s, t_car (*f)(t_car));
extern t_car			*ft_strmapi(t_car const *s, t_car (*f)(t_u32, t_car));
extern t_car			*ft_strncat(t_car *dest, t_car const *src, t_usz nb);
extern t_i32			ft_strncmp(t_car const *s1, t_car const *s2, t_usz n);
extern t_car			*ft_strncpy(t_car *dest, t_car const *src, t_usz n);
extern t_i32			ft_strnequ(t_car const *s1, t_car const *s2, t_usz n);
extern t_car			*ft_strnew(size_t sz);
extern t_usz			ft_strnlen(t_car const *str, t_usz size);
extern t_car			*ft_strnstr(t_car const *str, t_car const *f, t_usz l);
extern t_car			*ft_strrchr(t_car const *s, t_i32 c);
extern t_car			**ft_strsplit(t_car const *s, t_car c);
extern t_car			*ft_strstr(t_car const *haystack, t_car const *needle);
extern t_car			*ft_strsub(t_car const *s, t_u32 start, t_usz len);
extern t_car			*ft_strtrim(t_car const *s);
extern t_usz			ft_strword(t_car const *s, t_car c);

#endif
