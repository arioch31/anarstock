/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 04:05:09 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/25 18:36:04 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_last(t_list *start)
{
	t_list	*ptr;

	ptr = start;
	while (ptr && ptr->next)
		ptr = ptr->next;
	return (ptr);
}

t_list	*get_prelast(t_list *start)
{
	t_list	*ptr;

	ptr = start;
	while (ptr && ptr->next && ptr->next->next)
		ptr = ptr->next;
	return (ptr);
}

void	rot_pile(t_list **start)
{
	t_list	*ptr;

	ptr = *start;
	*start = (*start)->next;
	get_last(*start)->next = ptr;
	ptr->next = NULL;
}

void	revrot_pile(t_list **start)
{
	t_list	*ptr;

	ptr = get_last(*start);
	get_prelast(*start)->next = NULL;
	ptr->next = *start;
	*start = ptr;
}

int		swap_pile(t_list **start)
{
	t_list	*first;
	t_list	*second;

	if (!start || !*start || !(*start)->next)
		return (0);
	first = *start;
	second = (*start)->next;
	first->next = second->next;
	second->next = first;
	*start = second;
	return (1);
}
