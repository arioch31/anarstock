/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 02:45:09 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/11/16 07:38:54 by aeguzqui         ###   ########.fr       */
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

void	exiter(void)
{
	ft_putendl("escape ok!");
	exit(0);
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
	}	ft_putendl("zoom- ok!");
}

int		key_dispatch(int keycode, void *param)
{
	t_window	*w;

	w = (t_window*)param;
	if (keycode == 53)
		exiter();
	else if (keycode == 69)
		zoom_plus(w);
	else if (keycode == 78)
		zoom_moins(w);
	else
	{
		ft_putnbr(keycode);
		ft_putchar('\n');
	}
	draw_img(w);
	return (0);
}

int		win_init(t_window *w)
{
	void		*screen;

	w->mlx = mlx_init();
	w->screen = mlx_new_window(w->mlx, W_LARGE, W_HEIGHT, "windobe");
	draw_img(w);
	mlx_key_hook(w->screen, &key_dispatch, w);
	mlx_loop(w->mlx);
	return (0);
}

int		main(void)
{
	int			i;
	int			mult;
	t_window	*w;

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
	win_init(w);
	return (0);
}
