/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 04:31:56 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/07/13 01:20:56 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_3d.h"

void	print_point(t_point *p)
{
	ft_putstr("point:\t x= ");
	ft_putdouble(p->x, 4);
	ft_putstr("\t y= ");
	ft_putdouble(p->y, 4);
	ft_putstr("\t z= ");
	ft_putdouble(p->z, 4);
	ft_putchar('\n');
}

void	print_vector(t_vector *v)
{
	ft_putstr("vecteur:\t x= ");
	ft_putdouble(v->x, 4);
	ft_putstr("\t y= ");
	ft_putdouble(v->y, 4);
	ft_putstr("\t z= ");
	ft_putdouble(v->z, 4);
	ft_putstr("\t magnitude= ");
	ft_putdouble(v->w, 4);
	ft_putchar('\n');
}

void	print_matrix(double *m)
{
	int			i;
	int			j;

	i = -1;
	ft_putendl("matrix:");
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			ft_putdouble(m[i * 4 + j], 4);
			ft_putchar('\t');
		}
		ft_putendl("");
	}
}
