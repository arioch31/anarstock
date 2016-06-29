/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 20:32:05 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/06/29 00:00:32 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

void	aff_grid(t_list *list)
{
	t_list	*ptr;
	t_list	*ptr2;

	ptr = list;
	while (ptr)
	{
		ptr2 = *(t_list**)ptr->content;
		while (ptr2)
		{
			ft_putstr((char*)ptr2->content);
			ft_putchar('\t');
			ptr2 = ptr2->next;
		}
		ft_putchar('\n');
		ptr = ptr->next;
	}
}

int		main(int ac, char **av)
{
	int		fd;
	int		nb_rows;
	char	*line;
	t_list	**map;
	t_list	*list;

	line = NULL;
	list = NULL;
	nb_rows = 0;
	if (ac != 2 || !(fd = open(av[1], O_RDONLY)))
		return (0);
	while ((get_next_line(fd, &line)))
	{
		map = malloc(sizeof(t_list*));
		if (!nb_rows)
			nb_rows = nb_words(line, ' ');
		if (nb_rows != nb_words(line, ' '))
			return (0);
		*map = ft_lstrsplit(line, ' ');
		ft_lstapp(&list, ft_lstnew(map, sizeof(t_list**)));
	}
	aff_grid(list);
	return (0);
}
