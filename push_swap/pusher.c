/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 04:47:51 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/25 18:35:53 by aeguzqui         ###   ########.fr       */
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
		return (ad_op(c, 0));
	}
	else if (cible == 2 && c->lb_len > 1 \
		&& (!c->last_op || !(*(c->last_op) == SB)))
	{
		swap_pile(&(c->lb));
		return (ad_op(c, 10));
	}
	else if (cible == 3 && c->la_len > 1 && c->lb_len > 1 \
		&& (!c->last_op || !(*c->last_op == SS)))
	{
		swap_pile(&(c->la));
		swap_pile(&(c->lb));
		return (ad_op(c, 5));
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
		return (ad_op(c, 1));
	}
	else if (cible == 2 && c->lb_len && (!c->last_op || !(*c->last_op == PA)))
	{
		c->la_len++;
		c->lb_len--;
		push_piler(&(c->lb), &(c->la));
		return (ad_op(c, 9));
	}
	return (0);
}

int		ps_rot(int cible, t_controleur *c)
{
	if (cible == 1 && c->la_len > 1 && (!c->last_op || (!(*c->last_op == RRA) \
		&& !(*c->last_op == RRR))))
	{
		rot_pile(&(c->la));
		return (ad_op(c, 2));
	}
	else if (cible == 2 && c->lb_len > 1 \
		&& (!c->last_op || (!(*c->last_op == RRB) && !(*c->last_op == RRR))))
	{
		rot_pile(&(c->lb));
		return (ad_op(c, 3));
	}
	else if (cible == 3 && c->la_len > 1 && c->lb_len > 1\
		&& ((!c->last_op || *c->last_op > RRA || *c->last_op < RRR)))
	{
		rot_pile(&(c->la));
		rot_pile(&(c->lb));
		return (ad_op(c, 4));
	}
	return (0);
}

int		ps_revrot(int cible, t_controleur *c)
{
	if (cible == 1 && c->la_len > 1 && (!c->last_op || (!(*c->last_op == RA) \
		&& !(*c->last_op == RR))))
	{
		revrot_pile(&(c->la));
		return (ad_op(c, 8));
	}
	else if (cible == 2 && c->lb_len > 1 \
		&& (!c->last_op || (!(*c->last_op == RB) && !(*c->last_op == RR))))
	{
		revrot_pile(&(c->lb));
		return (ad_op(c, 7));
	}
	else if (cible == 3 && c->la_len > 1 && c->lb_len > 1\
		&& ((!c->last_op || *c->last_op < RA || *c->last_op > RR)))
	{
		revrot_pile(&(c->la));
		revrot_pile(&(c->lb));
		return (ad_op(c, 6));
	}
	return (0);
}