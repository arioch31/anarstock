/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 01:12:01 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/03/28 06:58:00 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

const char	*g_month[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
	"Aug", "Sep", "Oct", "Nov", "Dec"};

void	write_rights(struct stat *ptr)
{
	if (S_ISDIR(ptr->st_mode))
		printf("%c", 'd');
	else if (S_ISBLK(ptr->st_mode))
		printf("%c", 'b');
	else if (S_ISCHR(ptr->st_mode))
		printf("%c", 'c');
	else if (S_ISFIFO(ptr->st_mode))
		printf("%c", 'p');
	else if (S_ISSOCK(ptr->st_mode))
		printf("%c", 's');
	else if (S_ISLNK(ptr->st_mode))
		printf("%c", 'l');
	else
		printf("%c", '-');
	printf("%c%c%c%c%c%c%c%c%c",
	ptr->st_mode & S_IRUSR ? 'r' : '-',
	ptr->st_mode & S_IWUSR ? 'w' : '-',
	ptr->st_mode & S_IXUSR ? 'x' : '-',
	ptr->st_mode & S_IRGRP ? 'r' : '-',
	ptr->st_mode & S_IWGRP ? 'w' : '-',
	ptr->st_mode & S_IXGRP ? 'x' : '-',
	ptr->st_mode & S_IROTH ? 'r' : '-',
	ptr->st_mode & S_IWOTH ? 'w' : '-',
	ptr->st_mode & S_IXOTH ? 'x' : '-');
}

void	write_date(struct tm *t)
{
	printf("%s %02d %02d:%02d", g_month[t->tm_mon],
	t->tm_mday, t->tm_hour + 1, t->tm_min);
}

void	print_line(struct stat *ptr, char *name, char *path, int *tab)
{
	char lnk[256];
	char *full_name;

	write_rights(ptr);
	printf(" %*hu ", tab[0], ptr->st_nlink);
	printf("%-*s  ", tab[1], getpwuid(ptr->st_uid)->pw_name);
	printf("%-*s ", tab[2], getgrgid(ptr->st_gid)->gr_name);
	printf("%*lld ", tab[3], ptr->st_size);
	write_date(gmtime(&ptr->st_mtimespec.tv_sec));
	printf(" %-s", name);
	bzero(lnk, 256);
	if (S_ISLNK(ptr->st_mode) && path)
	{
		full_name = get_full_name(path, name);
		if (readlink(full_name, lnk, 256) > 0)
			printf(" -> %s", lnk);
		else
			printf("%s not read from %s", lnk, full_name);
		free(full_name);
	}
	printf("\n");
}

void	print_dir_line(char *path)
{
	struct dirent	*dp;
	DIR				*dirp;
	struct stat		ptr;
	char			*full_name;
	int				*tab;

	tab = get_sizes_pad(path);
	dirp = opendir(path);
	if (dirp)
		while ((dp = readdir(dirp)) != NULL)
		{
			full_name = get_full_name(path, dp->d_name);
			if (lstat(full_name, &ptr) == 0)
				print_line(&ptr, dp->d_name, path, tab);
			else
				printf("%s failed, code: %s\n", full_name, strerror(errno));
			free(full_name);
		}
	(void)closedir(dirp);
}

void	aff_entry(t_list *entry)
{
	t_entry	*ent;
	int		tab[] = {0, 0, 0, 0};

	printf("try");
	ent = (t_entry*)entry->content;
	printf("name :%s\t", ent->name);
	print_line(ent->data, ent->name, NULL, tab);
	printf("OK\n");
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
