/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 02:03:59 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/03/22 04:49:14 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <uuid/uuid.h>

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

const char	*g_month[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
	"Aug", "Sep", "Oct", "Nov", "Dec"};

void	write_date(struct tm *t)
{
	printf("%s %02d %02d:%02d", g_month[t->tm_mon],
	t->tm_mday, t->tm_hour + 1, t->tm_min);
}

void	print_line(struct stat *ptr, char *name)
{
	char test[250];

	write_rights(ptr);
	printf(" %2hu ", ptr->st_nlink);
	printf("%s  ", getpwuid(ptr->st_uid)->pw_name);
	printf("%s", getgrgid(ptr->st_gid)->gr_name);
	printf("%9lld ", ptr->st_size);
	write_date(gmtime(&ptr->st_mtimespec.tv_sec));
	printf(" %-s", name);
	bzero(test, 250);
	if (S_ISLNK(ptr->st_mode) && readlink(name, test, 250))
		printf(" -> %s", test);
	printf("\n");
}

void	print_dir_line(char *path)
{
	struct dirent	*dp;
	DIR				*dirp;
	struct stat		ptr;

	dirp = opendir(path);
	if (dirp)
		while ((dp = readdir(dirp)) != NULL)
		{
			if (lstat(dp->d_name, &ptr) == 0)
				print_line(&ptr, dp->d_name);
			else
				printf("%s failed\n", dp->d_name);
		}
	(void)closedir(dirp);
}

int		main(int ac, char **av)
{
	struct stat ptr;

	if (ac > 1 && stat(av[1], &ptr) == 0)
	{
		print_dir_line(av[1]);
	}
	else if (ac == 1)
		print_dir_line(".");
	return (0);
}
