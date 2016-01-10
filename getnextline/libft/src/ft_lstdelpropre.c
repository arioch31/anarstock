/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelpropre.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:10:58 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/01/10 17:50:48 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	deleter(void *content, size_t size)
{
	free(content);
	content = NULL;
	size = 0;
}

void		ft_lstdelpropre(t_list **alst)
{
	t_list *lst;

	if (*alst)
	{
		lst = (*alst)->next;
		ft_lstdelone(alst, deleter);
		*alst = lst;
	}
}
