/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:02:37 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/03/25 05:50:00 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** !!!! utiliser avec des pointeurs de debut de chaine ou l'adresse
**														inclue dans next
*/

void	ft_lstinsert_all(t_list **alst, t_list **new)
{
	t_list	*temp;

	temp = NULL;
	if (*alst && *new)
	{
		temp = (*alst);
		*alst = *new;
		if (temp)
			ft_lstapp(alst, temp);
	}
	else if (*new)
		alst = new;
}

void	ft_lstinsert_one(t_list **alst, t_list **new)
{
	t_list	*temp;
	t_list	*ptr;

	temp = NULL;
	if (*alst && *new)
	{
		temp = (*alst);
		ptr = (*new)->next;
		*alst = *new;
		(*alst)->next = temp;
		*new = ptr;
	}
	else if (*new)
	{
		*alst = *new;
		if ((*new)->next)
			*new = (*new)->next;
		else
			*new = NULL;
	}
}
