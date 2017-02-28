/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 20:32:05 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/02/28 02:53:49 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		test_bis(t_window *w, int i)
{
	t_2dpt *p1;
	t_2dpt *p2;
	t_2dpt *p3;

	p1 = new_2dpt(i * 10, 0, 0x00FF0101);
	p2 = new_2dpt(w->large / 2, w->height / 2, 0X00FFFFFF);
	draw_point(p2, w);
	draw_line(p1, p2, w);
	p3 = new_2dpt(w->large / 3 * 2, 0, 0X00AAAAAA);
	draw_line(p3, p2, w);
	draw_line(p3, p1, w);
	free(p1);
	free(p2);
	free(p3);
	return (1);
}

int		refresh(void *ptr)
{
	t_window	*w;

	w = ((t_grid*)ptr)->w;
	bzero(w->img->start, w->img->bits_per_pixel * W_LARGE * W_HEIGHT / 8);
	draw_2dpts(ptr);
	mlx_put_image_to_window(w->mlx, w->screen, w->img->addr, 0, 0);
	return (1);
}

t_window	*new_window(void)
{
	t_window	*w;

	w = malloc(sizeof(t_window));
	w->img = malloc(sizeof(t_img));
	w->mlx = mlx_init(); //EXIT_FAILURE
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
	static int	i = 0;
	t_img		*img;
	t_window	*w;

	w = ((t_grid*)p)->w;
	img = w->img;
	bzero(img->start, img->bits_per_pixel * W_LARGE * W_HEIGHT / 8);
	test_bis(w, ++i);
	refresh(p);
	ft_putendl("zoom+ ok!");
}

int		key_dispatch(int keycode, void *param)
{
	if (keycode == 53)
		exiter();
	else if (keycode == 69)
		zoom_plus(param);
//	else if (keycode == 78)
//	{
	//		testtttttt(param);
//	}
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
	t_grid	*grille;
	double	*mat_proj;

	if (ac != 2 || !(fd = open(av[1], O_RDONLY)))
		return (0);
	grille = new_grid(fd);
	aff_grid(grille);
	init_3dpts(grille);
	aff_grid(grille);
	test(grille);
	return (0);
}
