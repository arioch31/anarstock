/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 03:00:23 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/07/25 05:41:14 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_3d.h"

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
	if (visible(pt, w))
	{
		mlx_pixel_put(w->mlx, w->screen, pt->x, pt->y, pt->color);
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
	double	flg;

	dx = p2->x - p1->x;
	dy = p2->y - p1->y;
	if (dx && ((a = (double)dy / (double)dx)))
	{
		if ((flg = fabs(a)) && flg > 1)
			dev = dy / 2;
		else
			dev = dx / 2;
	}
	while (!(pt->x == p2->x && pt->y == p2->y))
	{
		draw_point(pt, w);
		if (!dx)
			pt->y += (dy > 0 ? 1 : -1);
		else if (!dy)
			pt->x++;
		else if (flg < 1)
		{
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
			pt->y += (dy > 0 ? 1 : -1);
			dev += dx;
			if (dev >= dy)
			{
				dev -= dy;
				pt->x++;
			}
		}
	}
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
