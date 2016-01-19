/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:31:55 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/01/19 13:16:18 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	static char		*str = NULL;
	char			*input;
	char			*tmp;
	int				res;

	if (fd < 0 || line == NULL)
		return (-1);
	if (!str)
	{
		if ((res = ft_read(fd, &input)) && res > 0)
			cut_str(input, line, &str);
		else return (res);
	}
	else
	{
		ft_read(fd, &input);
		tmp = ft_strjoin(str, input);
		free(str);
		if (!*tmp)
			return (0);
		cut_str(tmp, line, &str);	
		free(tmp);
	}
	free(input);
	return (1);
}

void cut_str(char *input, char **first_part, char **last_part)
{
	int	n;

	n = ft_strseekc(input, '\n');
	*first_part = ft_strsub(input, 0, n);
	*last_part = ft_strsub(input, n + 1, ft_strlen(input) - n);
}

int	ft_read(int const fd, char **input)
{
	char	*buffer;
	char	*tmp;
	int		octets_lus;

	*input = ft_strnew(0);
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
	return (ft_strlen(*input) > 0);
}
