/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 01:13:08 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/03/15 05:32:10 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char			cancel(t_controleur *c)
{
	char	op;

	op = *c->last_op;
	*c->last_op = 0;
	c->last_op--;
	CTAB_F[(int)op](c);
	return (op);
}

void			acter(t_controleur *c, int i)
{
	if (i == 0)
		ps_swap(1, c);
	if (i == 1)
		ps_push(1, c);
	if (i == 2)
		ps_rot(1, c);
	if (i == 3)
		ps_rot(2, c);
	if (i == 4)
		ps_rot(3, c);
	if (i == 5)
		ps_swap(3, c);
	if (i == 6)
		ps_revrot(3, c);
	if (i == 7)
		ps_revrot(2, c);
	if (i == 8)
		ps_revrot(1, c);
	if (i == 9)
		ps_push(2, c);
	if (i == 10)
		ps_swap(2, c);
}

t_controleur	*rewind(t_controleur *c, int nb_op)
{
	while (nb_op--)
	{
		cancel(c);
	}
	return (c);
}

/*
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
		while (++i < 11)
		{
			acter(i, parent);
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
}*/

t_controleur	*brute(t_controleur *parent, size_t it_max)
{
	t_controleur	*c;
	int				i;
	int				j;

	if (parent->nb_op + parent->lb_len >= it_max)
	{
//		aff_journal(parent);
//		ft_putendl("fin de branche");
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
//	ft_putnbr(parent->nb_op);
//	ft_putendl("\tfin d'un noeud");
	destr_c(&parent);
	return (NULL);
}

t_controleur	*monobrute(t_controleur *parent, size_t it_max)
{
	t_controleur	*c;
	int				i;

	if (parent->nb_op >= it_max)
	{
//		aff_journal(parent);
//		ft_putendl("");
//		ft_putendl("fin de branche");
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
//	ft_putnbr(parent->nb_op);
//	ft_putendl("\tfin d'un noeud");
	destr_c(&parent);
	return (NULL);
}
