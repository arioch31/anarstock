/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 00:06:59 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/11/16 03:20:49 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exiter(void)
{
	ft_putendl("escape ok!");
	exit(0);
}

void	zoom_plus(void)
{
	ft_putendl("zoom+ ok!");
}

int		key_dispatch(int keycode, void *param)
{
	if (keycode == 53)
		exiter();
	else if (keycode == 69)
		zoom_plus();
	else
	{
		ft_putnbr(keycode);
		ft_putchar('\n');
	}
	return (0);
}

void	draw_grid(t_window *w, t_grid *gr)
{
	int i;

	i = 0;
	while (i < gr->rows * gr->lines)
	{
		gr->l_2dpts[i]->x = gr->l_3dpts[i]->x * 10;
		gr->l_2dpts[i]->y = gr->l_3dpts[i]->y * 10;
		draw_point(gr->l_2dpts[i], w);
		if (i % gr->rows)
			draw_line(gr->l_2dpts[i - 1], gr->l_2dpts[i], w);
		if (i > gr->rows)
			draw_line(gr->l_2dpts[i - gr->rows], gr->l_2dpts[i], w);
		i++;
	}
}

void	upd_grid(t_window *w, t_grid *gr)
{
	int		i;
	t_3dpt	*pt;
	double	*mat;

	i = 0;
	mat = mult_matrix(w->mat_cam, w->mat_proj);
	print_matrix(mat);
	while (i < gr->rows * gr->lines)
	{
		pt = matrix_point(mat, gr->l_3dpts[i]);
		free(gr->l_3dpts[i]);
		gr->l_3dpts[i] = pt;
		i++;
	}
	i = 0;
	while (i < gr->rows * gr->lines)
	{
		print_3dpt(gr->l_3dpts[i]);
		i++;
	}
}

int		test(t_grid *gr)
{
	void		*ptr;
	void		*screen;
	t_window	*w;
	t_3dpt		*camera;

	ptr = mlx_init();
	w = malloc(sizeof(t_window));
	screen = mlx_new_window(ptr, W_LARGE, W_HEIGHT, "windobe");
	w->mlx = ptr;
	w->screen = screen;
	w->large = W_LARGE;
	w->height = W_HEIGHT;
	ft_putendl("test ");
	camera = new_3dpoint(0, 0, 0);
	w->mat_cam = new_matrix();
	translate_matrix(w->mat_cam, new_vector(camera, NULL));
	w->mat_proj = proj_matrix(60.0, (640.0 / 480), 1.0, 100.0);
	print_matrix(w->mat_cam);
	print_matrix(w->mat_proj);
	upd_grid(w, gr);
	draw_grid(w, gr);
	mlx_key_hook(w->screen, &key_dispatch, w->mlx);
	mlx_loop(w->mlx);
	return (0);
}
