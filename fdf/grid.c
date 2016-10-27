/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 01:03:43 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/10/27 02:39:56 by aeguzqui         ###   ########.fr       */
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
	if (elem->next)
		magicrasse(elem->next);
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
			{
				ft_putstr((char*)ptr2->content);
				ft_putchar('!');
			}
			ft_putchar('\t');
			ptr2 = ptr2->next;
		}
		ft_putchar('\n');
		ptr = ptr->next;
	}
}

int		*trad_grid(t_grid *grille)
{
	t_list	*ptr;
	t_list	*ptr2;
	int		*tab;
	int		i;

	tab = malloc(sizeof(int) * grille->rows * grille->lines);
	i = 0;
	ptr = grille->grid;
	while (ptr)
	{
		ptr2 = *(t_list**)ptr->content;
		while (ptr2)
		{
			if (ptr2->content_size == sizeof(int))
				tab[i] = *(int*)ptr2->content;
			else
				ft_putstr("erreur\t");
			i++;
			ptr2 = ptr2->next;
		}
		ptr = ptr->next;
	}
	return (tab);
}

void	init_3dpts(t_grid *gr)
{
	int		i;
	t_3dpt	*pt;

	i = 0;
	pt = NULL;
	ft_putstr("test\n");
	while (i < gr->rows * gr->lines)
	{
		pt = new_3dpoint(i % gr->rows, i / gr->rows, gr->tab[i]);
		if (i % gr->rows)
			ft_lstapp(&pt->liens, ft_lstgetnb(gr->list_3dpts, i - 1));
		if (i >= gr->rows)
			ft_lstapp(&pt->liens, ft_lstgetnb(gr->list_3dpts, i - gr->rows));
		ft_lstapp(&gr->list_3dpts, ft_lstnew(pt, sizeof(t_3dpt*)));
		i++;
	}
	ft_putstr("test ok!\n");
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
	grille->tab = NULL;
	grille->list_3dpts = NULL;
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
	grille->tab = trad_grid(grille);
	init_3dpts(grille);
	return (grille);
}
