/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetnb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 01:00:32 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/05/28 03:59:35 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstgetnb(t_list *start, size_t index)
{
	size_t i;

	if (!index)
		return (NULL);
	i = 1;
	while (start && i < index)
	{
		i++;
		start = start->next;
	}
	return (start);
}
