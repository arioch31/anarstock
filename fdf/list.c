/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 23:50:16 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/02/28 02:37:34 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_2dpt	*as_2dpt(t_list *start, size_t index)
{
	t_list	*ptr;
	t_2dpt	*pt;
	if (((ptr = ft_lstgetnb(start, index)))
	&& (ptr->content_size == sizeof(t_2dpt)))
		return ((t_2dpt*)ptr->content);
	return (NULL);
}

t_3dpt	*as_3dpt(t_list *start, size_t index)
{
	t_list	*ptr;

	if ((ptr = ft_lstgetnb(start, index)))
		return ((t_3dpt*)ptr->content);
	return (NULL);
}
