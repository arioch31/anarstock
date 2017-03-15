/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 02:03:59 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/03/15 04:39:17 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
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
	printf("%c ", ptr->st_mode & S_IFLNK ? '@' : ' ');
}

int	main(int ac, char **av)
{
	struct stat ptr;

	if (ac > 1 && stat(av[1], &ptr) == 0)
	{
		printf("test\n");
		printf("%s\n", ctime(&ptr.st_atimespec.tv_sec));
		printf("%s\n", ctime(&ptr.st_mtimespec.tv_sec));
		printf("%s\n", ctime(&ptr.st_ctimespec.tv_sec));

		write_rights(&ptr);
		printf("%hu ", ptr.st_nlink);
		printf("%s  ", getpwuid(ptr.st_uid)->pw_name);
		printf("%s", getgrgid(ptr.st_gid)->gr_name);
		printf("%9lld\n", ptr.st_size);
		printf("%s", ctime(&ptr.st_mtimespec.tv_sec));
	}
	else
		printf("%s failed\n", av[1]);
	return (0);
}
