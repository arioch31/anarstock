/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:31:55 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/01/09 17:50:15 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	static t_list	*list = NULL;
	t_list			*ptr;
	char			*input;

	if (fd < 0 || line == NULL)
		return (-1);
	if (!list)
	{
		if ((input = ft_read(fd)))
			list = ft_lstrsplit(input, '\n');
		else
			return (-1);
	}
	if (list)
	{
		*line = ft_strdup(list->content);
		ptr = list->next;
		free(list->content);
		free(list);
		list = ptr;
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
	int		octets_lus;
	int		len;

	len = 0;
	input = (char*)malloc(1);
	*input = '\0';
	buffer = (char*)malloc(BUFF_SIZE + 1);
	if (!buffer)
		return (NULL);
	while ((octets_lus = read(fd, buffer, BUFF_SIZE)))
	{
		if (octets_lus == -1)
			return (NULL);
		buffer[octets_lus] = 0;
		input = ft_strjoin(input, buffer);
		ft_bzero(buffer, BUFF_SIZE + 1);
	}
	free(buffer);
	return (input);
}
