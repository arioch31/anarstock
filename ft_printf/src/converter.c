/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 14:25:47 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/10 00:29:32 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*conv_p(t_param *p, va_list ap)
{
	unsigned long int	i;

	p->type = 'x';
	p->padding = add_char(p->padding, '#');
	p->length = 'k';
	i = (unsigned long int)(va_arg(ap, void *));
	return (buff_u_base(p, i));
	}

void		conv_n(t_param *p, t_list *start, va_list ap)
{
	intmax_t		len;
	intmax_t		*ptr;

	len = 0;
	while (p->ptr != start)
	{
		len += ft_strlen(start->content);
		start = start->next;
	}
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
	*ptr = len;
	p->ptr->content = ft_strnew(0);
}

char		*conv_d(t_param *p, va_list ap)
{
	if (p->length == 'l')
		return (buff_decimal(p, (long long)va_arg(ap, long int)));
	else if (p->length == 'k')
		return (buff_decimal(p, (long long)va_arg(ap, long long)));
	else if (p->length == 'h')
		return (buff_decimal(p, (short int)va_arg(ap, int)));
	else if (p->length == 'g')
		return (buff_decimal(p, (char)va_arg(ap, int)));
	else if (p->length == 'j')
		return (buff_decimal(p, (intmax_t)va_arg(ap, intmax_t)));
	else if (p->length == 'z')
		return (buff_decimal(p, (size_t)va_arg(ap, size_t)));
	else
		return (buff_decimal(p, (int)va_arg(ap, int)));
}

char		*conv_u(t_param *p, va_list ap)
{
	if (p->length == 'l')
		return (buff_u_base(p, va_arg(ap, unsigned long int)));
	else if (p->length == 'k')
		return (buff_u_base(p, va_arg(ap, unsigned long long)));
	else if (p->length == 'h')
		return (buff_u_base(p, (unsigned short int)va_arg(ap, unsigned int)));
	else if (p->length == 'g')
		return (buff_u_base(p, (unsigned char)va_arg(ap, unsigned int)));
	else if (p->length == 'j')
		return (buff_u_base(p, (uintmax_t)va_arg(ap, uintmax_t)));
	else if (p->length == 'z')
		return (buff_u_base(p, (ssize_t)va_arg(ap, ssize_t)));
	else
		return (buff_u_base(p, (unsigned int)va_arg(ap, unsigned int)));
}

char		*buff_arg(char *res, t_param *p)
{
	if (!res)
		return (NULL);
	if (p->precision && (p->type == 's' || p->type == 'S'))
		res = ft_strsub(res, 0, p->precision);
	if (ft_strchr(p->padding, '-'))
		res = padd_left(res, p->withd);
	else
		res = padd_right(res, p->withd);
	return (res);
}
