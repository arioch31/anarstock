/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 21:18:07 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/10 00:05:12 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstlen(t_list *start)
{
	int cpt;

	cpt = 0;
	while (start)
	{
		cpt++;
		start = start->next;
	}
	return (cpt);
}
