/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/25 12:01:47 by djean             #+#    #+#             */
/*   Updated: 2015/12/03 14:54:29 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READ_H
# define FT_READ_H
# define BUF_SIZE 4096

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>


char	*ft_read(int fd);
char	*enlarge_input(char *input, char *buffer, int len, int octet_lus);
int		ft_open(char *file);
void	ft_close(int fd, char *input);

#endif
