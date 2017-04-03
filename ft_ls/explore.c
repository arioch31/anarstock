/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 00:26:47 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/04/03 05:08:15 by aeguzqui         ###   ########.fr       */
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

	if (ft_strcmp(".", path))
	{
		tmp = ft_strjoin(path, "/");
		full_name = ft_strjoin(tmp, name);
		free(tmp);
	}
	else
		full_name = ft_strdup(name);
	return (full_name);
}

void	delete_entry(void *lst, size_t useless)
{
	t_entry			*entry;

	(void)useless;
	entry = (t_entry*)lst;
	free(entry->name);
	free(entry->data);
}

t_list	*add_entry(char *path, char *name)
{
	t_entry			*entry;
	struct stat		*ptr;
	char			*full_name;
	t_list			*ret;

	ret = NULL;
	ptr = malloc(sizeof(struct stat));
	full_name = get_full_name(path, name);
	if (lstat(full_name, ptr) == 0)
	{
		entry = malloc(sizeof(t_entry));
		entry->name = ft_strdup(name);
		entry->data = ptr;
		ret = ft_lstnew(NULL, 0);
		ret->content = (void*)entry;
		ret->content_size = 1;
		free(full_name);
	}
	else
		printf("%s read failed: %s\n", full_name, strerror(errno));
	return (ret);
}

t_list	*list_entries(DIR *dirp, char *path)
{
	t_list			*lst;
	t_list			*tmp;
	struct dirent	*dp;

	lst = NULL;
	tmp = NULL;
	while ((dp = readdir(dirp)) != NULL)
	{
		tmp = add_entry(path, dp->d_name);
		ft_lstadd(&lst, tmp);
	}
	return (lst);
}

void	aff_entries(t_list *entry, t_env *env, char *path, int *format)
{
	t_entry	*ent;

	while (entry)
	{
		ent = (t_entry*)entry->content;
		if (!(!(env->flags & F_NO_HIDDEN) && ent->name[0] == '.'))
			print_line(ent->data, ent->name, path, format);
		entry = entry->next;
	}
}

u_long	check_entries(t_list *entry, t_env *env, int *format)
{
	t_entry	*ent;
	u_long	ret;

	ret = 0;
	while (entry)
	{
		ent = (t_entry*)entry->content;
		if (ft_strncmp(ent->name, ".", 2) && ft_strncmp(ent->name, "..", 3))
		{
			check_sizes(format, ent->data);
			ret += ent->data->st_blocks;
		}
		entry = entry->next;
	}
	return (ret);
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
	int				tab[4];
	struct stat		ptr;
	u_long			size;

	ft_bzero(tab, 4 * sizeof(int));
	if (!(env->flags & F_NO_EXPLORE) && (dirp = opendir(path)))
	{
		entries = list_entries(dirp, path);
		size = check_entries(entries, env, tab);
		printf("\n%s:\n%lu\n", path, size);
		entries = sort_choose(env, entries);
		aff_entries(entries, env, path, tab);
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
		printf("%s read failed: %s\n", path, strerror(errno));
}
