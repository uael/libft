/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:37:09 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/08 16:05:49 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <libft.h>

t_i32	main(void)
{
	static struct { char *a; char s; char *b[10]; } tests[] = {
		{ "a", '*', {"a", NULL} },
		{ "*hello**fellow", '*', {"hello", "fellow", NULL} },
		{ "coucou*toi**", '*', {"coucou", "toi", NULL} },
		{ "coucou*tu**veux", '*', {"coucou", "tu", "veux", NULL} },
	};

	for (int i = 0; i < 3; ++i)
	{
		t_car **ss = ft_strsplit(tests->a, tests->s);
		t_car **sst = tests->b;
		while (*sst)
		{
			assert(ft_strequ(*sst, *ss));
			assert(ft_strequ(*ss, *sst));
			++ss;
			++sst;
		}
		assert(*sst == NULL);
		assert(*ss == NULL);
	}
}
