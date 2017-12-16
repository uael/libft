/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:57 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/08 15:09:01 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str.h"

inline int		ft_strcmp(char const *s1, char const *s2)
{
	while (((uint8_t)*s1 == (uint8_t)*s2) && *s1)
	{
		++s1;
		++s2;
	}
	return (*(uint8_t *)s1 - *(uint8_t *)s2);
}

inline char		*ft_strcpy(char *dest, char const *src)
{
	char *s;

	s = dest;
	while ((*s++ = *src++))
		;
	return (dest);
}

inline char		*ft_strdup(char const *src)
{
	char	*dup;
	size_t	sz;

	sz = ft_strlen(src);
	dup = ft_malloc((sz + 1) * sizeof(char));
	return (ft_strcpy(dup, src));
}

inline size_t	ft_strlcat(char *dest, char const *src, size_t size)
{
	size_t	slen;
	size_t	dlen;

	slen = (size_t)ft_strlen(src);
	dlen = (size_t)ft_strnlen(dest, size);
	if (dlen == size)
		return (size + slen);
	if (slen < size - dlen)
		ft_strncpy(dest + dlen, src, slen + 1);
	else
	{
		ft_strncpy(dest + dlen, src, size - dlen - 1);
		dest[size - 1] = '\0';
	}
	return (dlen + slen);
}

inline size_t	ft_strlcpy(char *dst, char const *src, size_t size)
{
	char const	*sptr;
	size_t		slen;

	sptr = src;
	while (*sptr++)
		;
	slen = ((size_t)(sptr - src - 1));
	if (slen < size)
		ft_strncpy(dst, src, slen + 1);
	else if (size != 0)
	{
		ft_strncpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (slen);
}
