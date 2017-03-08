/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 04:31:56 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/03/08 02:32:24 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_3d.h"

void	print_2dpt(t_2dpt *pt)
{
	ft_putnbr(pt->x);
	ft_putchar(',');
	ft_putnbr(pt->y);
}

void	debug_link(t_list *ptr)
{
	t_link	*lnk;

	lnk = *(t_link**)ptr->content;
	print_2dpt((t_2dpt*)lnk->p1->content);
	ft_putstr(" => ");
	print_2dpt((t_2dpt*)lnk->p2->content);
	ft_putstr("\n");
}

void	print_3dpt(t_3dpt *p)
{
	ft_putstr("point:\t x= ");
	ft_putdouble(p->x, 4);
	ft_putstr("\t y= ");
	ft_putdouble(p->y, 4);
	ft_putstr("\t z= ");
	ft_putdouble(p->z, 4);
	ft_putchar('\n');
}

void	print_3dvec(t_3dvec *v)
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
