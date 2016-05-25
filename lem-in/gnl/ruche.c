/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ruche.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 21:45:38 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/05/25 21:54:59 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		verif_ruche(t_ruche *ruche)
{
	t_list	*ptr;
	t_salle	*salle;

	ptr = ruche->list_salles;
	while (ptr)
	{
		salle = *(t_salle**)ptr->content;
		if (!salle->liens)
			salle->utile = 0;
		ptr = ptr->next;
	}
	return (2);
}
