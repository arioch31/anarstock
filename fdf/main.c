/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 20:32:05 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/06/28 22:58:25 by aeguzqui         ###   ########.fr       */
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
		ft_putendl("test ext");
		ptr2 = (t_list*)ptr->content;
		/*
		while (ptr2)
		{
			ft_putendl("test int");
			ft_putstr((char*)ptr2->content);
			ft_putendl("test int2");
			ft_putchar(' ');
			ptr2 = ptr2->next;
		}
		ft_putchar('\n');
*/
	ft_lstaff(ptr2);
		ptr = ptr->next;
	}
}

int		main(int ac, char **av)
{
	int		fd;
	int		nb_rows;
	char	*line;
	t_list	*map;
	t_list	*list;

	line = NULL;
	list = NULL;
	nb_rows = 0;
	if (ac != 2 || !(fd = open(av[1], O_RDONLY)))
		return (0);
	while ((get_next_line(fd, &line)))
	{
		ft_putendl(line);
		if (!nb_rows)
			nb_rows = nb_words(line, ' ');
		if (nb_rows != nb_words(line, ' '))
			return (0);
		map = ft_lstrsplit(line, ' ');
		ft_lstaff(map);
		ft_lstapp(&list, ft_lstnew(map, sizeof(t_list*)));
	}
	ft_putendl("test");
	aff_grid(list);
	return (0);
}
