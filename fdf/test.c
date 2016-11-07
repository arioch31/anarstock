/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 00:06:59 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/11/07 21:08:20 by aeguzqui         ###   ########.fr       */
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

void	draw_test(t_window *w, t_grid *gr)
{
	int i;

	i = 0;
	while (i < gr->rows * gr->lines)
	{
		draw_point(gr->l_2dpts[i], w);
		if (i % gr->rows)
			draw_line(gr->l_2dpts[i - 1], gr->l_2dpts[i], w);
		if (i > gr->rows)
			draw_line(gr->l_2dpts[i - gr->rows], gr->l_2dpts[i], w);
		i++;
	}
}

int		test(t_grid *grille)
{
	void		*ptr;
	void		*screen;
	t_window	*w;

	ptr = mlx_init();
	w = malloc(sizeof(t_window));
	screen = mlx_new_window(ptr, W_LARGE, W_HEIGHT, "windowstinks");
	w->mlx = ptr;
	w->screen = screen;
	w->large = W_LARGE;
	w->height = W_HEIGHT;
	draw_test(w, grille);
	mlx_key_hook(w->screen, &key_dispatch, w->mlx);
	mlx_loop(w->mlx);
	return (0);
}
