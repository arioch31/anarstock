/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canceler.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 01:13:08 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/03/07 18:28:45 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	c_pa(t_controleur *c)
{
	c->la_len++;
	c->lb_len--;
	push_piler(&(c->lb), &(c->la));
}

void	c_pb(t_controleur *c)
{
	push_piler(&(c->la), &(c->lb));
	c->la_len--;
	c->lb_len++;
}

void 	c_ra(t_controleur *c)
{
	revrot_pile(&(c->la));
}

void	c_rb(t_controleur *c)
{
	revrot_pile(&(c->lb));
}

void	c_rr(t_controleur *c)
{
	revrot_pile(&(c->la));
	revrot_pile(&(c->lb));
}

void	c_rra(t_controleur *c)
{
	rot_pile(&(c->la));
}

void	c_rrb(t_controleur *c)
{
	rot_pile(&(c->lb));
}

void	c_rrr(t_controleur *c)
{
	rot_pile(&(c->la));
	rot_pile(&(c->lb));
}

void 	c_sa(t_controleur *c)
{
	swap_pile(&(c->la));
}

void 	c_sb(t_controleur *c)
{
	swap_pile(&(c->lb));
}

void 	c_ss(t_controleur *c)
{
	swap_pile(&(c->la));
	swap_pile(&(c->lb));
}