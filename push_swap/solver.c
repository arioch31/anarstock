/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 01:13:08 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/25 19:00:01 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		solver(t_controleur *c)
{
	size_t test;
	size_t cpt;

	if (!c->lb && pile_triee(c->la, 1))
		return (1);
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

void	mover(t_controleur *c)
{
	size_t test;
	size_t test2;
	size_t cpt;
	size_t r1;
	size_t r2;

	cpt = 0;
	r1 = 0;
	r2 =0;
	if (c->la_len > 1)
		test = get_sublength(c->la->next, *(int*)c->la->content, 1);
	if (c->lb_len > 1)
		test2 = get_sublength(c->lb->next, *(int*)c->lb->content, 0);
	if (!test2)
	{
		ps_swap(1, c);
		while (++cpt < test)
		{
			ps_rot(1, c);
			ps_swap(1, c);
		}
		while (--cpt > 1)
			ps_revrot(1, c);
	}
	else if (!test)
	{
		ps_swap(2, c);
		while (++cpt < test2)
		{
			ps_rot(2, c);
			ps_swap(2, c);
		}
		while (--cpt > 1)
			ps_revrot(2, c);
	}
	else
	{
		ps_swap(3, c);
		while (++cpt < test && cpt < test2)
		{
			ps_rot(3, c);
			ps_swap(3, c);
			r1++;
			r2++;
		}
		while (++cpt < test)
		{
			ps_rot(1, c);
			ps_swap(1, c);
			r1++;
		}
		while (++cpt < test2)
		{
			ps_rot(2, c);
			ps_swap(2, c);
			r2++;
		}
		while (--r1 > 1 && --r2 > 1)
			ps_revrot(3, c);
		while (--r1 > 1)
			ps_revrot(1, c);
		while (--r2 > 1)
			ps_revrot(2, c);
		

	}	
}

int		solverv2(t_controleur *c)
{
	size_t test;
	size_t cpt;

	if (!c->lb && pile_triee(c->la, 1))
		return (1);
	if (pile_triee(c->la, 1) && pile_triee(c->lb, 0))
	{
		while (c->lb_len)
			ps_push(2, c);
		return (solverv2(c));
	}
	if (*(int*)c->la->content < c->val_m && !pile_triee(c->la))
	{
		ps_push(1, c);
		return (solverv2(c));
	}
	
	cpt = 0;
	if (c->la_len > 1 \
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
		return (solverv2(c));
	}
	if (c->lb_len > 1 \
		&& (test = get_sublength(c->lb->next, *(int*)c->lb->content, 0)))
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
	ps_revrot(1, c);
	if (c->lb_len > 1 && !pile_triee(c->lb, 0))
		ps_revrot(2, c);
	return (solverv2(c));
}

int		solverv3(t_controleur *c)
{
	if (!c->lb && pile_triee(c->la, 1))
		return (1);
	if (pile_triee(c->la, 1) && pile_triee(c->lb, 0))
	{
		while (c->lb)
			ps_push(2, c);
		return (solverv3(c));
	}
	if (*(int*)c->la->content > *(int*)c->la->next->content)
	{
		ps_swap(1, c);
	}
	if (*(int*)c->la->content < c->val_m)
	{
		ps_push(1, c);
		return (solverv3(c));
	}
	return (solverv3(c));
}
