/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 01:13:08 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/25 18:58:57 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
t_controleur	*opti_brute(t_controleur *parent, size_t it_max)
{


	return (NULL);
}*/

t_controleur	*brute(t_controleur *parent, size_t it_max)
{
	t_fpile			tab[] = {ps_swap, ps_push, ps_rot, ps_revrot};
	t_controleur	*c;
	int				i;
	int				j;

	if (!parent)
		return (NULL);
	if (parent->nb_op + parent->lb_len >= it_max)
	{
		destr_c(&parent);
		return (NULL);
	}
	if (!parent->lb && pile_triee(parent->la, 1))
		return (parent);
	c = NULL;
	i = -1;
	while (++i < 4)
	{
		j = 1;
		while (j < 4)
		{
			if (!c)
				c = copie_c(parent);
			if ((tab[i](j++, c)) && (c = brute(c, it_max)))
				return (c);
			else if (c)
				destr_c(&c);
		}
	}
	if (parent)
		destr_c(&parent);
	return (NULL);
}

t_controleur	*monobrute(t_controleur *parent, size_t it_max)
{
	t_fpile			tab[] = {ps_swap, ps_rot, ps_revrot};
	t_controleur	*c;
	int				i;

	if (parent->nb_op + parent->lb_len >= it_max)
	{
		destr_c(&parent);
		return (NULL);
	}
	if (!parent->lb && pile_triee(parent->la, 1))
		return (parent);
	c = NULL;
	i = 0;
	while (i < 3)
	{
		if (!c)
			c = copie_c(parent);
		if ((tab[i](1, c)) && (c = monobrute(c, it_max)))
			return (c);
		else if (c)
			destr_c(&c);
		i++;
	}
	destr_c(&parent);
	return (NULL);
}
