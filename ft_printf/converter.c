/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 14:25:47 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/08 12:04:55 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//si padding contient 0 et withd >0 et precision == 0, precision = withd (pour
//padder les 0

char	*conv_p(t_param *p, va_list ap)
{
	unsigned long int 	i;

	p->type = 'x';
	p->padding = add_char(p->padding, '#');
	p->length = 'k';
	i = (unsigned long int)(va_arg(ap, void *));
	if (i)
		return (buff_u_base(p, i));
	else
		return (NULL);
}

int 	conv_n(t_param *p, t_list *start, va_list ap)
{
	char 	*buffer;
	int 	len;
	int 	*ptr;

	buffer = NULL;
	while (p->ptr != start)
	{
		buffer = ft_strjoin(buffer,start->content);
		start = start->next;
	}
	len = ft_strlen(buffer);
	ptr = va_arg(ap, int *);
	*ptr = len;
	p->ptr->content = ft_strnew(0);
	return (*ptr);
}

char	*conv_d(t_param *p,va_list ap)
{

	if (p->length == 'l')
		return (buff_decimal(p, (long long)va_arg(ap, long int)));
	else if (p->length == 'k')
		return (buff_decimal(p, (long long)va_arg(ap, long long)));
	else if (p->length == 'h')
		return (buff_decimal(p, (short int)va_arg(ap, int)));
	else if (p->length == 'g')
		return (buff_decimal(p, (char)va_arg(ap, int)));
	else
		return(buff_decimal(p, (int)va_arg(ap, int)));
}

char	*conv_u(t_param *p,va_list ap)
{

	if (p->length == 'l')
		return (buff_u_base(p, (unsigned long long)va_arg(ap, unsigned long int)));
	else if (p->length == 'k')
		return (buff_u_base(p, (unsigned long long)va_arg(ap, unsigned long long)));
	else if (p->length == 'h')
		return (buff_u_base(p, (unsigned short int)va_arg(ap, unsigned int)));
	else if (p->length == 'g')
		return (buff_u_base(p, (unsigned char)va_arg(ap, unsigned int)));
	else
		return(buff_u_base(p, (unsigned int)va_arg(ap, unsigned int)));
}

char	*buff_arg(char *res, t_param *p)
{
	if (p->precision && (p->type == 's' || p->type == 'S'))
		res = ft_strsub(res, 0, p->precision);
	if (ft_strchr(p->padding, '-'))
		res = padd_left(res, p->withd);
	else
		res = padd_right(res, p->withd);
	return (res);
}

char *buff_decimal(t_param *p, long long s)
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

char *buff_u_base(t_param *p, unsigned long long s)
{
	char			*res;

	if (p->type == 'd' || p->type == 'i')
		return (buff_decimal(p, s));
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
