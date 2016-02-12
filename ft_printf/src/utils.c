/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 03:03:20 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/11 19:49:34 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_param	*new_param(void)
{
	t_param	*p;

	p = malloc(sizeof(t_param));
	p->p_index = 0;
	p->padding = ft_strnew(0);
	p->next = NULL;
	p->withd = 0;
	p->precision = 0;
	p->length = 0;
	p->type = 0;
	p->ptr = malloc(sizeof(char*));
	return (p);
}

int		app_param(t_param **start, t_param *elem)
{
	int		i;
	t_param	*last;

	i = 1;
	last = *start;
	if (*start)
	{
		while (last->next)
		{
			last = last->next;
			i++;
		}
		last->next = elem;
	}
	else
	{
		last = elem;
		*start = last;
	}
	return (i);
}

void	destr_param(t_param *p)
{
	free(p->padding);
	p->padding = NULL;
	p->ptr = NULL;
	free(p);
}
