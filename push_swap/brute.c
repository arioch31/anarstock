/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 01:13:08 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/20 18:34:55 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_controleur	*test(t_controleur *p, t_fpile *tab, size_t it_max)
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
	ft_putstr("nb op :\t");
 	ft_putnbr(c->nb_op);
 	ft_putstr("\nlast op :\t");
 	ft_putendl(c->last_op);
	i= 0;
	while (i < 4)
	{
		j = 1;
		while (j < 4)
		{
			ft_putstr("test");
			ft_putnbr(i);
			ft_putnbr(j);
			if (!c)
				c = copie_c(p);
			if ((tab[i](j++, c)) && brute(c, it_max))
				return(c);
			ft_putstr("ok");

		}
		i++;
		ft_putchar('\n');
	}
	return (NULL);
}

t_controleur	*brute(t_controleur *parent, size_t it_max)
{
	t_fpile 	tab[] = {ps_swap, ps_rot, ps_revrot, ps_push};

	if (parent->nb_op >= it_max)
	{
		destr_c(&parent);
		return (NULL);
	}
	if (!parent->lb && pile_triee(parent->la))
		return (parent);
	if (test(parent, tab, it_max))
		return (parent);
	return(NULL);
}
