/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 00:46:52 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/06/11 00:47:21 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	list_clear(void *content, size_t content_size)
{
	if (content)
		content = NULL;
	content_size++;
	content_size = 0;
}

void	clear_salles(t_list *list)
{
	t_list	*ptr;
	t_salle	*ptr_salle;

	ptr = list;
	{
		while (ptr)
		{
			ptr_salle = *(t_salle**)ptr->content;
			ft_lstdel((t_list**)&(ptr_salle->liens), list_clear);
			free(ptr_salle->name);
			free(ptr_salle);
			ptr = ptr->next;
			if (list)
				{
					free(list);
					list = NULL;
					list = ptr;
				}
		}
	}
}

void	clear_map(t_list *map)
{
	t_list *ptr;

	ptr = map;
	{
		while (ptr)
		{

			ft_lstdel((t_list**)&(ptr->content), list_clear);
			ptr = ptr->next;
		}

	}
}

void	clear_listmap(t_list *list_maps)
{
	t_list *ptr;

		ptr = list_maps;
	{
		while (ptr)
		{
			clear_map(*(t_list**)ptr->content);
			ft_lstdel((t_list**)&(ptr->content), list_clear);
			ptr = ptr->next;
		}
		ft_lstdel(&list_maps, list_clear);
	}
}

void	clear_ruche(t_ruche *ruche)
{
	clear_listmap(ruche->list_maps);
	clear_map(ruche->list_paths);
	ft_lstdel(&ruche->short_path, list_clear);
	clear_salles(ruche->list_salles);
	ruche->start = NULL;
	ruche->end = NULL;
	free(ruche);
	ruche = NULL;
}