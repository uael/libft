/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/07 09:53:34 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cute.h>

CUTEST_DATA {
    int dummy;
};

CUTEST_SETUP {
    self->dummy = 0;
}

CUTEST_TEARDOWN {
    (void) self;
}

CUTEST(atoi, common) {
    ASSERT_EQ(0, self->dummy);
    return CUTE_SUCCESS;
}

int main(void) {
    CUTEST_DATA test;

    CUTEST_PASS(atoi, common);
    return EXIT_SUCCESS;
}
