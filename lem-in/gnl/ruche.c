/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ruche.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 21:45:38 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/05/26 01:55:31 by aeguzqui         ###   ########.fr       */
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
	return (2);
}
