/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:06:28 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/09 22:56:44 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	aff_salle(t_list *list)
{
	t_salle	*p;

	p = *(t_salle**)list->content;
	ft_putendl(p->name);
	ft_putnbr(p->coo_x);
	ft_putchar('\t');
	ft_putnbr(p->coo_y);
	ft_putstr("\nutilité: ");
	ft_putnbr(p->utile);
	ft_putchar('\n');
}

void aff_ruche(t_ruche *ruche)
{
	ft_putnbr(ruche->nb_fourmis);
	ft_putendl(" fourmis");
	ft_lstiter(ruche->list_salles, &aff_salle);
}