/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 22:46:06 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/06/10 18:19:30 by aeguzqui         ###   ########.fr       */
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

int	addstep_path(t_ruche *ruche, t_list *path, t_salle *current)
{
	t_list	*ptr;
	t_salle	*ptr_salle;
	t_list	*path_next;

	if (current == ruche->end)
	{
		ft_lstadd(&(ruche->list_paths), ft_lstnew(&path, sizeof(t_list*)));
		return (1);
	}
	ptr = current->liens;
	while (ptr)
	{
		ptr_salle = *(t_salle**)ptr->content;
		if (ptr_salle->utile && !is_used(path, ptr_salle))
		{
			path_next = ft_lstcpy(path);
			ft_lstapp(&(path_next), ft_lstnew(&ptr_salle, sizeof(t_salle*)));
			addstep_path(ruche, path_next, ptr_salle);
		}
		ptr = ptr->next;
	}
	ft_lstdel(&path, &list_clear);
	return (0);
}
