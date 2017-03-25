/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 05:07:46 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/03/25 00:55:23 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstmove(t_list **dest, t_list **elem)
{
	t_list *tmp1;
	t_list *tmp2;

	if (dest && elem)
	{
		ft_putstr((char*)(*dest)->content);
		ft_putstr("\t");
		ft_putstr((char*)(*elem)->content);
		ft_putendl("\ttest");
		tmp1 = *dest;
		tmp2 = *elem;
		*dest = tmp2;
		*elem = tmp2->next;
		(*dest)->next = tmp1;
	}
}
