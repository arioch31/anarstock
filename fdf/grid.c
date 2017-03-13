/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 01:03:43 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/03/13 22:45:29 by aeguzqui         ###   ########.fr       */
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
	int		z;

	z = *(int*)ptr->content;
	truc = new_2dpt((i % rows + z / 2) * 50, (i / rows + z / 2) * 50,
	0XFFFF00 * (1 + z));
	free(ptr->content);
	ptr->content = (void*)truc;
	ptr->content_size = sizeof(t_2dpt);
}

void	magicrasse3(t_list *ptr, int i, int rows)
{
	t_3dpt	*truc;

	truc = new_3dpoint(i % rows, i / rows, *(int*)ptr->content);
	free(ptr->content);
	ptr->content = (void*)truc;
	ptr->content_size = sizeof(t_3dpt);
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
			magicrasse3(p2, i, gr->rows);
		else
			gr->rect = 0;
		i++;
	}
}

void	aff_grid(t_list *data)
{
	t_list	*ptr;
	t_list	*ptr2;
	t_2dpt	*pt_2d;

	ptr = data;
	while (ptr)
	{
		ptr2 = *(t_list**)ptr->content;
		while (ptr2)
		{
			print_point(ptr2);
			ft_putchar('\t');
			ptr2 = ptr2->next;
		}
		ft_putchar('\n');
		ptr = ptr->next;
	}
}

t_2dpt	*proj_pt(t_3dpt *pt)
{
	t_2dpt *ret;

	ret = new_2dpt(pt->x, pt->y, -1);
	free(pt);
	return (ret);
}

t_2dpt	*get_2dpt(t_grid *gr, t_list *p)
{
	t_2dpt	*p2d;
	t_3dpt	*p3d;

	if (p->content_size == sizeof(t_2dpt))
		return (as_2dpt(p, 1));
	if (p->content_size == sizeof(t_3dpt))
	{
		p3d = as_3dpt(p, 1);
		p3d = matrix_point(gr->camera, p3d);
		p2d = new_2dpt(p3d->x, p3d->y, 0XFFFFFF00);
		return (p2d);
	}
	return (NULL);
}

void	draw_grid(t_grid *gr)
{
	int		i;
	t_list	*p1;
	t_list	*p2;
	t_list	*p3;

	i = 0;
	p1 = gr->data;
	p2 = *(t_list**)p1->content;
	while (i < gr->rows * gr->lines)
	{
		if ((p1 = ft_lstgetnb(gr->data, i / gr->rows + 1))
		&& ((p2 = *(t_list**)p1->content))
		&& ((p2 = ft_lstgetnb(p2, i % gr->rows + 1))))
		{
			if ((p3 = p2->next))
				draw_line(get_2dpt(gr, p3), get_2dpt(gr, p2), gr->w);
			if (((p3 = p1->next))
			&& ((p3 = *(t_list**)p3->content))
			&& ((p3 = ft_lstgetnb(p3, i % gr->rows + 1))))
				draw_line(get_2dpt(gr, p3), get_2dpt(gr, p2), gr->w);
		}
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
