/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:06:28 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/05/26 02:41:25 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	aff_liens(t_salle *salle)
{
	t_list	*ptr;

	if (salle && salle->liens)
	{
		ft_putstr("liens vers:");
		ptr = salle->liens;
		while (ptr)
		{
			ft_putchar('\t');
			ft_putstr((*(t_salle**)ptr->content)->name);
			ptr = ptr->next;
		}
		ft_putchar('\n');
	}
}

void	aff_salle(t_list *list)
{
	t_salle	*p;

	p = *(t_salle**)list->content;
	ft_putstr("salle :");
	ft_putstr(p->name);
	ft_putstr("\t x= ");
	ft_putnbr(p->coo_x);
	ft_putstr("\t y= ");
	ft_putnbr(p->coo_y);
	ft_putstr("\tutilité: ");
	ft_putnbr(p->utile);
	ft_putchar('\n');
	if (p->liens)
		aff_liens(p);
}

void	aff_ruche(t_ruche *ruche)
{
	ft_putnbr(ruche->nb_fourmis);
	ft_putendl(" fourmis");
	if (ruche->start)
	{
		ft_putstr("start : ");
		ft_putendl(ruche->start->name);
	}
	if (ruche->end)
	{
		ft_putstr("end :");
		ft_putendl(ruche->end->name);
	}
	ft_lstiter(ruche->list_salles, &aff_salle);
}