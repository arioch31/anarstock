/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 01:03:43 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/02/27 05:55:58 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

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

void	magicrasse2(t_list *ptr, int i, int rows)
{
	t_3dpt	*truc;

	truc = new_3dpoint(i % rows, i / rows, *(int*)ptr->content);
	free(ptr->content);
	ptr->content = (void*)truc;
	ptr->content_size = sizeof(t_3dpt);
}

void	aff_grid(t_grid *grille)
{
	t_list	*ptr;
	t_list	*ptr2;
	t_3dpt	*point;

	ptr = grille->data;
	while (ptr)
	{
		ptr2 = *(t_list**)ptr->content;
		while (ptr2)
		{
			if (ptr2->content_size == sizeof(int))
				ft_putnbr(*(int*)ptr2->content);
			else if (ptr2->content_size == sizeof(t_3dpt))
			{
				point = (t_3dpt*)ptr2->content;
				ft_putnbr((int)point->x);
				ft_putchar(',');
				ft_putnbr((int)point->y);
				ft_putchar(',');
				ft_putnbr((int)point->z);
			}
			else
				ft_putstr("pb elem");
			ft_putchar('\t');
			ptr2 = ptr2->next;
		}
		ft_putchar('\n');
		ptr = ptr->next;
	}
}

void	init_3dpts(t_grid *gr)
{
	int		i;
	t_3dpt	**tab;
	t_list	*p1;
	t_list	*p2;

	i = 0;
	p1 = gr->data;
	p2 = *(t_list**)p1->content;
	while (i < gr->rows * gr->lines && p1)
	{
		if ((p1 = ft_lstgetnb(gr->data, i / gr->rows + 1))
		&& ((p2 = *(t_list**)p1->content))
		&& ((p2 = ft_lstgetnb(p2, i % gr->rows + 1))))
			magicrasse2(p2, i, gr->rows);
		else
			gr->rect = 0;
		i++;
	}
}

t_grid	*new_grid(int fd)
{
	char	*line;
	t_list	**map;
	t_grid	*grille;

	line = NULL;
	map = malloc(sizeof(t_list*));
	grille = malloc(sizeof(t_grid));
	ft_bzero(grille, sizeof(t_grid));
	grille->rect = 1;
	while ((get_next_line(fd, &line)))
	{
		*map = ft_lstrsplit(line, ' ');
		free(line);
		if (!grille->rows || grille->rows < ft_lstlen(*map))
			grille->rows = ft_lstlen(*map);
		magicrasse(*map);
		ft_lstapp(&(grille->data), ft_lstnew(map, sizeof(t_list*)));
		grille->lines++;
	}
	init_3dpts(grille);
	close(fd);
	return (grille);
}
