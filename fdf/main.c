/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 20:32:05 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/03/08 04:07:48 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		refresh(void *ptr)
{
	t_window	*w;

	w = ((t_grid*)ptr)->w;
	bzero(w->img->start, w->img->bits_per_pixel * W_LARGE * W_HEIGHT / 8);
	draw_grid(ptr);
	mlx_put_image_to_window(w->mlx, w->screen, w->img->addr, 0, 0);
	return (1);
}

int		clear_img(void *ptr)
{
	t_window	*w;

	w = ((t_grid*)ptr)->w;
	bzero(w->img->start, w->img->bits_per_pixel * W_LARGE * W_HEIGHT / 8);
	mlx_put_image_to_window(w->mlx, w->screen, w->img->addr, 0, 0);
	return (1);
}

t_window	*new_window(void)
{
	t_window	*w;

	w = malloc(sizeof(t_window));
	w->img = malloc(sizeof(t_img));
	w->mlx = mlx_init();
	w->screen = mlx_new_window(w->mlx, W_LARGE, W_HEIGHT, "windobe");
	w->large = W_LARGE;
	w->height = W_HEIGHT;
	w->center = new_2dpt(W_LARGE / 2, W_HEIGHT / 2, 0xFF0000);
	w->img->addr = mlx_new_image(w->mlx, w->large, w->height);
	w->img->start = mlx_get_data_addr(w->img->addr, &(w->img->bits_per_pixel),
	&(w->img->size_line), &(w->img->endian));
	return (w);
}

void	exiter(void)
{
	ft_putendl("escape ok!");
	exit(0);
}

void	zoom_plus(void *p)
{
	refresh(p);
	ft_putendl("zoom+ ok!");
}

int		key_dispatch(int keycode, void *param)
{
	if (keycode == 53)
		exiter();
	else if (keycode == 69)
		clear_img(param);
	else
	{
		refresh(param);
		ft_putnbr(keycode);
		ft_putchar('\n');
	}
	return (0);
}

int		test(t_grid *gr)
{
	gr->w = new_window();
	mlx_expose_hook(gr->w->screen, &refresh, gr);
	mlx_key_hook(gr->w->screen, &key_dispatch, gr);
	mlx_loop(gr->w->mlx);
	return (0);
}

int		main(int ac, char **av)
{
	int		fd;
	int		*tab;
	int		i;
	t_obj	*obj;
	t_grid	*gr;
	double	*mat_proj;

	if (ac != 2 || !(fd = open(av[1], O_RDONLY)))
		return (0);
	gr = new_grid(fd);
	aff_grid(gr->data);
	init_3dpts(gr);
	ft_putendl("init_2dpt!");
	aff_grid(gr->data);
	ft_putendl("init obj!");
	obj = create_obj();
	fill_obj(gr, obj);
	debug_obj(obj);
	free_obj(obj);
//	gr->camera = proj_matrix(60, 16.0 / 9, 1, 100);
//	print_matrix(gr->camera);
//	test(gr);
	return (0);
}
