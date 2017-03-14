/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 23:47:26 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/03/14 00:36:16 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exiter(void)
{
	ft_putendl("escape ok!");
	exit(0);
}

void	zoom_plus(void *p)
{
	t_grid	*gr;

	gr = (t_grid*)p;
	scale_matrix(gr->camera, 1.1);
	refresh(p);
}

void	zoom_minus(void *p)
{
	t_grid	*gr;

	gr = (t_grid*)p;
	scale_matrix(gr->camera, 0.9);
	refresh(p);
}

void	move_up(void *p)
{
	t_grid	*gr;
	t_3dvec	up = {0, 1, 0};

	gr = (t_grid*)p;
	translate_matrix(gr->camera, &up);
	refresh(p);
}

void	move_down(void *p)
{
	t_grid	*gr;
	t_3dvec	down = {0, -1, 0};

	gr = (t_grid*)p;
	translate_matrix(gr->camera, &down);
	refresh(p);
}

void	move_left(void *p)
{
	t_grid	*gr;
	t_3dvec	left = {1, 0, 0};

	gr = (t_grid*)p;
	translate_matrix(gr->camera, &left);
	refresh(p);
}

void	move_right(void *p)
{
	t_grid	*gr;
	t_3dvec	right = {-1, 0, 0};

	gr = (t_grid*)p;
	translate_matrix(gr->camera, &right);
	refresh(p);
}

int		key_dispatch(int keycode, void *param)
{
	if (keycode == 53)
		exiter();
	else if (keycode == 69)
		zoom_plus(param);
	else if (keycode == 78)
		zoom_minus(param);
	else if (keycode == 126)
		move_up(param);
	else if (keycode == 125)
		move_down(param);
	else if (keycode == 123)
		move_left(param);
	else if (keycode == 124)
		move_right(param);
	else
	{
		refresh(param);
		ft_putnbr(keycode);
		ft_putchar('\n');
	}
	return (0);
}
