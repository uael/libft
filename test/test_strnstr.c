/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:37:09 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/08 16:08:43 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <libft.h>

t_i32	main(void)
{
	static struct { char *a; char *b; } tests[] = {
		{ "FF", "see FF your FF return FF now FF" },
		{ "FF", "see F your F return FF now FF" },
		{ "FF", "see F your F return F now FF" },
		{ "abcc", "c" },
		{ "aaabbbaaabbb", "abbaaab" },
		{ "MZIRIBMZIRIBMZP", "MZIRIBMZP" },
		{ "こんにちは", "にち" },
		{ "a", "" }
	};
	for (int i = 0; i < 8; ++i)
	{
		char *s1 = tests[i].a;
		char *s2 = tests[i].b;

		assert(strnstr(s1, s2, 0) == ft_strnstr(s1, s2, 0));
		assert(strnstr(s2, s2, 0) == ft_strnstr(s2, s2, 0));
		assert(strnstr(s2, s1, 0) == ft_strnstr(s2, s1, 0));
		assert(strnstr(s1, s1, 0) == ft_strnstr(s1, s1, 0));

		assert(strnstr(s1, s2, strlen(s1)) == ft_strnstr(s1, s2, strlen(s1)));
		assert(strnstr(s2, s2, strlen(s1)) == ft_strnstr(s2, s2, strlen(s1)));
		assert(strnstr(s2, s1, strlen(s1)) == ft_strnstr(s2, s1, strlen(s1)));
		assert(strnstr(s1, s1, strlen(s1)) == ft_strnstr(s1, s1, strlen(s1)));

		assert(strnstr(s1, s2, strlen(s2)) == ft_strnstr(s1, s2, strlen(s2)));
		assert(strnstr(s2, s2, strlen(s2)) == ft_strnstr(s2, s2, strlen(s2)));
		assert(strnstr(s2, s1, strlen(s2)) == ft_strnstr(s2, s1, strlen(s2)));
		assert(strnstr(s1, s1, strlen(s2)) == ft_strnstr(s1, s1, strlen(s2)));

		assert(strnstr(s1, s2, strlen(s1) + strlen(s2))
			== ft_strnstr(s1, s2, strlen(s1) + strlen(s2))
		);
		assert(strnstr(s2, s2, strlen(s1) + strlen(s2))
			== ft_strnstr(s2, s2, strlen(s1) + strlen(s2))
		);
		assert(strnstr(s2, s1, strlen(s1) + strlen(s2))
			== ft_strnstr(s2, s1, strlen(s1) + strlen(s2))
		);
		assert(strnstr(s1, s1, strlen(s1) + strlen(s2))
			== ft_strnstr(s1, s1, strlen(s1) + strlen(s2))
		);
	}
	return (EXIT_SUCCESS);
}
