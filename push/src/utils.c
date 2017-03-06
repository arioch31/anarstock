/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 18:39:30 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/05/11 22:04:45 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t		rank(t_list *start, int value)
{
	size_t i;

	i = 1;
	while (start)
	{
		if (value > *(int*)start->content)
			i++;
		start = start->next;
	}
	return (i);
}

t_list		*get_valued(t_list *start, int value)
{
	while (start)
	{
		if (*(int*)start->content == value)
			return (start);
		start = start->next;
	}
	return (start);
}

t_list		*get_ranker(t_list *start, size_t index)
{
	t_list *ptr;

	ptr = start;
	while (ptr && ptr->content_size != index)
		ptr = ptr->next;
	return (ptr);
}

size_t		get_length(t_list *start)
{
	size_t i;

	i = 0;
	while (start)
	{
		i++;
		start = start->next;
	}
	return (i);
}

size_t		get_sublength(t_list *start, int value, int sens)
{
	int i;

	i = 0;
	while (start)
	{
		if ((value < *(int*)start->content) ^ !sens)
			return (i);
		if (!start->next)
			return (++i);
		if ((*(int*)start->content < *(int*)start->next->content) ^ !sens)
		{
			start = start->next;
			i++;
		}
		else
			return (++i);
	}
	return (i);
}
