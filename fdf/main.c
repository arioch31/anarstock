/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 20:32:05 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/02/18 05:35:52 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//
// int		test(t_grid *gr)
// {
// 	void		*ptr;
// 	void		*screen;
// 	t_window	*w;
// 	t_3dpt		*camera;
//
// 	ptr = mlx_init();
// 	w = malloc(sizeof(t_window));
// 	screen = mlx_new_window(ptr, W_LARGE, W_HEIGHT, "windobe");
// 	w->mlx = ptr;
// 	w->screen = screen;
// 	w->large = W_LARGE;
// 	w->height = W_HEIGHT;
// 	ft_putendl("test ");
// 	camera = new_3dpoint(0, 0, 0);
// 	w->mat_cam = new_matrix();
// 	translate_matrix(w->mat_cam, new_vector(camera, NULL));
// 	w->mat_proj = proj_matrix(60.0, (640.0 / 480), 1.0, 100.0);
// 	print_matrix(w->mat_cam);
// 	print_matrix(w->mat_proj);
// 	upd_grid(w, gr);
// 	draw_grid(w, gr);
// 	mlx_key_hook(w->screen, &key_dispatch, w->mlx);
// 	mlx_loop(w->mlx);
// 	return (0);
// }

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
	return (0);
}
