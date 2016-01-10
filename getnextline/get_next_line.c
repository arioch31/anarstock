/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:31:55 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/01/10 17:52:31 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	static t_list	*list = NULL;
	char			*input;

	if (fd < 0 || line == NULL)
		return (-1);
	if (!list)
	{
		if ((input = ft_read(fd)))
		{
			list = ft_lstrsplit(input, '\n');
			free(input);
		}
		else
			return (-1);
	}
	if (list)
	{
		*line = ft_strdup(list->content);
		ft_lstdelpropre(&list);
		if (!list)
			return (0);
		return (1);
	}
	return (-1);
}

char	*ft_read(int const fd)
{
	char	*buffer;
	char	*input;
	char	*tmp;
	int		octets_lus;
	int		len;

	len = 0;
	input = (char*)malloc(1);
	*input = '\0';
	buffer = (char*)malloc(BUFF_SIZE + 1);
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, BUFF_SIZE + 1);
	while ((octets_lus = read(fd, buffer, BUFF_SIZE)))
	{
		tmp = input;
		if (octets_lus == -1)
			return (NULL);
		buffer[octets_lus] = 0;
		input = ft_strjoin(tmp, buffer);
		ft_bzero(buffer, BUFF_SIZE + 1);
		free(tmp);
	}
	free(buffer);
	return (input);
}
