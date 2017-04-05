/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entries.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 00:57:56 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/04/05 02:47:34 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	delete_entry(void *lst, size_t useless)
{
	t_entry			*entry;

	(void)useless;
	entry = (t_entry*)lst;
	free(entry->name);
	free(entry->data);
	entry->path = NULL;
	free(lst);
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
		entry->path = path;
		ret = ft_lstnew(NULL, 0);
		ret->content = (void*)entry;
		ret->content_size = 1;
		free(full_name);
	}
	else
		printf("%s read failed: %s\n", full_name, strerror(errno));
	return (ret);
}

t_list	*list_entries(DIR *dirp, char *path, u_long *size, int *format)
{
	t_list			*lst;
	t_list			*tmp;
	struct dirent	*dp;
	t_entry			*ent;

	lst = NULL;
	tmp = NULL;
	while ((dp = readdir(dirp)) != NULL)
	{
		tmp = add_entry(path, dp->d_name);
		ent = tmp->content;
		if ((ft_strncmp(ent->name, ".", 2) && ft_strncmp(ent->name, "..", 3)) &&
		!(ent->name[0] == '.' && !(format[4])))
		{
			check_sizes(format, ent->data);
			*size += ent->data->st_blocks;
		}
		ft_lstadd(&lst, tmp);
	}
	return (lst);
}
