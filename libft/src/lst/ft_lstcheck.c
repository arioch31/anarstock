/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 02:27:18 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/04/13 02:32:57 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstcheck(t_list *lst, int (*f)(t_list*))
{
	if (lst->next)
	{
		if (!ft_lstcheck((lst->next), f))
			return (0);
	}
	return (f(lst));
}
