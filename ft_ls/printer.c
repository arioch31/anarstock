/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 01:12:01 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/04/05 04:59:53 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

const char	*g_month[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
	"Aug", "Sep", "Oct", "Nov", "Dec"};

void	print_inline(t_entry *entry, int *tab)
{
	char		lnk[256];
	char		*full_name;
	struct stat	*ptr;

	ptr = entry->data;
	write_rights(ptr);
	printf(" %*hu ", tab[0], ptr->st_nlink);
	printf("%-*s  ", tab[1], getpwuid(ptr->st_uid)->pw_name);
	printf("%-*s ", tab[2], getgrgid(ptr->st_gid)->gr_name);
	printf("%*lld ", tab[3], ptr->st_size);
	write_date(gmtime(&ptr->st_mtimespec.tv_sec));
	printf(" %-s", entry->name);
	ft_bzero(lnk, 256);
	if (S_ISLNK(ptr->st_mode) && (entry->path))
	{
		full_name = get_full_name((entry->path), entry->name);
		if (readlink(full_name, lnk, 256) > 0)
			printf(" -> %s", lnk);
		else
			printf("%s link not read from %s", lnk, full_name);
		free(full_name);
	}
	printf("\n");
}

void	aff_entries(t_list *entry, t_env *env, int *format, u_long size)
{
	t_entry	*ent;

	if (env->nb_targets > 1 || env->flags & F_RECURSIVE)
		printf("%s:\n", ((t_entry*)entry->content)->path);
	if (env->flags & F_INLINE)
		printf("total %lu\n", size);
	while (entry)
	{
		ent = (t_entry*)entry->content;
		if (!(!(env->flags & F_NO_HIDDEN) && ent->name[0] == '.'))
		{
			if (env->flags & F_INLINE)
				print_inline(ent, format);
			else
				printf("%s\t", ent->name);
		}
		entry = entry->next;
	}
	printf("%s", (env->flags & F_INLINE) ? "" : "\n");
}

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
	ft_bzero(lnk, 256);
	if (S_ISLNK(ptr->st_mode))
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
