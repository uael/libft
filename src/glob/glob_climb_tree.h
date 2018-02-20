/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_climb_tree.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 20:57:25 by mc                #+#    #+#             */
/*   Updated: 2018/02/20 11:32:16 by mc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOB_CLIMB_TREE_H
# define GLOB_CLIMB_TREE_H

# include "glob_match.h" /* for glob_match */
# include "glob_util/glob_util.h" /* for glob_* */


/*
** Recursively check PAT on the matching directory tree
**
** @pat: Shell-style pattern to match, e.g. "*.[ch]".
*/
int			glob_climb_tree(char const *pattern, t_glob *pglob, t_match **match_list);


/*
** TODO: doc
*/
int			glob_read_dir(char const *pattern, int flags, \
						  t_match **match_list, int depth, char const *previous_dir);

#endif /* GLOB_CLIMB_TREE_H */
