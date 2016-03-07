/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 01:13:08 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/03/07 18:28:45 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
int				rewind(t_controleur *c)
{

}

t_controleur	*opti_brute(t_controleur *parent, size_t it_max)
{
	int				i;
	int				j;
	t_controleur	fils;

	if (!parent)
		return (NULL);
	while (1)
	{
		i = -1;
		while (++i < 4)//changer ca
		{
			j = 1;
			while (j < 4)//ca aussi
			{
				TAB_F[i](j++, parent);
				if (parent->nb_op + parent->lb_len >= it_max)
					return (NULL); //rewind(parent)?
				//condition de sortie ok
				if (!parent->lb && pile_triee(parent->la, 1))
				{
					if (!(fils = opti_brute(copie_c(parent), parent->nb_op)))
						return (parent);
					else
						return (fils);
				}
			}
		}
	}
}
*/

t_controleur	*brute(t_controleur *parent, size_t it_max)
{
	t_controleur	*c;
	int				i;
	int				j;

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
			if ((TAB_F[i](j++, c)) && (c = brute(c, it_max)))
				return (c);
			else if (c)
				destr_c(&c);
		}
	}
	destr_c(&parent);
	return (NULL);
}

t_controleur	*monobrute(t_controleur *parent, size_t it_max)
{
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
	while (++i < 4)
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
