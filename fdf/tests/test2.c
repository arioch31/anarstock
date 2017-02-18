/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 02:45:09 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/02/18 03:56:00 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		draw_img(t_window *w)
{
	int		i;
	int		mult;

	mult = w->large * w->height;
	i = -1;
	while (++i < mult)
		draw_point(w->img[i], w);
	return (0);
}

int		clear_img(t_window *w)
{
	int		i;
	int		mult;

	mult = w->large * w->height;
	i = -1;
	while (++i < mult)
		w->img[i]->color = 0;
	return (0);
}

void	zoom_plus(t_window *w)
{
	int		i;
	int		mult;

	mult = w->large * w->height;
	i = -1;
	while (++i < mult)
	{
		w->img[i]->color += i % 256 * 0x00000001;
	}
//	draw_img(w);
	ft_putendl("zoom+ ok!");
}

void	zoom_moins(t_window *w)
{
	int		i;
	int		mult;

	mult = w->large * w->height;
	i = -1;
	while (++i < mult)
	{
		w->img[i]->color = degrade(i, mult, 0, 0x00FFFFFF);
	}
	ft_putendl("zoom- ok!");
}

t_window		*win_init(void)
{
	void		*screen;
	t_window	*w;
	int			i;
	int			mult;

	w = malloc(sizeof(t_window));
	w->mlx = NULL;
	w->screen = NULL;
	w->large = W_LARGE;
	w->height = W_HEIGHT;
	mult = w->large * w->height;

	w->img = malloc(sizeof(t_2dpt*) * mult);
	i = -1;
	while (++i < mult)
		w->img[i] = new_2dpt(i % w->large, i / w->large, i * 0x00000001);
	w->mlx = mlx_init();
	w->screen = mlx_new_window(w->mlx, W_LARGE, W_HEIGHT, "windobe");
	draw_img(w);
	mlx_key_hook(w->screen, &key_dispatch, w);
	mlx_loop(w->mlx);
	return (w);
}
