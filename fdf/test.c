/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 00:06:59 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/08/10 01:03:02 by aeguzqui         ###   ########.fr       */
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

int		test(t_grid *grille)
{
	void		*ptr;
	void		*screen;
	t_window	*w;
	t_3dpt		*p3t1;
	t_2dpt		*pt1;
	t_3dpt		*p3t2;
	t_2dpt		*pt2;

	ptr = mlx_init();
	w = malloc(sizeof(t_window));
	screen = mlx_new_window(ptr, W_LARGE, W_HEIGHT, "windowstinks");
	w->mlx = ptr;
	w->screen = screen;
	w->large = W_LARGE;
	w->height = W_HEIGHT;
	p3t1 = new_3dpoint(8.0, 0.0, 0.0);
	pt1 = new_2dpt((int)p3t1->x, (int)p3t1->y, 0x0000FF00);
	p3t2 = new_3dpoint(108.0, 800.0, 0.0);
	pt2 = new_2dpt((int)p3t2->x, (int)p3t2->y, 0x0000FF00);
	draw_point(pt1, w);
	draw_line(pt1, pt2, w);
	mlx_key_hook(w->screen, &key_dispatch, w->mlx);
	mlx_loop(w->mlx);
	return (0);
}

int		main(int ac, char **av)
{
	int		fd;
	t_grid	*grille;

	if (ac != 2 || !(fd = open(av[1], O_RDONLY)))
		return (0);
	grille = new_grid(fd);
	aff_grid(grille);
	test(grille);
	return (0);
}
