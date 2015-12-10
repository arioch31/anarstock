/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:02:37 by aeguzqui          #+#    #+#             */
/*   Updated: 2015/12/07 16:13:27 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinsert(t_list **alst, t_list *new)
{
	t_list	*temp;

	temp = NULL;
	if (*alst && new)
	{
		temp = (*alst)->next;
		(*alst)->next = new;
		if (temp)
		{
			while (new->next)
				new = new->next;
			new->next = temp;
		}
	}
}
