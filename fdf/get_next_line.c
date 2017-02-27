/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:31:55 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/02/27 04:59:04 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	static char		*str[ULIMIT_FD];
	char			*input;
	int				res;

	if (fd < 0 || line == NULL || fd > ULIMIT_FD)
		return (-1);
	if ((res = !!(str[fd])))
	{
		if (ft_strchr(str[fd], END))
			cut_str(str[fd], line, &str[fd]);
		else if (ft_read(fd, &input) > 0)
		{
			cut_str(ft_strjoin(str[fd], input), line, &str[fd]);
			free(input);
		}
		else if ((res = !!(*str[fd])))
		{
			*line = ft_strdup(str[fd]);
			free(str[fd]);
		}
	}
	else if ((res = ft_read(fd, &input)) && res > 0)
		cut_str(input, line, &str[fd]);
	return (res);
}

void	cut_str(char *input, char **first_part, char **last_part)
{
	int		n;
	char	*tmp;

	tmp = *last_part;
	n = ft_strseekc(input, END);
	*first_part = ft_strsub(input, 0, n);
	*last_part = ft_strsub(input, n + 1, ft_strlen(input) - n);
	if (tmp)
		free(tmp);
	free(input);
}

int		ft_read(int const fd, char **input)
{
	char	*buffer;
	char	*tmp;
	int		o_lus;

	*input = ft_strnew(0);
	buffer = (char*)malloc(BUFF_SIZE + 1);
	if (!buffer)
		return (-1);
	ft_bzero(buffer, BUFF_SIZE + 1);
	while (!(ft_strchr(*input, END)) && (o_lus = read(fd, buffer, BUFF_SIZE)))
	{
		tmp = *input;
		if (o_lus < 1)
			return (o_lus);
		buffer[o_lus] = 0;
		*input = ft_strjoin(tmp, buffer);
		ft_bzero(buffer, BUFF_SIZE + 1);
		free(tmp);
	}
	free(buffer);
	return (ft_strlen(*input) > 0);
}
