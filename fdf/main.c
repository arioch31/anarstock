/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 20:32:05 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/08/02 04:35:47 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"
#include "fdf.h"

void	aff_grid(t_grid *grille)
{
	t_list	*ptr;
	t_list	*ptr2;

	ptr = grille->grid;
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

t_grid	*new_grid(int fd)
{
	char	*line;
	t_list	**map;
	t_grid	*grille;

	grille = malloc(sizeof(t_grid));
	line = NULL;
	grille->grid = NULL;
	grille->rows = 0;
	grille->lines = 0;
	while ((get_next_line(fd, &line)))
	{
		map = malloc(sizeof(t_list*));
		if (!grille->rows)
			grille->rows = nb_words(line, ' ');
		if (grille->rows != nb_words(line, ' '))
			return (NULL);
		*map = ft_lstrsplit(line, ' ');
		ft_lstapp(&(grille->grid), ft_lstnew(map, sizeof(t_list**)));
		grille->lines++;
	}
	return (grille);
}

int		main(int ac, char **av)
{
	int		fd;
	t_grid	*grille;

	if (ac != 2 || !(fd = open(av[1], O_RDONLY)))
		return (0);
	grille = new_grid(fd);
	aff_grid(grille);
	return (0);
}
