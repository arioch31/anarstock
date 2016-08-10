/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 01:03:43 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/08/10 02:29:44 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	magicrasse(t_list *elem)
{
	int		*trou;

	trou = malloc(sizeof(int));
	*trou = ft_atoi((char*)elem->content);
	free(elem->content);
	elem->content = (void*)trou;
	elem->content_size = sizeof(int);
}

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
			if (ptr2->content_size == sizeof(int))
				ft_putnbr(*(int*)ptr2->content);
			else
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
		magicrasse(*map);
		ft_lstapp(&(grille->grid), ft_lstnew(map, sizeof(t_list**)));
		grille->lines++;
	}
	return (grille);
}
