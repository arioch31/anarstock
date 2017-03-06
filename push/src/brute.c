/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 01:13:08 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/05/27 23:02:39 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_controleur	*brute(t_controleur *parent, size_t it_max)
{
	t_controleur	*c;
	int				i;
	int				j;

	if (parent->nb_op + parent->lb_len >= it_max)
		return (destr_c(&parent));
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
			if ((TAB_F[i](j++, c)) && (c = brute(c, it_max)))
				return (c);
			else if (c)
				destr_c(&c);
		}
	}
	return (destr_c(&parent));
}

t_controleur	*monobrute(t_controleur *parent, size_t it_max)
{
	t_controleur	*c;
	int				i;

	if (parent->nb_op >= it_max)
	{
		destr_c(&parent);
		return (NULL);
	}
	if (pile_triee(parent->la, 1))
		return (parent);
	c = NULL;
	i = 4;
	while (--i > 0)
	{
		if (!c)
			c = copie_c(parent);
		if ((TAB_F[i](1, c)) && (c = monobrute(c, it_max)))
			return (c);
		else if (c)
			destr_c(&c);
	}
	destr_c(&parent);
	return (NULL);
}