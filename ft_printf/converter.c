/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 14:25:47 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/04 18:30:30 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//si padding contient 0 et withd >0 et precision == 0, precision = withd (pour
//padder les 0

char	*buff_arg(char *res, t_param *p, int is_neg)
{
	if (p->precision && (p->type == 's' || p->type == 'S'))
		res = ft_strsub(res, 0, p->precision); //traitement pour S?
	if (ft_strchr(p->padding, '-'))
		res = padd_left(res, p->withd);
	else
		res = padd_right(res, p->withd);
	return (res);
}

char *conv_decimal(t_param *p, long long s)
{
	char			*res;
	int 			neg;

	neg = 0;
	if (s < 0)
	{
		neg = 1;
		s = -s;
	}
	res = ft_ultoa_base(s, 10, 0);
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

char *conv_u_base(t_param *p, unsigned long long s)
{
	char			*res;

	if (p->type == 'd' || p->type == 'i')
		return (conv_decimal(p, s));
	if (p->type == 'u')
		res = ft_ultoa_base(s, 10, 0);
	else if (p->type == 'o')
		res = ft_ultoa_base(s, 8, 0);
	else
		res = ft_ultoa_base(s, 16, (p->type == 'X'));

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
