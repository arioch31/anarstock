/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 01:03:43 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/02/28 03:22:06 by aeguzqui         ###   ########.fr       */
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
	t_2dpt	*truc;

//	truc = new_3dpoint(i % rows, i / rows, *(int*)ptr->content);
	truc = new_2dpt((i % rows + *(int*)ptr->content / 3) * 50,
	 (i  / rows - *(int*)ptr->content / 3) * 50, 0X00FF00FF);
	free(ptr->content);
	ptr->content = (void*)truc;
	ptr->content_size = sizeof(t_2dpt);
}

void	aff_grid(t_grid *grille)
{
	t_list	*ptr;
	t_list	*ptr2;
	t_2dpt	*pt_2d;
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
			else if (ptr2->content_size == sizeof(t_2dpt))
				{
				pt_2d = (t_2dpt*)ptr2->content;
					ft_putnbr(pt_2d->x);
					ft_putchar(',');
					ft_putnbr(pt_2d->y);
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

void	draw_2dpts(t_grid *gr)
{
	int		i;
	t_list	*p1;
	t_list	*p2;
	t_list	*p3;

	i = 0;
	p1 = gr->data;
	p2 = *(t_list**)p1->content;
	while ((p1 = ft_lstgetnb(gr->data, i / gr->rows + 1))
		&& ((p2 = *(t_list**)p1->content))
		&& ((p2 = ft_lstgetnb(p2, i % gr->rows + 1))))
		{
			if ((p3 = p2->next))
				draw_line(as_2dpt(p3, 1), as_2dpt(p2, 1), gr->w);
			if (((p3 = p1->next))
			&& ((p3 = *(t_list**)p3->content))
			&& ((p3 = ft_lstgetnb(p3, i % gr->rows + 1))))
				draw_line(as_2dpt((p3), 1), as_2dpt(p2, 1), gr->w);
			i++;
		}
}

void	init_3dpts(t_grid *gr)
{
	int		i;
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
		{
			magicrasse2(p2, i, gr->rows);
		}
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
	close(fd);
	return (grille);
}
