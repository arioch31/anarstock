/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 04:47:51 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/15 04:52:34 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_piler(t_list **l1, t_list **l2)
{
  t_list  *ptr;

  ptr = (*l1)->next;
  (*l1)->next = *l2;
  *l2 = *l1;
  *l1 = ptr;
}

int 	ps_swap(int cible, t_controleur *c)
{
	if (*c->last_op == 's')
		return(0);
	if (cible == 1 && c->la)
	{
		swap_pile(&(c->la));
		return (ad_op(c, "sa"));
	}
	else if(cible == 2 && c->lb)
	{
		swap_pile(&(c->lb));	
		return (ad_op(c, "sb"));
	}
	else if(cible == 3 && c->la && c->lb \
		&& c->la->next && c->lb->next)
	{
		swap_pile(&(c->la));
		swap_pile(&(c->lb));
		return (ad_op(c, "ss"));
	}
	return (0);
}

int		ps_push(int cible, t_controleur *c)
{
	if (cible == 1 && c->la && !ft_strequ("pb", c->last_op))
	{
		push_piler(&(c->la), &(c->lb));
		c->la_len--;
		c->lb_len++;
		return (ad_op(c, "pa"));
	}
	else if(cible == 2 && c->lb && !ft_strequ("pa", c->last_op))
	{
		c->la_len++;
		c->lb_len--;
		push_piler(&(c->lb), &(c->la));
		return (ad_op(c, "pb"));
	}
	return (0);
}

int 	ps_rot(int cible, t_controleur *c)
{

	if (cible == 1 && c->la && !ft_strequ("rra", c->last_op) && !ft_strequ("rrr", c->last_op))
	{
		rot_pile(&(c->la));
		return (ad_op(c, "ra"));
	}
	else if(cible == 2 && c->lb && !ft_strequ("rrb", c->last_op) && !ft_strequ("rrr", c->last_op))
	{
		rot_pile(&(c->lb));	
		return (ad_op(c, "rb"));
	}
else if(cible == 3 && c->la && c->lb \
		&& c->la->next && c->lb->next && !ft_strlen(c->last_op) == 3)
	{
		rot_pile(&(c->la));
		rot_pile(&(c->lb));
		return (ad_op(c, "rr"));
	}
	return (0);
}

int 	ps_revrot(int cible, t_controleur *c)
{
	if (cible == 1 && c->la && !ft_strequ("ra", c->last_op) && !ft_strequ("rr", c->last_op))
	{
		revrot_pile(&(c->la));
		return (ad_op(c, "rra"));
	}
	else if(cible == 2 && c->lb && !ft_strequ("rb", c->last_op) && !ft_strequ("rr", c->last_op))
	{
		revrot_pile(&(c->lb));	
		return (ad_op(c, "rrb"));
	}
	else if(cible == 3 && c->la && c->lb \
		&& c->la->next && c->lb->next && !(ft_strlen(c->last_op) == 2 && *c->last_op == 'r'))
	{
		revrot_pile(&(c->la));
		revrot_pile(&(c->lb));
		return (ad_op(c, "rrr"));
	}
	return (0);
}
