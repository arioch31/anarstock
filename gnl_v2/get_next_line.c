/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:31:55 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/01/15 06:31:08 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	static t_list	*list = NULL;
	t_list			*ptr_list;
	t_str_fd		*s;
	char			*input;
	char			*tmp;
	int				res;

	if (fd < 0 || line == NULL)
		return (-1);
	input = ft_strnew(0);
	if (!list || !(ptr_list = seek_fd(list, fd)))
	{
		if ((res = ft_read(fd, &input)) && res > 0)
		{
			s = crea_s(input, fd);
			ft_lstapp(&list, ft_lstnew(&s, sizeof(s)));
			*line = ft_strsub(input, 0, ft_strseekc(input, '\n'));
		}
		else return (res);
	}
	else
	{
		s = ptr_list->content;
		ft_read(fd, &input);
		tmp = ft_strjoin(s->str, input);
		free(s->str);
		s->str = NULL;
		free(input);
		*line =  ft_strsub(tmp, 0, ft_strseekc(tmp, '\n'));
		if (!*tmp)
		{
			destr_s(s);
			return (0);
		}
		s->str = ft_strsub(tmp, ft_strseekc(tmp, '\n') + 1 , ft_strlen(tmp) -ft_strseekc(tmp, '\n'));
		free(tmp);
	}
	return (1);
}

t_str_fd	*crea_s(char *str, int fd)
{
	t_str_fd	*s;

	s = malloc(sizeof(t_str_fd));
	s->fd = fd;
	
	ft_putendl("creator");
	ft_putstr("aff fd \t");
		ft_putnbr(s->fd);
		ft_putchar('\n');
	ft_putstr("aff s->fd \t");
		ft_putnbr(s->fd);
		ft_putchar('\n');
	
	s->str = ft_strdup(ft_strchr(str, '\n') + 1);
	return (s);
}

void		destr_s(t_str_fd *s)
{
	if (s)
	{
		if (s->str)
		{
			ft_bzero(s->str, ft_strlen(s->str) + 1);
			free(s->str);
		}
		s->fd = 0;
		free(s);
	}
}

t_list	*seek_fd(t_list *start, int fd)
{
	t_list		*ptr;
	t_str_fd	*s;

	ptr = start;
	while (ptr)
	{
		s = ptr->content;
		ft_putendl("seeker:");
		ft_putstr("aff seeked->fd \t");
		ft_putnbr(fd);
		ft_putchar('\n');

		ft_putstr("aff s->fd \t");
		ft_putnbr(s->fd);
		ft_putchar('\n');

		if (s->fd == fd)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
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
