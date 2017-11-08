/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bwero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:44:11 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/07 09:44:26 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cute.h>
#include <libft.h>

CUTEST_DATA {
	t_car *str;
};

CUTEST_SETUP {
    self->str = malloc(10);
	strcpy(self->str, "abcdefghi");
}

CUTEST_TEARDOWN {
    free(self->str);
}

CUTEST(bzero, common) {
    ft_bzero(self->str, 0);
	ASSERT_SEQ("abcdefghi", self->str);
	ft_bzero(self->str, 1);
	ASSERT_SEQ("", self->str);
	ASSERT_SEQ("bcdefghi", self->str + 1);
    return CUTE_SUCCESS;
}

int main(void) {
    CUTEST_DATA test;

    CUTEST_PASS(bzero, common);
    return EXIT_SUCCESS;
}
