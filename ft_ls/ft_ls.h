/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 02:03:59 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/03/29 05:43:52 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_LS_H
# define _FT_LS_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <strings.h>
# include <dirent.h>
# include <sys/stat.h>
# include <time.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <errno.h>
# include "libft.h"

# define F_RECURSIVE 1
# define F_INLINE 2
# define F_HIDDEN 4
# define F_HIDE_USER 8
# define F_NO_EXPLORE 16
# define F_REV_ORDER 32
# define F_SORT_TIME_M 64
# define F_SORT_TIME_A 128
# define F_SORT_TIME_CH 256
# define F_SORT_TIME_CR 512 //darwin 64 macro a verifier
# define F_SORT_SIZE 1024
# define F_NO_SORT 2048

typedef struct	s_env
{
	int		flags;
	int		nb_targets;
	char	**targets;
}				t_env;

typedef struct	s_entry
{
	char		*name;
	struct stat	*data;
}				t_entry;

char			*get_full_name(char *path, char *name);
void			check_sizes(int *tab, struct stat *ptr);
int				*get_sizes_pad(char *path);

void			aff_entry(t_list *entry);

void			write_rights(struct stat *ptr);
void			write_date(struct tm *t);
void			print_dir_line(char *path);
void			print_line(struct stat *ptr, char *name, char *path, int *tab);
void			explore_dir(t_env *env, char *path);
t_list			*sort_choose(t_env *env, t_list *lst);

#endif
