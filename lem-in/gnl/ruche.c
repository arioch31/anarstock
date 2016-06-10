/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ruche.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 21:45:38 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/06/10 19:30:38 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		trim_ruche(t_ruche *ruche)
{
	t_list	*ptr;
	t_salle	*salle;
	int		ret;

	ret = 0;
	ptr = ruche->list_salles;
	while (ptr)
	{
		salle = *(t_salle**)ptr->content;
		if (salle->utile == 1 && nb_vliaisons(salle) < 2)
		{
			salle->utile = 0;
			ret = 1;
		}
		ptr = ptr->next;
	}
	return (ret);
}

int		delim_ruche(t_ruche *ruche)
{
	t_list	*ptr;
	t_salle	*salle;

	if (!ruche->start->liens || !ruche->end->liens)
		return (0);
	if (ruche->start == ruche->end)
		return (1);
	while (trim_ruche(ruche))
		;
	next_step(ruche, ruche->start);
	ptr = ruche->list_salles;
	while (ptr)
	{
		salle = *(t_salle**)ptr->content;
		if (!salle->dist_start && salle != ruche->start)
			salle->utile = 0;
		ptr = ptr->next;
	}
	if (ruche->end->dist_start)
	{
		ruche->short_path = ft_lstnew(&(ruche->end), sizeof(t_salle*));
		addstep_short(ruche, ruche->end);
	}
	return (ruche->end->dist_start);
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
			|| ptr_salle->dist_start > current->dist_start + 1))
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

t_ruche	*init_ruche(void)
{
	t_ruche	*ruche;

	ruche = malloc(sizeof(t_ruche));
	ruche->list_salles = NULL;
	ruche->start = NULL;
	ruche->end = NULL;
	ruche->map_paths = NULL;
	return (ruche);
}
