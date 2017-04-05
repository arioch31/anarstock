/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 00:26:47 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/04/05 03:23:26 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	check_sizes(int *tab, struct stat *ptr)
{
	int len;

	len = int_strlen(ptr->st_nlink, 10);
	if (len > tab[0])
		tab[0] = len;
	len = ft_strlen(getpwuid(ptr->st_uid)->pw_name);
	if (len > tab[1])
		tab[1] = len;
	len = ft_strlen(getgrgid(ptr->st_gid)->gr_name);
	if (len > tab[2])
		tab[2] = len;
	len = int_strlen(ptr->st_size, 10);
	if (len > tab[3])
		tab[3] = len;
}

char	*get_full_name(char *path, char *name)
{
	char			*full_name;
	char			*tmp;

	if (path && ft_strcmp(".", path))
	{
		tmp = ft_strjoin(path, "/");
		full_name = ft_strjoin(tmp, name);
		free(tmp);
	}
	else
		full_name = ft_strdup(name);
	return (full_name);
}

void	recursive_explo(t_env *env, char *path, t_list *entry)
{
	t_entry	*ent;
	char	*full_name;

	while (entry)
	{
		ent = (t_entry*)entry->content;
		if (S_ISDIR(ent->data->st_mode) && ft_strncmp(ent->name, ".", 2)
		&& ft_strncmp(ent->name, "..", 3))
		{
			full_name = get_full_name(path, ent->name);
			printf("\n");
			explore_dir(env, full_name);
			free(full_name);
		}
		entry = entry->next;
	}
}

void	explore_dir(t_env *env, char *path)
{
	DIR				*dirp;
	t_list			*entries;
	int				tab[5];
	struct stat		ptr;
	u_long			size;

	ft_bzero(tab, 5 * sizeof(int));
	size = 0;
	if (!(env->flags & F_NO_EXPLORE) && (dirp = opendir(path)))
	{
		tab[4] = (env->flags & F_NO_HIDDEN);
		entries = list_entries(dirp, path, &size, tab);
		entries = sort_choose(env, entries);
		aff_entries(entries, env, tab, size);
		if (env->flags & F_RECURSIVE)
			recursive_explo(env, path, entries);
		(void)closedir(dirp);
		ft_lstdel(&entries, &delete_entry);
	}
	else if ((env->flags & F_NO_EXPLORE) && (lstat(path, &ptr) == 0))
	{
		check_sizes(tab, &ptr);
		print_line(&ptr, path, NULL, tab);
	}
	else
		printf("ft_ls: %s: %s\n", path, strerror(errno));
}
