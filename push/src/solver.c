/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 01:13:08 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/05/11 22:20:31 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		solver(t_controleur *c)
{
	size_t test;
	size_t cpt;

	if (!c->lb && pile_triee(c->la, 1))
		return (c->nb_op);
	cpt = 0;
	if (c->la_len > 2 \
		&& (test = get_sublength(c->la->next, *(int*)c->la->content, 1)))
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

int		mover(t_controleur *c, int cible)
{
	size_t test;
	size_t cpt;

	cpt = 0;
	test = 0;
	if (!cible && c->la_len > 2)
		test = get_sublength(c->la->next, *(int*)c->la->content, 1);
	else if (cible && c->lb_len > 2)
		test = get_sublength(c->lb->next, *(int*)c->lb->content, 0);
	if (test)
	{
		ps_swap(1 + cible, c);
		while (++cpt < test)
		{
			ps_rot(1 + cible, c);
			ps_swap(1 + cible, c);
		}
		while (--cpt > 1)
			ps_revrot(1 + cible, c);
	}
	return (test);
}

int		solverv2(t_controleur *c)
{
	if (!c->lb && pile_triee(c->la, 1))
		return (c->nb_op);
	if (pile_triee(c->la, 1) && pile_triee(c->lb, 0) \
		&& *(int*)c->la->content > *(int*)c->lb->content)
	{
		while (c->lb)
			ps_push(2, c);
		return (solverv2(c));
	}
	if (*(int*)c->la->content < c->val_m)
	{
		ps_push(1, c);
		return (solverv2(c));
	}
	if (mover(c, 0) || mover(c, 1))
		return (solverv2(c));
	if (!pile_triee(c->la, 1))
		ps_revrot(1, c);
	if (!pile_triee(c->lb, 0))
		ps_revrot(2, c);
	return (solverv2(c));
}

int		solverv3(t_controleur *c)
{
	if (!c->lb && pile_triee(c->la, 1))
		return (c->nb_op);
	if (pile_triee(c->la, 1) && pile_triee(c->lb, 0)\
		&& *(int*)c->la->content > *(int*)c->lb->content)
	{
		while (c->lb)
		{
			push_piler(&(c->lb), &(c->la));
			c->lb_len--;
			c->la_len++;
			ad_op(c, PB);
		}
		return (solverv3(c));
	}
	while (c->la_len > 1 && !pile_triee(c->la, 1))
	{
		if (rank(c->la, *(int*)c->la->content) == 1)
			ps_push(1, c);
		else if (c->la_len - get_length(get_ranker(c->la, 1)) < c->la_len / 2)
			ps_rot(1, c);
		else
			ps_revrot(1, c);
	}
	return (solverv3(c));
}