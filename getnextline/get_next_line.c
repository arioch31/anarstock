/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:31:55 by aeguzqui          #+#    #+#             */
/*   Updated: 2015/12/21 15:31:34 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static unsigned int	len_line(const char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

t_list				*ft_linesplit(const char *str)
{
	t_list			*list;
	t_list			*elem;
	unsigned int	i;
	unsigned int	n;

	list = NULL;
	if (!str)
		return (NULL);
	i = 0;
	while (i < ft_strlen(str))
	{
		n = len_line(&str[i]);
		elem = ft_lstnew(ft_strsub(str, i, n), n);
		ft_lstapp(&list, elem);
		i += n;
		if (n == 0)
			i++;
	}
	return (list);
}

int					get_next_line(int const fd, char **line)
{
	static t_list	*list = NULL;
	t_list			*ptr;
	char			*input;

	if (!list)
	{
		if ((input = ft_read(fd)))
		{
			list = ft_linesplit(input);
			ft_lstaff(list);
			if (!list)
				return (-1);
		}
		else
			return (0);
	}
	if (list)
	{
		*line = ft_strdup(list->content);
		ptr = list->next;
		free(list->content);
		free(list);
		list = ptr;
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
			return (NULL);// gerer ces erreurs plus haut?
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
		free(input);
	}
	i = 0;
	while (i < oct_lus)
	{
		tmp[i + ln - oct_lus] = buffer[i];
		i++;
	}
	return (tmp);
}
