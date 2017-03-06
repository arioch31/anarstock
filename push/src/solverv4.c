/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solverv4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 00:24:44 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/05/27 23:36:54 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		dist_tominmax(t_controleur *c)
{
	int d_min;
	int d_max;

	d_min = get_length(get_ranker(c->la, c->rank_min_la));
	d_max = get_length(get_ranker(c->la, c->rank_max_la));
	if (!((int)c->la_len - d_min) || !((int)c->la_len - d_max))
		return (0);
	if (d_min < (int)c->la_len - d_min)
		d_min = -d_min;
	else
		d_min = (int)c->la_len - d_min;
	if (d_max < (int)c->la_len - d_max)
		d_max = -d_max;
	else
		d_max = (int)c->la_len - d_max;
	if (VAL_ABS(d_max) > VAL_ABS(d_min))
		return (d_min);
	else
		return (d_max);
}

void	sendback(t_controleur *c)
{
	int		cpt;

	while (c->lb)
		ps_push(2, c);
	cpt = get_length(get_ranker(c->la, 1));
	if (cpt < (int)c->length - cpt)
		while (cpt--)
			ps_rot(1, c);
	else
		while (cpt++ < (int)c->length)
			ps_revrot(1, c);
}

void	setfirstminormax(t_controleur *c)
{
	int		cpt;

	cpt = dist_tominmax(c);
	while (cpt)
	{
		if (cpt < 0)
		{
			cpt++;
			ps_revrot(1, c);
		}
		else
		{
			cpt--;
			ps_rot(1, c);
		}
	}
}

int		solverv4(t_controleur *c)
{
	while (!pile_triee(c->la, 1))
	{
		setfirstminormax(c);
		if (get_ranker(c->la, c->rank_max_la) == c->la)
		{
			ps_push(1, c);
			c->rank_max_la--;
			if (c->lb_len > 1)
				ps_rot(2, c);
		}
		else if (!pile_triee(c->la, 1) \
			&& get_ranker(c->la, c->rank_min_la) == c->la)
		{
			ps_push(1, c);
			c->rank_min_la++;
		}
	}
	sendback(c);
	return (c->nb_op);
}
