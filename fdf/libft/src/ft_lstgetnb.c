/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetnb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 01:00:32 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/02/27 05:49:32 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstgetnb(t_list *start, size_t index)
{
	size_t	i;
	t_list	*ptr;

	if (!index)
		return (NULL);
	i = 1;
	ptr = start;
	while (ptr && i < index)
	{
		ptr = ptr->next;
		i++;
	}
	return (ptr);
}
