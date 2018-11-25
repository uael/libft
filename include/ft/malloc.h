/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft/string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <stdint.h>
# include <stddef.h>

extern void	ft_free(void *ptr);
extern void *ft_memalign(size_t alignment, size_t size);
extern void	*ft_malloc(size_t size);
extern void	*ft_realloc(void *ptr, size_t size);
extern void	*ft_reallocf(void *ptr, size_t size);
extern void	*ft_calloc(size_t nmemb, size_t size);

#endif
