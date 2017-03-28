/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_tri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 01:14:58 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/03/27 23:37:55 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_tri_as(t_list *start, int (*f)(t_list *l1, t_list *l2))
{
	t_list	*dest;
	t_list	*ptr1;
	t_list	**ptr2;
	t_list	*tmp;

	ptr1 = start;
	dest = NULL;
	while (ptr1)
	{
		ft_putstr("dest:\t");
		ft_lstaff(dest, NULL);
		tmp = ptr1->next;
		ptr1->next = NULL;
		if (!dest)
			ft_lstinsert_one(&dest, &ptr1);
		else
		{
			ptr2 = &dest;
			while (ft_lstcmp(ptr1, (*ptr2), f) >= 0 && *ptr2)
				(ptr2) = &(*ptr2)->next;
			ft_lstinsert_one(ptr2, &ptr1);
		}
		ptr1 = tmp;
	}
	return (dest);
}

t_list	*ft_lst_tri_ds(t_list *start, int (*f)(t_list *l1, t_list *l2))
{
	t_list	*dest;
	t_list	*ptr1;
	t_list	**ptr2;
	t_list	*tmp;

	ptr1 = start;
	dest = NULL;
	while (ptr1)
	{
		ft_putstr("dest:\t");
		ft_lstaff(dest, NULL);
		tmp = ptr1->next;
		ptr1->next = NULL;
		if (!dest)
			ft_lstinsert_one(&dest, &ptr1);
		else
		{
			ptr2 = &dest;
			while (ft_lstcmp(ptr1, (*ptr2), f) <= 0 && *ptr2)
				(ptr2) = &(*ptr2)->next;
			ft_lstinsert_one(ptr2, &ptr1);
		}
		ptr1 = tmp;
	}
	return (dest);
}
