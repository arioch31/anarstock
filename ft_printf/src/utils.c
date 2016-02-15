/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 03:03:20 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/15 00:27:05 by aeguzqui         ###   ########.fr       */
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

void	conv_n(t_param *p, t_list *start, va_list ap)
{
	intmax_t		*ptr;

	if (p->length == 'l')
		ptr = (intmax_t *)va_arg(ap, long int *);
	else if (p->length == 'k')
		ptr = (intmax_t *)va_arg(ap, long long *);
	else if (p->length == 'h')
		ptr = (intmax_t *)(short int*)va_arg(ap, int *);
	else if (p->length == 'g')
		ptr = (intmax_t *)(char*)va_arg(ap, int *);
	else if (p->length == 'j')
		ptr = (intmax_t *)va_arg(ap, intmax_t *);
	else if (p->length == 'z')
		ptr = (intmax_t *)va_arg(ap, size_t *);
	else
		ptr = (intmax_t *)va_arg(ap, int *);
	*ptr = 0;
	while (p->ptr != start)
	{
		*ptr += start->content_size - 1;
		start = start->next;
	}
	p->ptr->content = ft_strnew(0);
	p->ptr->content_size = 1;
}
