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
#include <libft.h>

CUTEST_DATA {
    int dummy;
};

CUTEST_SETUP {
	(void) self;
}

CUTEST_TEARDOWN {
    (void) self;
}

CUTEST(atoi, common) {
	ASSERT_EQ(atoi("0"), ft_atoi("0"));
	ASSERT_EQ(atoi("+0"), ft_atoi("+0"));
	ASSERT_EQ(atoi("-0"), ft_atoi("-0"));
	ASSERT_EQ(atoi("-1"), ft_atoi("-1"));
	ASSERT_EQ(atoi("1"), ft_atoi("1"));
	ASSERT_EQ(atoi("42"), ft_atoi("42"));
	ASSERT_EQ(atoi("-42"), ft_atoi("-42"));
	ASSERT_EQ(atoi("–2147483648"), ft_atoi("–2147483648"));
	ASSERT_EQ(atoi("–21474836488"), ft_atoi("–21474836488"));
	ASSERT_EQ(atoi("2147483647"), ft_atoi("2147483647"));
    return CUTE_SUCCESS;
}

int main(void) {
    CUTEST_DATA test;

    CUTEST_PASS(atoi, common);
    return EXIT_SUCCESS;
}
