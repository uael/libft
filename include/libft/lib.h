/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft/lib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/15 18:06:48 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_LIB_H
# define LIBFT_LIB_H

# include <stdlib.h>
# include "types.h"

# define FT_INIT(S, TY) ft_memset(S, 0, sizeof(TY))

extern int		ft_atoi(char const *str);
extern char		*ft_itoa(int n);
extern char		*ft_itoa_base(int n, uint8_t base);
extern uint8_t	ft_digits(int64_t n, uint8_t base);

#endif
