/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 01:12:01 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/03/24 04:57:06 by aeguzqui         ###   ########.fr       */
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
	char lnk[250];
	char *full_name;

	write_rights(ptr);
	printf(" %*hu ", tab[0], ptr->st_nlink);
	printf("%-*s  ", tab[1], getpwuid(ptr->st_uid)->pw_name);
	printf("%-*s ", tab[2], getgrgid(ptr->st_gid)->gr_name);
	printf("%*lld ", tab[3], ptr->st_size);
	write_date(gmtime(&ptr->st_mtimespec.tv_sec));
	printf(" %-s", name);
	bzero(lnk, 250);
	if (S_ISLNK(ptr->st_mode))
	{
		full_name = get_full_name(path, name);
		if (readlink(full_name, lnk, 250) > 0)
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

void	explore_dir(char *path)
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
				print_line(&ptr, dp->d_name, path, tab);// ft_lstadd
			free(full_name);
		}
	// trier et afficher !
	// recursiver !
	(void)closedir(dirp);
}
