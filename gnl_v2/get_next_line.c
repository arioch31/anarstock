/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:31:55 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/01/12 17:33:13 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	static t_list	*slist = NULL;
	t_list			*new_list;
	t_list			*list;
	char			*input;
	int				res;

	if (fd < 0 || line == NULL)
		return (-1);
	input = malloc(1);
	*input = '\0';
	if (!slist || !seek_fd(slist, fd))
	{
		if ((res = ft_read(fd, &input)) && res > 0 )
		{
			list = ft_lstrsplit(input, '\n');
			free(input);
	ft_lstaff(list);
			new_list = ft_lstnew(list, sizeof(list));
			ft_lstapp(&slist, new_list);
			new_list->content_size = (unsigned int)fd;
		}
		else return (res);
	}
	list = seek_fd(slist, fd);
	ft_putendl(list->content);
	ft_putendl("test");
	*line = ft_strdup(list->content);
	if (list)
		ft_lstdelpropre(&list);
	return (1);
}

t_list	*seek_fd(t_list *start, int fd)
{
	t_list	*ptr;

	ptr = start;
	while (ptr)
	{
		if (ptr->content_size == (unsigned int)fd)
			return (ptr->content);
		ptr = ptr->next;
	}
	return (NULL);
}

int	ft_read(int const fd, char **input)
{
	char	*buffer;
	char	*tmp;
	int		octets_lus;
	int		len;

	len = 0;
	**input = '\0';
	buffer = (char*)malloc(BUFF_SIZE + 1);
	if (!buffer)
		return (-1);
	ft_bzero(buffer, BUFF_SIZE + 1);
	while ((octets_lus = read(fd, buffer, BUFF_SIZE)))
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
	return (1);
}
