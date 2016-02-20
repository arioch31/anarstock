/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 01:13:08 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/20 19:13:38 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		solver(t_controleur *c)
{
	size_t test;
	size_t cpt;

	if (!c->lb && pile_triee(c->la))
		return (1);
	cpt = 0;
	if ((test = get_sublength(c->la->next, *(int*)c->la->content, 1)))
	{
		ps_swap(1, c);
		while (++cpt < test)
		{
			ps_rot(1, c);
			ps_swap(1, c);
		}
		while (--cpt > 1)
			ps_revrot(1, c);
		return (solver(c));
	}
	ps_revrot(1, c);
	return (solver(c));
}

int		solverv2(t_controleur *c)
{
	size_t test;
	size_t cpt;

	aff_pile(c->la);
	ft_putchar('\n');
	aff_pile(c->lb);
	ft_putchar('\n');
	if (!c->lb && pile_triee(c->la))
		return (1);
	if (pile_triee(c->la) && pile_triee(c->lb))
	{
		while (c->lb)
			ps_push(2, c);
		return (solverv2(c));
	}
	cpt = 0;
	if ((test = get_sublength(c->la->next, *(int*)c->la->content, 1)))
	{
		ps_swap(1, c);
		while (++cpt < test)
		{
			ps_rot(1, c);
			ps_swap(1, c);
		}
		while (--cpt > 1)
			ps_revrot(1, c);
		return (solverv2(c));
	}
	if (c->lb_len > 1 \
		&& (test = get_sublength(c->lb->next, *(int*)c->lb->content, 1)))
	{
		ps_swap(2, c);
		while (++cpt < test)
		{
			ps_rot(2, c);
			ps_swap(2, c);
		}
		while (--cpt > 1)
			ps_revrot(2, c);
		return (solverv2(c));
	}
	if (*(int*)c->la->content < c->val_m)
	{
		ps_push(1, c);
		return (solverv2(c));
	}
	if (c->lb_len > 1)
		ps_revrot(3, c);
	else
		ps_revrot(1, c);
	return (solverv2(c));
}
