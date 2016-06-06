/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ruche.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 21:45:38 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/06/07 00:44:57 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		delim_ruche(t_ruche *ruche)
{
	t_list	*ptr;
	t_salle	*salle;

	if (ruche->start == ruche->end)
		return (1);
	ptr = ruche->list_salles;
	while (ptr)
	{
		if ((salle->utile == 2 || salle->utile == 3) && !salle->liens)
			return (0);
		salle = *(t_salle**)ptr->content;
		if (!salle->liens || (salle->utile == 1 && !salle->liens->next))
			salle->utile = 0;
		ptr = ptr->next;
	}
	return (test_shortpath(ruche));
}

void	next_step(t_ruche *ruche, t_salle *current)
{
	t_list	*ptr;
	t_salle	*ptr_salle;

	ptr = current->liens;
	while (ptr)
	{
		ptr_salle = *(t_salle**)ptr->content;
		if (ptr_salle->utile % 2 && (!ptr_salle->dist_start
			|| ptr_salle->dist_start > current->dist_start))
		{
			ptr_salle->dist_start = current->dist_start + 1;
			next_step(ruche, ptr_salle);
		}
		if (ptr_salle == ruche->end)
			ptr = NULL;
		else
			ptr = ptr->next;
	}
}

void	addstep_short(t_ruche *ruche, t_salle *current)
{
	t_list	*ptr;
	t_salle	*ptr_salle;

	ptr = current->liens;
	while (ptr)
	{
		ptr_salle = *(t_salle**)ptr->content;
		if (ptr_salle->dist_start == current->dist_start - 1)
		{
			ft_lstadd(&(ruche->short_path),
				ft_lstnew(&ptr_salle, sizeof(t_salle*)));
			addstep_short(ruche, ptr_salle);
			ptr = NULL;
		}
		else
			ptr = ptr->next;
	}
}

int		test_shortpath(t_ruche *ruche)
{
	t_list	*short_path;

	short_path = NULL;
	next_step(ruche, ruche->start);
	if (ruche->end->dist_start)
	{
		ruche->short_path = ft_lstnew(&(ruche->end), sizeof(t_salle*));
		addstep_short(ruche, ruche->end);
	}
	return (ruche->end->dist_start);
}
