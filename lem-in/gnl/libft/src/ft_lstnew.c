/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 23:17:20 by aeguzqui          #+#    #+#             */
/*   Updated: 2015/12/03 17:47:59 by aeguzqui         ###   ########.fr       */
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
