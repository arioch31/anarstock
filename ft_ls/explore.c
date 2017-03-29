/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 00:26:47 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/03/29 02:02:25 by aeguzqui         ###   ########.fr       */
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

void	explore_dir(char *path)
{
	DIR				*dirp;
	t_list			*entries;

	dirp = opendir(path);
	if (dirp)
	{
		entries = list_entries(dirp, path);
		printf("\ntest aff lst\n");
		ft_lstaff(entries, &aff_entry);
	}
	(void)closedir(dirp);
}
