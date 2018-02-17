/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_climb_tree.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mc <mc.maxcanal@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 20:57:25 by mc                #+#    #+#             */
/*   Updated: 2018/02/17 13:52:30 by mc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOB_CLIMB_TREE_H
# define GLOB_CLIMB_TREE_H

#include <sys/types.h> /* for {open,read,close}dir */
#include <sys/syslimits.h> /* for PATH_MAX */
#include <dirent.h> /* for {open,read,close}dir */

# include "libft/str.h" /* for ft_strchr */
# include "libft/sort.h" /* for ft_shellsort */
# include "libft/ft_glob.h" /* for t_glob and GLOBUX flags */
# include "glob_match.h" /* for glob_match */

# define IS_DIR(dirent) ((dirent)->d_type == DT_DIR)

# define GLOBUX_BOOM_BABY 5
# define GLOBUX_NOBODY_GIVES_A_DAMN 6
/* # define GLOBUX_INITIALIZED (1 << 15) */


typedef unsigned char	t_byte;

/* Structure describing a glob match.  */
typedef struct s_match	t_match;
struct					s_match
{
	t_match	*next;
	t_byte	buf[1];
};


/*
** Recursively check PAT on the matching directory tree
**
** @pat: Shell-style pattern to match, e.g. "*.[ch]".
*/
int			glob_climb_tree(char const *pattern, t_glob *pglob, t_match **match_list);

int			glob_read_dir(char const *pattern, int flags, \
						  t_match **match_list, int depth, char const *previous_dir);


/*
** in glob_list.c:
*/
t_match		*matchctor(char const *path, size_t len);
void		matchdtor(t_match *match);
void		add_match_to_list(t_match *match, t_match **match_list);
size_t		list_len(t_match *match_list);


/*
** in glob_dir.c:
*/
int			glob_count_depth(char const *pattern);
int			glob_open_dir(DIR **dir, char const *dir_name, int flags);
int			glob_close_dir(DIR *dir, int flags);
char const	*glob_get_sub_pattern(char const *pattern, int depth);
char const *glob_get_folder_name(char const *path);
int			glob_append_file_name(char *path_buf, char const *new_file);
int			glob_store_dir_name(char *path_buf, char const *prev_dir, \
								char const *new_dir);

#endif /* GLOB_CLIMB_TREE_H */
