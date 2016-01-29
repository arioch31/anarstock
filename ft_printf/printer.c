/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 04:39:45 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/01/29 05:57:12 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*buff_arg(char *res, t_param *p, int is_neg)
{
	if (ft_strchr(p->padding, '#'))
	{
		if (p->type == 'x')
			res = add_char(add_char(res, 'x'), '0');
		if (p->type == 'X')
			res = add_char(add_char(res, 'X'), '0');
		if (p->type == 'o')
			res = add_char(res, '0');
	}
	else if (is_neg)
		res = add_char(res, '-');
	else if (ft_strchr(p->padding, '+'))
		res = add_char(res, '+');
	else if (ft_strchr(p->padding, ' '))
		res = add_char(res, ' ');
	else if (ft_strchr(p->padding, '0') && p->type != 'n' && \
			!(p->precision && ft_strchr(INT_CONV, p->type)))
		res = padd_zero(res, p->withd);
	if (p->precision && (p->type == 's' || p->type == 'S'))
		res = ft_strsub(res, p->precision); //traitement pour S?
	if (ft_strchr(p->padding, '-'))
		res = padd_left(res, p->withd);
	else
		res = padd_right(res, p->withd);
	return (res);
}
