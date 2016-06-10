/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 22:46:06 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/06/11 01:06:34 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	add_paths(t_ruche *ruche, t_list *pathlist)
{
	t_list	*ptr;
	t_list	*ptr_path;

	ptr = ruche->map_paths;
	while (ptr)
	{
		ptr_path = *(t_list**)ptr->content;
		if (!multicross(ruche, pathlist, ptr_path))
			ft_lstapp(&pathlist, ft_lstnew(&ptr_path, sizeof(t_list*)));
		ptr = ptr->next;
	}
}

void	select_paths(t_ruche *ruche)
{
	t_list	*ptr;
	t_list	*ptr_path;
	t_list	*ptr_patlst;

	ptr = ruche->map_paths;
	while (ptr)
	{
		ptr_path = *(t_list**)ptr->content;
		ptr_patlst = ft_lstnew(&ptr_path, sizeof(t_list*));
		add_paths(ruche, ptr_patlst);
		ptr_patlst->content_size = ft_lstlen(ptr_patlst);
		ft_lstadd(&ruche->lists_paths, ft_lstnew(&ptr_patlst, sizeof(t_list*)));
		ptr = ptr->next;
	}
}

///////////////////CHANTIER!!!!!!!!!!!!!!!
void	trim_paths(t_ruche *ruche)
{
	t_list	*ptr;
	t_list	*ptr_path;

	ptr = ruche->lists_paths;
	while (ptr)
	{
		if (ptr->content_size == 1)
		{
			ptr_path = *(t_list**)ptr->content;
			if ((int)ptr_path->content_size > ft_lstlen(ruche->short_path))
			{
				ft_putstr("path trop long");
				aff_path(ptr_path);
			}
		}
		ptr = ptr->next;
	}
}

int		addstep_path(t_ruche *ruche, t_list *path, t_salle *current)
{
	t_list	*ptr;
	t_salle	*ptr_salle;
	t_list	*path_next;

	if (current == ruche->end)
	{
		path_next = ft_lstnew(&path, sizeof(t_list*));
		path->content_size = ft_lstlen(path);
		ft_lstadd(&(ruche->map_paths), path_next);
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
