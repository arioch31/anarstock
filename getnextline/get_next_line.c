/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:31:55 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/01/15 06:47:57 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	static char		*str;
	char			*input;
	char			*tmp;
	int				res;

	if (fd < 0 || line == NULL)
		return (-1);
	input = ft_strnew(0);
	if (!str)
	{
		if ((res = ft_read(fd, &input)) && res > 0)
		{
			str = ft_strdup(ft_strchr(input, '\n'));
			*line = ft_strsub(input, 0, ft_strseekc(input, '\n'));
		}
		else return (res);
	}
	else
	{
		ft_read(fd, &input);
		tmp = ft_strjoin(str, input);
		free(str);
		str = NULL;
		free(input);
		*line =  ft_strsub(tmp, 0, ft_strseekc(tmp, '\n'));
		if (!*tmp)
			return (0);
		str = ft_strsub(tmp, ft_strseekc(tmp, '\n') + 1 , ft_strlen(tmp) -ft_strseekc(tmp, '\n'));
		free(tmp);
	}
	return (1);
}

int	ft_read(int const fd, char **input)
{
	char	*buffer;
	char	*tmp;
	int		octets_lus;

	**input = '\0';
	buffer = (char*)malloc(BUFF_SIZE + 1);
	if (!buffer)
		return (-1);
	ft_bzero(buffer, BUFF_SIZE + 1);
	while (!(ft_strchr(*input, '\n')) && (octets_lus = read(fd, buffer, BUFF_SIZE)))
	{
		tmp = *input;
		if (octets_lus < 1)
			return (octets_lus);
		buffer[octets_lus] = 0;
		*input = ft_strjoin(tmp, buffer);
		ft_bzero(buffer, BUFF_SIZE + 1);
		free(tmp);
	}
	free(buffer);
	return (octets_lus > 0);
}
