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

t_controleur	*brute(t_controleur *parent, size_t it_max)
{
	t_fpile 	tab[] = {ps_swap, ps_revrot, ps_rot, ps_push};
	t_controleur 	*c;
	int 			i;
	int 			j;


	if (!parent)
		return (NULL);
	if (parent->nb_op + parent->lb_len >= it_max)
	{
		destr_c(&parent);
		return (NULL);
	}
	if (!parent->lb && pile_triee(parent->la))
		return (parent);
	c = NULL;
	i= 0;
	while (i < 4)
	{
		j = 1;
		while (j < 4)
		{
			if (!c)
				c = copie_c(parent);
			if ((tab[i](j++, c)) && (c = brute(c, it_max)))
				return(c);
			else if (c)
				destr_c(&c);
		}
		i++;
	}
	destr_c(&parent);
	return(NULL);
}
