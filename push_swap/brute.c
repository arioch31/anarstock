/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 01:13:08 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/15 04:53:58 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
t_controleur	*last_p(t_controleur *p, t_fpile *tab, int origin, int it_max)
{
	t_controleur 	*c;
	int 			i;
	int 			j;

	c = copie_c(p);
	if ((tab[0](origin, c)) && brute(c, it_max))
		return (c);
	i= 1;
	while (i < 4)
	{
		j = 1;
		while (j < 4)
		{
			if (!c)
			c = copie_c(p);
			if ((tab[i](j++, c)) && brute(c, it_max))
				return(c);
		}
		i++;
	}
	return (NULL);
}

t_controleur	*last_s(t_controleur *p, t_fpile *tab int it_max)
{
	t_controleur 	*c;
	int 			i;
	int 			j;

	c = copie_c(p);
	if ((tab[0](1, c)) && brute(c, it_max))
		return (c);
	if (!c)
	c = copie_c(p);
	if ((tab[0](2, c)) && brute(c, it_max))
		return (c);
	i= 2;
	while (i < 4)
	{
		j = 1;
		while (j < 4)
		{
			if (!c)
				c = copie_c(p);
			if ((tab[i](j++, c)) && brute(c, it_max))
				return(c);
		}
		i++;
	}
	return (NULL);
}
*/

t_controleur	*test(t_controleur *p, t_fpile *tab, int it_max)
{
	t_controleur 	*c;
	int 			i;
	int 			j;

	c = copie_c(p);
   ft_putendl("\n============================");
	ft_putendl("état des piles :");
	aff_pile(c->la);
	ft_putchar('\n');
	aff_pile(c->lb);
	ft_putstr("\nop journal:\t");
 	ft_putendl(c->op_j);
 	ft_putstr("\nlast op :\t");
 	ft_putendl(c->last_op);
	ft_putstr("test\n");

	i= 0;
	while (i < 4)
	{
		j = 1;
		while (j < 4)
		{
			if (!c)
				c = copie_c(p);
			if ((tab[i](j++, c)) && brute(c, it_max))
				return(c);
		}
		i++;
	}
	return (NULL);
}

t_controleur	*brute(t_controleur *parent, size_t it_max)
{
	t_fpile 	tab[] = {ps_swap, ps_rot, ps_revrot, ps_push};

	if (parent->nb_op >= it_max)
	{
		destr_c(parent);
		return (NULL);
	}
	if (!parent->lb && pile_triee(parent->la))
		return (parent);
	if (!test(parent, tab, it_max))
		destr_c(parent);
	else
		return (parent);
	return(NULL);
}