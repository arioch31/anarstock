/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 22:46:06 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/06/07 00:32:52 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	is_used(t_list *path, t_salle *salle)
{
	t_list	*ptr;
	t_salle	*ptr_salle;

	ptr = path;
	while (ptr)
	{
		ptr_salle = *(t_salle**)ptr->content;
		if (ptr_salle == salle)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

/*
int	explore(t_ruche *ruche, t_salle *current, t_list *path)
{
	if (current == ruche->end)
		return (1);
}

int	pathfinder(t_ruche *ruche)
{
	return (ruche->end->dist_start);
}
*/
