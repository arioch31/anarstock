/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 19:28:26 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/20 21:06:22 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*buff_arg(char *res, t_param *p)
{
	char	*str;

	if (!res)
		return (NULL);
	if (!*res && (p->type == 'c' || p->type == 'C'))
	{
		str = ft_strnew(p->withd + 1);
		str = ft_memset(str, ' ', p->withd);
		if (!ft_strchr(p->padding, '-') && p->withd)
			*(str + p->withd - 1) = '\0';
		else
			*str = '\0';
		return (str);
	}
	else if (p->precision && (p->type == 's' || p->type == 'S'))
		str = ft_strsub(res, 0, p->precision - 1);
	else
		str = ft_strdup(res);
	if (ft_strchr(p->padding, '-'))
		str = padd_right(str, p->withd);
	else
		str = padd_left(str, p->withd);
	return (str);
}

int			withd_modifier(t_param *p, int neg)
{
	if (ft_strchr(p->padding, '#') && (p->type == 'x' || p->type == 'X'))
		return (2);
	if (ft_strchr(p->padding, '#') && p->type == 'o')
		return (1);
	if (p->type == 'd' && neg == 1)
		return (1);
	if (p->type == 'd' && !neg && \
			(ft_strchr(p->padding, ' ') || ft_strchr(p->padding, '+')))
		return (1);
	return (0);
}

char		*buff_intstr(t_param *p, char *res, int neg)
{
	if (p->precision > 1)
		res = padd_zero(res, p->precision - 1);
	else if (p->precision == 1 && ft_strequ(res, "0"))
		res = ft_strnew(0);
	if (ft_strchr(p->padding, '0') \
			&& p->withd > withd_modifier(p, neg) + ft_strlen(res))
		res = padd_zero(res, p->withd - withd_modifier(p, neg));
	if (neg)
		res = add_char(res, '-');
	else if (p->type == 'd' && ft_strchr(p->padding, '+'))
		res = add_char(res, '+');
	else if (p->type == 'd' && ft_strchr(p->padding, ' '))
		res = add_char(res, ' ');
	else if (ft_strchr(p->padding, '#') && !(p->type == 'o' && *res == '0') && \
	(p->type == 'p' || ft_atoi(res) || (p->precision && p->type == 'o')))
	{
		if (p->type == 'x' || p->type == 'p')
			res = add_char(res, 'x');
		else if (p->type == 'X')
			res = add_char(res, 'X');
		res = add_char(res, '0');
	}
	res = buff_arg(res, p);
	p->ptr->content_size = ft_strlen(res) + 1;
	return (res);
}

char		*buff_decimal(t_param *p, intmax_t s)
{
	char			*res;
	int				neg;

	neg = 0;
	if (s < 0)
	{
		neg = 1;
		if (s - 1 < s)
			s = -s;
	}
	res = ft_umaxtoa_base(s, 10, 0);
	return (buff_intstr(p, res, neg));
}

char		*buff_u_base(t_param *p, uintmax_t s)
{
	char			*res;

	if (p->type == 'u')
		res = ft_umaxtoa_base(s, 10, 0);
	else if (p->type == 'o')
		res = ft_umaxtoa_base(s, 8, 0);
	else
		res = ft_umaxtoa_base(s, 16, (p->type == 'X'));
	return (buff_intstr(p, res, 0));
}
