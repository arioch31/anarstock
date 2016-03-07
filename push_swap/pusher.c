/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 04:47:51 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/03/07 18:37:49 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_piler(t_list **l1, t_list **l2)
{
	t_list	*ptr;

	ptr = (*l1)->next;
	(*l1)->next = *l2;
	*l2 = *l1;
	*l1 = ptr;
}

int		ps_swap(int cible, t_controleur *c)
{
	if (cible == 1 && c->la_len > 1 && (!c->last_op || !(*(c->last_op) == SA)))
	{
		swap_pile(&(c->la));
		return (ad_op(c, SA));
	}
	else if (cible == 2 && c->lb_len > 1 \
		&& (!c->last_op || !(*(c->last_op) == SB)))
	{
		swap_pile(&(c->lb));
		return (ad_op(c, SB));
	}
	else if (cible == 3 && c->la_len > 1 && c->lb_len > 1 \
		&& (!c->last_op || !(*c->last_op == SS)))
	{
		swap_pile(&(c->la));
		swap_pile(&(c->lb));
		return (ad_op(c, SS));
	}
	return (0);
}

int		ps_push(int cible, t_controleur *c)
{
	if (cible == 1 && c->la_len && (!c->last_op || !(*c->last_op == PB)))
	{
		push_piler(&(c->la), &(c->lb));
		c->la_len--;
		c->lb_len++;
		return (ad_op(c, PA));
	}
	else if (cible == 2 && c->lb_len && (!c->last_op || !(*c->last_op == PA)))
	{
		c->la_len++;
		c->lb_len--;
		push_piler(&(c->lb), &(c->la));
		return (ad_op(c, PB));
	}
	return (0);
}

int		ps_rot(int cible, t_controleur *c)
{
	if (cible == 1 && c->la_len > 1 && (!c->last_op || (!(*c->last_op == RRA) \
		&& !(*c->last_op == RRR))))
	{
		rot_pile(&(c->la));
		return (ad_op(c, RA));
	}
	else if (cible == 2 && c->lb_len > 1 \
		&& (!c->last_op || (!(*c->last_op == RRB) && !(*c->last_op == RRR))))
	{
		rot_pile(&(c->lb));
		return (ad_op(c, RB));
	}
	else if (cible == 3 && c->la_len > 1 && c->lb_len > 1\
		&& ((!c->last_op || *c->last_op > RRA || *c->last_op < RRR)))
	{
		rot_pile(&(c->la));
		rot_pile(&(c->lb));
		return (ad_op(c, RR));
	}
	return (0);
}

int		ps_revrot(int cible, t_controleur *c)
{
	if (cible == 1 && c->la_len > 1 && (!c->last_op || (!(*c->last_op == RA) \
		&& !(*c->last_op == RR))))
	{
		revrot_pile(&(c->la));
		return (ad_op(c, RRA));
	}
	else if (cible == 2 && c->lb_len > 1 \
		&& (!c->last_op || (!(*c->last_op == RB) && !(*c->last_op == RR))))
	{
		revrot_pile(&(c->lb));
		return (ad_op(c, RRB));
	}
	else if (cible == 3 && c->la_len > 1 && c->lb_len > 1\
		&& ((!c->last_op || *c->last_op < RA || *c->last_op > RR)))
	{
		revrot_pile(&(c->la));
		revrot_pile(&(c->lb));
		return (ad_op(c, RRR));
	}
	return (0);
}
