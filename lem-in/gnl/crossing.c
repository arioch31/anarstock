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

int		path_equ(t_list *path1, t_list *path2) //a tester
{
	t_list	*ptr1;
	t_list	*ptr2;

	ptr1 = path1;
	ptr2 = path2;
	while (ptr1 && ptr2)
	{
		if (*(t_salle**)ptr2->content != *(t_salle**)ptr2->content)
			return (0);
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
		if (!ptr1 - !ptr2)
			return (0);
	}
	return (1);
}

t_list	*map_in_list(t_list *map, t_list *listmap)
{
	t_list	*ptr;

 	ptr = listmap;
 	while (ptr)
 	{
		if (map_equ(map, *(t_list**)ptr->content))
 			return (*(t_list**)(ptr->content));
 		ptr = ptr->next;
 	}
 	return (NULL);
}

int	path_in_map(t_list *path, t_list *listpath)
{
	t_list	*ptr;

 	ptr = listpath;
 	while (ptr)
 	{
 		if (path_equ(path, *(t_list**)ptr->content))
 			return (1);
 		ptr = ptr->next;
 	}
 	return (0);
}

int		map_equ(t_list *pathlist1, t_list *pathlist2) //a tester
{
	t_list	*ptr1;
	t_list	*ptr2;

	ptr1 = pathlist1;
	while (ptr1)
	{
		if (!path_in_map(*(t_list**)ptr1->content, pathlist2))
			return (0);
		ptr1 = ptr1->next;
	}
	ptr2 = pathlist2;
	while (ptr2)
	{
		if (!path_in_map(*(t_list**)ptr2->content, pathlist1))
			return (0);
				ptr2 = ptr2->next;
	}
	return (1);
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
