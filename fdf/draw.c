/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 03:00:23 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/03/15 01:59:49 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_3d.h"
#include "fdf.h"
#include <stdio.h>

int		out_screen(t_2dpt *pt, t_window *w)
{
	int	x;
	int	y;
	int ret;

	x = pt->x + w->center->x;
	y = pt->y + w->center->y;
	ret = 0;
	if (x < 0)
		ret += 8;
	if (y < 0)
		ret += 1;
	if (x > w->large)
		ret += 4;
	if (y > w->height)
		ret += 2;
	return (ret);
}

int		draw_point(t_2dpt *pt, t_window *w)
{
	int		locat;
	char	*ptr;

	if (out_screen(pt, w))
	{
		locat = w->img->size_line * (pt->y + w->center->y)
		+ (pt->x + w->center->x - 1) * w->img->bits_per_pixel / 8;
		ptr = w->img->start + locat;
		*ptr = (char)(pt->color / 0x00100000);
		*(++ptr) = (char)((pt->color % 0x00100000) / 0x001000);
		*(++ptr) = (char)((pt->color % 0x001000) / 0x0010);
		*(++ptr) = (char)(pt->color % 0x0010);
		return (1);
	}
	return (0);
}

void	get_next_pt(t_2dpt *p1, t_2dpt *p2, t_2dpt *pt, t_window *w)
{
	double	a;
	int		dev;
	int		dx;
	int		dy;

	dx = p2->x - p1->x;
	dy = p2->y - p1->y;
	if (dx && dy && ((a = fabs((double)dy / (double)dx))))
	{
		if (a > 1)
			dev = abs(dy / 2);
		else
			dev = dx / 2;
	}
	if (!dx)
		while (pt->y != p2->y)
		{
			draw_point(pt, w);
			pt->y += (dy > 0 ? 1 : -1);
		}
	else if (!dy)
		while (pt->x != p2->x)
		{
			draw_point(pt, w);
			pt->x++;
		}
	else
		while (!(pt->x == p2->x && pt->y == p2->y))
		{
			draw_point(pt, w);
			if (a == 1)
			{
				pt->x++;
				pt->y += (dy > 0 ? 1 : -1);
			}
			else if (a < 1)
			{
				pt->x++;
				dev += abs(dy);
				if (dev >= dx)
				{
					dev -= dx;
					pt->y += (dy > 0 ? 1 : -1);
				}
			}
			else
			{
				pt->y += (dy > 0 ? 1 : -1);
				dev += dx;
				if (dev >= abs(dy))
				{
					dev -= abs(dy);
					pt->x++;
				}
			}
		}
}

void	draw_line(t_2dpt *p1, t_2dpt *p2, t_window *w)
{
	t_2dpt	*pt;

	if (!out_screen(p1, w) || !out_screen(p1, w)
	|| !(out_screen(p1, w) && out_screen(p2, w)))
	{
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
}
