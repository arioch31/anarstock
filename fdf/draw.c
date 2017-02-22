/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 03:00:23 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/02/22 23:56:43 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_3d.h"
#include <stdio.h>

int		visible(t_2dpt *pt, t_window *w)
{
	if (pt->x < 0 || pt->y < 0)
		return (0);
	if (pt->x < w->large && pt->y < w->height)
		return (1);
	return (0);
}

int		draw_point(t_2dpt *pt, t_window *w)
{
	int		locat;
	char	*ptr;

	if (visible(pt, w))
	{
		locat = w->img->size_line * pt->y + pt->x * w->img->bits_per_pixel / 8;
		ptr = w->img->start + locat;
		*ptr = (char)(pt->color / 0x00100000);
		*(++ptr) = (char)((pt->color % 0x00100000) / 0x001000);
		*(++ptr) = (char)((pt->color % 0x001000) / 0x0010);
		*(++ptr) = (char)(pt->color % 0x0010);
		return (1);
	}
	return (0);
}

void	get_next_pt(t_2dpt *p1, t_2dpt *p2, t_2dpt *pt, t_window *w) //CACACACACACACCACACACACACACACACACACACACACAACAC
{
	double	a;
	int		dev;
	int		dx;
	int		dy;
	double	flg;

	ft_putendl("test in");

	dx = p2->x - p1->x;
	dy = p2->y - p1->y;
	if (dx && dy && ((a = (double)dy / (double)dx)))
	{
		if ((flg = fabs(a)) && flg > 1)
			dev = dy / 2;
		else
			dev = dx / 2;
	}
	while (!(pt->x == p2->x && pt->y == p2->y))
	{
		ft_putendl("test boucle in");

		draw_point(pt, w);
		if (!dx)
		{
			ft_putendl("test boucle in 1");

			pt->y += (dy > 0 ? 1 : -1);
		}
		else if (!dy)
		{
			ft_putendl("test boucle in2");
			pt->x++;
		}
		else if (flg < 1)
		{
			ft_putendl("test boucle in3");

			pt->x++;
			dev += dy;
			if (dev >= dx)
			{
				dev -= dx;
				pt->y += (dy > 0 ? 1 : -1);
			}
		}
		else
		{
			printf("(%d,%d)=>(%d,%d)\n", p1->x, p1->y, p2->x, p2->y);
			printf("test boucle in (%d,%d) %d\n", pt->x, pt->y, dev);
			pt->y += (dy > 0 ? 1 : -1);
			dev += dx;
			if (abs(dev) >= abs(dy))
			{
				dev -= dy;
				pt->x++;
			}
			getchar();
		}
	}
	ft_putendl("test out");
}

void	draw_line(t_2dpt *p1, t_2dpt *p2, t_window *w)
{
	t_2dpt	*pt;

	if (p2->x < p1->x)
	{
		pt = new_2dpt(p2->x, p2->y, p1->color);
		get_next_pt(p2, p1, pt, w);
		free(pt);
	}
	else
	{
		pt = new_2dpt(p1->x, p1->y, p1->color);
		get_next_pt(p1, p2, pt, w);
		free(pt);
	}
}
