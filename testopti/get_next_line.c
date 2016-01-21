/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:31:55 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/01/21 02:14:47 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	static char		*str[ULIMIT_FD];
	char			*input;
	char			*tmp;
	int				res;

	if (fd < 0 || line == NULL)
		return (-1);
	if (str[fd])
	{
        if (!((res = 1)) || !ft_strchr(str[fd], END))
            res = ft_read(fd, &input);
    	tmp = ft_strjoin(str[fd], input);
		if (*tmp)
            cut_str(tmp, line, &str[fd]);
		free(tmp);
   	}
	else if ((res = ft_read(fd, &input)) && res > 0)
			cut_str(input, line, &str[fd]);
	free(input);
	return (res);
}

void	cut_str(char *input, char **first_part, char **last_part)
{
	int	n;

	if (*last_part)
		free(*last_part);
	n = ft_strseekc(input, END);
	*first_part = ft_strsub(input, 0, n);
	*last_part = ft_strsub(input, n + 1, ft_strlen(input) - n);
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
