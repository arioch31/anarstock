/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 23:17:20 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/04/22 02:36:21 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list *newelem;

	newelem = NULL;
	if ((newelem = malloc(sizeof(t_list))))
	{
		newelem->next = NULL;
		if (content && content_size)
		{
			newelem->content = malloc(content_size);
			ft_memcpy(newelem->content, content, content_size);
			newelem->content_size = content_size;
		}
		else
		{
			newelem->content = NULL;
			newelem->content_size = 0;
		}
	}
	return (newelem);
}

t_list	*ft_lstxnew(size_t nb)
{
	size_t		cpt;
	t_list	*newelem;

	newelem = NULL;
	cpt = 0;
	while (cpt++ < nb)
		ft_lstapp(&newelem, ft_lstnew(NULL, 0));
	return (newelem);
}
