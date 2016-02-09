/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 03:03:20 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/09 21:09:28 by aeguzqui         ###   ########.fr       */
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

char	*buff_decimal(t_param *p, intmax_t s)
{
	char			*res;
	int				neg;

	neg = 0;
	if (s < 0)
	{
		neg = 1;
		s = -s;
	}
	res = ft_umaxtoa_base(s, 10, 0);
	if (p->precision)
		res = padd_zero(res, p->precision - 1);
	if (neg)
		res = add_char(res, '-');
	else if (ft_strchr(p->padding, '+'))
		res = add_char(res, '+');
	else if (ft_strchr(p->padding, ' '))
		res = add_char(res, ' ');
	res = padd_zero(res, p->precision);
	if (ft_strchr(p->padding, '-'))
		res = padd_right(res, p->withd);
	else
		res = padd_left(res, p->withd);
	return (res);
}

char	*buff_u_base(t_param *p, uintmax_t s)
{
	char			*res;

	if (p->type == 'd' || p->type == 'i')
		return (buff_decimal(p, s));
	if (p->type == 'u')
		res = ft_umaxtoa_base(s, 10, 0);
	else if (p->type == 'o')
		res = ft_umaxtoa_base(s, 8, 0);
	else
		res = ft_umaxtoa_base(s, 16, (p->type == 'X'));
	res = padd_zero(res, p->precision);
	if (ft_strchr(p->padding, '#'))
	{
		if (p->type == 'x')
			res = add_char(res, 'x');
		else if (p->type == 'X')
			res = add_char(res, 'X');
		res = add_char(res, '0');
	}
	if (ft_strchr(p->padding, '-'))
		res = padd_right(res, p->withd);
	else
		res = padd_left(res, p->withd);
	return (res);
}
