/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:31:55 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/01/08 08:57:38 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					get_next_line(int const fd, char **line)
{
	static t_list	*list = NULL;
	t_list			*ptr;
	char			*input;
	if (fd < 0 || line == NULL)
		return (-1);
	if (!list)
	{
		if ((input = ft_read(fd)))
		{
			list = ft_lstrsplit(input,'\n');
		}
		else
			return (-1);
	}
	if (list)
	{
		*line = ft_strdup(list->content);
		ptr = list->next;
//		if (list->content)
			free(list->content);
		free(list);
		list = ptr;
		if (!list)
			return(0);
		return (1);
	}
	return (-1);
}

char				*ft_read(int const fd)
{
	char	*buffer;
	char	*input;
	int		octets_lus;
	int		len;

	len = 0;
	input = NULL;
	buffer = (char*)malloc(BUFF_SIZE + 1);
	if (!buffer)
		return (NULL);
	while ((octets_lus = read(fd, buffer, BUFF_SIZE)))
	{
		if (octets_lus == -1)
			return (NULL);
		len += octets_lus;
		input = larg_input(input, buffer, len, octets_lus);
		input[len] = '\0';
	}
	free(buffer);
	return (input);
}

char				*larg_input(char *input, char *buffer, int ln, int oct_lus)
{
	char	*tmp;
	int		i;

	tmp = (char*)malloc(ln + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	if (input)
	{
		while (i < ln - oct_lus)
		{
			tmp[i] = input[i];
			i++;
		}
		//free(input);
	}
	i = 0;
	while (i < oct_lus)
	{
		tmp[i + ln - oct_lus] = buffer[i];
		i++;
	}
	return (tmp);
}
