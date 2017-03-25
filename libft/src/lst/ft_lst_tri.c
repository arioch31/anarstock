/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_tri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 01:14:58 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/03/25 03:25:49 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_tri(t_list *start, int (*f)(t_list *l1, t_list *l2))
{
	t_list	**dest;
	t_list	*ptr1;
	t_list	*ptr2;
	t_list	*tmp;

	ptr1 = start;
	dest = malloc(sizeof(t_list*));
	while (ptr1)
	{
		ptr2 = *dest;
		tmp = ptr1->next;
		ptr1->next = NULL;
		if (!ptr2)
			ft_lstinsert_one(dest, &ptr1);
		else
		{
			while (ptr2->next && ft_lstcmp(ptr1, ptr2->next, f) > 0)
				ptr2 = ptr2->next;
			ft_lstinsert_one(&ptr2, &ptr1);
		}
		ptr1 = tmp;
		ft_putendl("tri result:");
		ft_lstaff(*dest, NULL);
	}
	return (*dest);
}
