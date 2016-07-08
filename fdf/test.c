/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 00:06:59 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/07/08 07:15:27 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <unistd.h>
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
	t_point		*p1;
	t_point		*p2;
	t_point		*orig;
	t_vector	*v1;
	t_vector	*v2;
	t_matrix	*m0;
	t_matrix	*m1;
	t_matrix	*m2;

	p1 = new_point(8.0, 8.0, 8.0);
	print_point(p1);
	p2 = new_point(18.0, 18.0, 18.0);
	print_point(p2);
	orig = new_point(0.00, 0.0, 0.0);
	v1 = new_vector(p2, p1);
	v2 = new_vector(p2, orig);
	print_vector(v1);
	print_vector(v2);
	ft_putendl("v1 normé:");
	print_vector(norm_vector(v1));
	ft_putendl("v1 * 4:");
	print_vector(mult_vector(v1, 4.0));
	ft_putendl("v1 - v2:");
	print_vector(sub_vector(v1, v2));
	ft_putendl("jusque la, ca marche:");
	ft_putstr(" new ");
	m0 = new_matrix();
	print_matrix(m0);
	ft_putstr(" new ");
	m0 = new_matrix();
	print_matrix(m0);
	m1 = rot_matrix(M_PI / 3, 'x');
	ft_putstr(" m1 ");
	print_matrix(m1);
	ft_putstr(" m0 ");
	print_matrix(m0);
	ft_putstr(" m1 ");
	print_matrix(m1);
	ft_putendl("et la, c deja la foire... ");

	m2 = rot_matrix(M_PI / 3, 'y');
	ft_putstr(" m2 ");
	print_matrix(m2);
	ft_putstr(" m1 * ident ");
	print_matrix(mult_matrix(m1, m0));
	ft_putstr(" m1 * m2 ");
	print_matrix(mult_matrix(m1, m2));
	ft_putstr(" m0 * m0 ");
	print_matrix(mult_matrix(m0, m0));



	/*
	ptr = mlx_init();
	screen = mlx_new_window(ptr, 1000, 1000, "windowstinks");
	mlx_key_hook(screen, &key_dispatch, ptr);
	mlx_loop(ptr);
	*/
	return (0);
}
/*
**https://gist.github.com/KokaKiwi/4052375
*/
