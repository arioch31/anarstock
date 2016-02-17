/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 01:13:08 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/15 04:53:58 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int 	solver(t_controleur *c)
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
			ps_revrot(1,c);
		return(solver(c));
	}
	ps_revrot(1, c);
	return (solver(c));
}
//	if (c->op_l[ft_strlen(op_j) - 2] == 's')


t_controleur	*brute(t_controleur *parent, size_t it_max)
{
	t_fpile 	tab[] = {ps_swap, ps_push, ps_rot, ps_revrot};

	if (parent->nb_op >= it_max)
		return (NULL);
//	if (!parent->lb && pile_triee(parent->la))
//		return (parent);
	if (tab[2](1, parent))
		return (parent);
	return (NULL);
}