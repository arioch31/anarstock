/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 02:03:59 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/03/24 01:19:53 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

int		*get_sizes_pad(char *path)
{
	int				*tab;
	struct dirent	*dp;
	DIR				*dirp;
	struct stat		ptr;
	char			*full_name;

	dirp = opendir(path);
	tab = malloc(sizeof(int) * 4);
	ft_bzero(tab, sizeof(int) * 4);
	if (dirp)
		while ((dp = readdir(dirp)) != NULL)
		{
			full_name = get_full_name(path, dp->d_name);
			if (lstat(full_name, &ptr) == 0)
				check_sizes(tab, &ptr);
			free(full_name);
		}
	(void)closedir(dirp);
	return (tab);
}

int		main(int ac, char **av)
{
	struct stat ptr;
	char		*lnk;
	int			tab[] = {0, 0, 0, 0};

	if (ac > 1 && lstat(av[1], &ptr) == 0)
	{
		if (S_ISDIR(ptr.st_mode))
		{
			if (S_ISLNK(ptr.st_mode) && readlink(av[1], lnk, 250))
				print_dir_line(lnk);
			else
				print_dir_line(av[1]);
		}
		else
			print_line(&ptr, av[1], ".", tab);
	}
	else if (ac == 1)
		print_dir_line(".");
	return (0);
}
