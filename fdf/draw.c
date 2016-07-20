/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 03:00:23 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/07/20 06:26:30 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_3d.h"

int		visible(t_2dpt *pt, t_window *w)
{
	if (pt->x < w->large && pt->y < w->height)
		return (1);
	return (0);
}

void	draw_point(t_2dpt *pt, t_window *w)
{
	if (visible(pt, w))
		mlx_pixel_put(w->mlx, w->screen, pt->x, pt->y, pt->color);
}

void	get_next_pt(t_2dpt *p1, t_2dpt *p2)
{
	if (p1->x == p2->x)
	{
		if (p1->y < p2->y)
			p1->y++;
		else
			p1->y--;
	}
	else if (p1->y == p2->y)
		p1->x++;
	else if (p1->y < p2->y)
	{
		tralalalapouetpouet();
	}
}

void	draw_line(t_2dpt *p1, t_2dpt *p2, t_window *w)
{
	t_2dpt	*pt;

	if (p2->x < p1->x)
		draw_line(p2, p1);
	else if (visible(p1, w) && visible(p2, w))
	{
		pt = new_2dpt(p1->x, p1->y, p1->color);
		draw_point(pt);
		while (pt->x <= p2->x && pt->y != p2->y)
		{
			draw_point(pt);
		}
		free(pt);
	}
}
