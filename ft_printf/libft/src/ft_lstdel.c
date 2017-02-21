/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 00:46:06 by aeguzqui          #+#    #+#             */
/*   Updated: 2015/12/01 17:15:04 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst)
	{
		if ((*alst)->next)
		{
			ft_lstdel(&((*alst)->next), del);
			(*alst)->next = NULL;
		}
		ft_lstdelone(alst, del);
	}
}
