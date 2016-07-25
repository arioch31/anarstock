/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 00:06:59 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/07/25 05:41:13 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_3d.h"

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

int		main(void)
{
	void		*ptr;
	void		*screen;
	t_window	*w;

	t_2dpt		*pt1;
	t_2dpt		*pt2;
	t_2dpt		*pt3;
	t_2dpt		*pt4;

	ptr = mlx_init();
	pt1 = new_2dpt(-400, -400, 0x0000FF00);
	pt2 = new_2dpt(400, 800, 0x000000FF);
	pt3 = new_2dpt(800, 400, 0x00FF0000);
	pt4 = new_2dpt(800, 800, 0x00FFFFFF);

	w = malloc(sizeof(t_window));
	screen = mlx_new_window(ptr, 1600, 900, "windowstinks");
	w->mlx = ptr;
	w->screen = screen;
	w->large = 1600;
	w->height = 900;
	draw_point(pt1, w);
	draw_point(pt2, w);
	draw_point(pt3, w);
	draw_point(pt4, w);

	draw_line(pt1, pt2, w);
	draw_line(pt2, pt3, w);
	draw_line(pt3, pt1, w);

	draw_line(pt2, pt4, w);
	draw_line(pt3, pt4, w);
	draw_line(pt4, pt1, w);

	mlx_key_hook(w->screen, &key_dispatch, w->mlx);
	mlx_loop(w->mlx);











/*	t_3dpt		*p1;
	t_3dpt		*p2;
	t_3dpt		*orig;
	t_3dvec	*v1;
	t_3dvec	*v2;
	double	*m0;
	double	*m1;
	double	*m2;
*/
	/*
		p1 = new_3dpoint(8.0, 8.0, 8.0);
		print_3dpt(p1);
		p2 = new_3dpoint(18.0, 18.0, 18.0);
		print_3dpt(p2);
		orig = new_3dpoint(0.00, 0.0, 0.0);
		v1 = new_vector(p2, p1);
		v2 = new_vector(p2, orig);
		print_3dvec(v1);
		print_3dvec(v2);

		ft_putendl("v1 normé:");
		print_3dvec(norm_vector(v1));

		ft_putendl("v1 * 4:");
		print_3dvec(mult_3dvec(v1, 4.0));

		ft_putendl("v1 - v2:");
		print_3dvec(sub_vector(v1, v2));

		ft_putstr(" new ");
		m0 = new_matrix();
		print_matrix(m0);

		m1 = rot_matrix(M_PI / 3, 'x');
		ft_putstr(" m1 rot sur x ");
		print_matrix(m1);

		scale_matrix(m1, 3.0);
		ft_putstr(" m1 scale 3 ");
		print_matrix(m1);

		ft_putstr("\np1 ");
		print_3dpt(p1);

		p1 = matrix_point(m0, p1);
		ft_putstr(" p1 * ident ");
		print_3dpt(p1);

		p2 = matrix_point(m1, p1);
		ft_putstr(" p1 * m1 ");
		print_3dpt(p2);


		m2 = proj_matrix(60.0, (640.0 / 480), 1.0, 100.0);
		ft_putstr("\n m2 proj_matrix ");
		print_matrix(m2);

	*/

	return (0);
}
/*
*/
