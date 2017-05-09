/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:09:53 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/05/09 18:15:50 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_prec(t_param *p, const char *str, va_list *ap)
{
	if (*str == '.')
	{
		str++;
		if (*str == '*')
		{
			p->precision = va_arg(ap, int);
			str++;
		}
		else
		{
			p->precision = ft_atoi(str);
			while (ft_strchr(NUMERICS, *str))
				str++;
		}
	}
	return (get_types(p, str));
}

int		get_withd(t_param *p, const char *str, va_list *ap)
{
	int i;

	while ((i = ft_strindex(PREFLAGS, *str)))
	{
		if (p->flags & (1 << (i - 1)))
			return (0);
		else
			p->flags &= (1 << (i - 1));
		str++;
	}
	if (*str == '*')
	{
		p->withd = va_arg(ap, int);
		str++;
	}
	else
	{
		p->withd = ft_atoi(str);
		while (ft_strchr(NUMERICS, *str))
			str++;
	}
	return (get_prec(p, str, ap));
}

int		get_types(t_param *p, char *str)
{
	if ((*str == 'h' || *str == 'l') && *str == *(str + 1))
	{
		p->length = *(str) - 1;
		str += 2;
	}
	else if (ft_strchr(FLAGS, *str))
		p->length = *(str++);
	if (ft_strchr(CONVERTERS, *str))
	{
		p->type = *str;
		if (*str == 'D' || *str == 'O' || *str == 'U')
		{
			p->length = 'l';
			p->type = *str + 32;
		}
		return (1);
	}
	return (0);
}
