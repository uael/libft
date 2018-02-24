/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_brace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mc.maxcanal@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:55:44 by mcanal            #+#    #+#             */
/*   Updated: 2018/02/24 10:11:54 by mc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_util.h"
#include "../glob_climb_tree.h"

static char const	*glob_find_comma(char const *pat, char const *pat_end)
{
	if (pat >= pat_end)
		return (NULL);
	if (*pat == ',')
		return (pat);
	return (glob_find_comma(pat + 1, pat_end));
}

static int			glob_copy_pattern_and_boom(char const *pat, size_t size, \
									t_glob_env *e)
{
	char		brace_buf[PATH_MAX];

	if (size + 1 > PATH_MAX)
		return (GLOBUX_NOSPACE);
	ft_memcpy(brace_buf, pat, size);
	*(brace_buf + size) = '\0';
	e->pattern = brace_buf;
	return (glob_climb_tree(e));
}

static int			glob_check_brace(t_glob_env *e)
{
	char const	*pat;
	char const	*pat_end;
	char const	*comma;

	pat_end = NULL;
	pat = e->pattern;
	while (*pat)
	{
		if (*pat == '{' && (pat == e->pattern || *(pat - 1) != '\\'))
		{
			if (!(pat_end = is_there_a_closing_bracket(pat, *(e->flags), '}')))
				return (GLOBUX_SUCCESS);
            break ;
		}
		pat++;
	}
	if (!*pat)
		return (GLOBUX_SUCCESS);
	while ((comma = glob_find_comma(pat + 1, pat_end)))
	{
		glob_copy_pattern_and_boom(pat + 1, (size_t)(comma - pat) - 1, e);
		pat = comma;
	}
	glob_copy_pattern_and_boom(pat + 1, (size_t)(pat_end - pat) - 1, e);
	return (-1);
}

int					glob_brace(t_glob_env *e)
{
	if (!(*(e->flags) & GLOBUX_BRACE))
		return (GLOBUX_SUCCESS);
	return (glob_check_brace(e));
}
