/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 01:12:01 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/04/03 05:12:20 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

const char	*g_month[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
	"Aug", "Sep", "Oct", "Nov", "Dec"};

const int	g_tab1[4] = {0, 0, 0, 0};

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

void	print_line(struct stat *ptr, char *name, char *path, int *tab)//env et t_list?
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
	ft_bzero(lnk, 256);
	if (S_ISLNK(ptr->st_mode) && path)
	{
		full_name = get_full_name(path, name);
		if (readlink(full_name, lnk, 256) > 0)
			printf(" -> %s", lnk);
		else
			printf("%s link not read from %s", lnk, full_name);
		free(full_name);
	}
	printf("\n");
}
