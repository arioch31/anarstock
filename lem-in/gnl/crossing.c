/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crossing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 00:46:52 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/06/11 00:47:21 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		is_used(t_list *path, t_salle *salle)
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

int		crossing(t_ruche *ruche, t_list *path1, t_list *path2)
{
	t_list	*ptr;
	t_salle	*ptr_salle;

	ptr = path2;
	while (ptr)
	{
		ptr_salle = *(t_salle**)ptr->content;
		if (ptr_salle != ruche->end && ptr_salle != ruche->start
			&& is_used(path1, ptr_salle))
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

int		multicross(t_ruche *ruche, t_list *pathlist, t_list *path)
{
	t_list	*ptr;

	ptr = pathlist;
	while (ptr)
	{
		if (crossing(ruche, path, *(t_list**)(ptr->content)))
			return (1);
		ptr = ptr->next;
	}
	return (0);
}
