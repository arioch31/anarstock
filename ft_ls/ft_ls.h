/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 02:03:59 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/03/24 01:21:28 by aeguzqui         ###   ########.fr       */
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

char	*get_full_name(char *path, char *name);
void	check_sizes(int *tab, struct stat *ptr);
int		*get_sizes_pad(char *path);

void	write_rights(struct stat *ptr);
void	write_date(struct tm *t);
void	print_dir_line(char *path);
void	print_line(struct stat *ptr, char *name, char *path, int *tab);

#endif
