/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:32:13 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/01/19 15:19:46 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUFF_SIZE 16

typedef struct	s_str_fd 
{
	char	*str;
	int		test_padding[100];
	int		fd;
}				t_str_fd;

int		ft_read(int fd, char **input);
int		get_next_line(int const fd, char **line);
t_str_fd	*seek_fd(t_list *start, int fd);
void 	destr_s(t_str_fd *s);
t_str_fd	*crea_s(char *str, int fd);

#endif
