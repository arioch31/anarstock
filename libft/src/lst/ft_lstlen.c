/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 21:18:07 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/02/28 02:18:47 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstlen(t_list *start)
{
	int		cpt;
	t_list	*ptr;

	cpt = 0;
	ptr = start;
	while (ptr)
	{
		cpt++;
		ptr = ptr->next;
	}
	return (cpt);
}
