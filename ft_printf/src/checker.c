/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:09:53 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/09 20:13:51 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_dollar(t_param *p, char *str)
{
	int i;

	i = 0;
	if (*str != '0' && ft_strchr(NUMERICS, *str))
	{
		i = ft_atoi(str);
		while (ft_strchr(NUMERICS, *str))
			str++;
		if (*str == '$')
		{
			if (!i)
				return (-1);
			p->p_index = i;
			return (1);
		}
	}
	p->p_index = 0;
	return (0);
}

int		get_sizes(t_param *p, char *str)
{
	while (ft_strchr(PREFLAGS, *str))
		p->padding = ft_strjoin(p->padding, ft_strsub(str++, 0, 1));
	p->withd = ft_atoi(str);
	while (ft_strchr(NUMERICS, *str))
		str++;
	if (*str == '.')
	{
		p->precision = ft_atoi(++str);
		while (ft_strchr(NUMERICS, *str))
			str++;
	}
	return (get_types(p, str));
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
	ft_putendl("get_types foiré");
	return (0);
}

int		check_char(t_param *p)
{
	if (*(p->padding) && *(p->padding) != '-')
		return (0);
	if (p->length && p->length != 'l')
		return (0);
	if ((p->type == 'c' || p->type == 'C') && p->precision)
		return (0);
	if (p->length == 'l' && (p->type == 'c' || p->type == 's'))
		p->type -= 32;
	return (1);
}

int		err_checker(t_param *p)
{
	char	*ptr;

	ptr = p->padding;
	if (p->withd && p->precision > p->withd)
		return (0);
	while (*(ptr++))
		if (ft_strchr(ptr, *(ptr - 1)))
			return (0);
	if (p->type == 's' || p->type == 'S' || p->type == 'c' || p->type == 'C')
		return (check_char(p));
	if (ft_strchr(FLOAT_CONV, p->type) && ft_strchr(FLOAT_FORB, p->length))
		return (0);
	if (ft_strchr(INT_CONV, p->type) && p->length == 'L')
		return (0);
	if (ft_strchr(p->padding, '#') && (!ft_strchr(HASH_VALID, p->type)
				|| ft_strchr(p->padding, ' ') || ft_strchr(p->padding, '0')))
		return (0);
	if (p->type == '%')
		return (!ft_strequ((p->ptr->content), "%%"));
	if (p->type == 'n')
		return (!ft_strequ((p->ptr->content), "%n"));
	return (1);
}
