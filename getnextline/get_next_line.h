/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:32:13 by aeguzqui          #+#    #+#             */
/*   Updated: 2015/12/14 15:44:21 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H
#include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
#define BUF_SIZE 10

char	*ft_read(int fd);
char	*enlarge_input(char *input, char *buffer, int len, int octet_lus);
int		get_next_line(int const fd, char **line);



#endif
