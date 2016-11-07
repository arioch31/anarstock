/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 01:03:43 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/11/07 21:58:44 by aeguzqui         ###   ########.fr       */
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

void	init_2dpts(t_grid *gr)
{
	int		i;
	t_3dpt	*pt;

	i = 0;
	gr->l_2dpts = malloc(gr->rows * gr->lines * sizeof(t_2dpt*));
	while (i < gr->rows * gr->lines)
	{
		pt = gr->l_3dpts[i];
		gr->l_2dpts[i] = new_2dpt((int)(pt->x + pt->z / 2) * 50, (int)(pt->y + pt->z / 2) * 50, 0x0000FF00);
		i++;
	}
}

void	init_3dpts(t_grid *gr)
{
	int		i;
	t_3dpt	**tab;

	i = 0;
	tab = malloc(gr->rows * gr->lines * sizeof(t_3dpt*));
	while (i < gr->rows * gr->lines)
	{
		tab[i] = new_3dpoint(i % gr->rows, i / gr->rows, gr->tab[i]);
		i++;
	}
	gr->l_3dpts = tab;
}

t_grid	*new_grid(int fd)
{
	char	*line;
	t_list	**map;
	t_grid	*grille;

	grille = malloc(sizeof(t_grid));
	ft_bzero(grille, sizeof(t_grid));
	while ((get_next_line(fd, &line)))
	{
		map = malloc(sizeof(t_list*));
		if (!grille->rows)
			grille->rows = nb_words(line, ' ');
		if (grille->rows != nb_words(line, ' '))
			return (NULL);
		*map = ft_lstrsplit(line, ' ');
		magicrasse(*map);
		ft_lstapp(&(grille->grid), ft_lstnew(map, sizeof(t_list*)));
		grille->lines++;
	}
	grille->tab = trad_grid(grille);
	init_3dpts(grille);
	init_2dpts(grille);
	return (grille);
}
