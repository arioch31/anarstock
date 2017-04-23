/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:09:53 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/04/23 22:35:25 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_dollar(char *str)
{
	int i;

	i = 0;
	if (*str != '0' && ft_strchr(NUMERICS, *str))
	{
		i = ft_atoi(str);
		while (ft_strchr(NUMERICS, *str))
			str++;
		if (*str == '$')
			return (i);
	}
	return (0);
}

int		smell_dollarz(t_printer *pri, char *str, size_t size)
{
	int		target;
	t_list	*ptr;

	if ((target = get_dollar(str + 1)))
	{
		if (target > pri->dollars)
		{
			ft_lstapp(&(pri->args), ft_lstxnew(target - pri->dollars));
			pri->dollars = target;
		}
		ptr = ft_lstget(pri->args, target);
		if (ptr->content_size && ptr->content_size != size)
			return (-1);
		ptr->content_size = size;
		return (1);
	}
	return (0);
}

int		assign_args(t_printer *pri, va_list ap)
{

}

int		get_sizes(t_param *p, char *str)
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
	p->withd = ft_atoi(str);
	while (ft_strchr(NUMERICS, *str))
		str++;
	if (*str == '.')
	{
		p->precision = ft_atoi(++str);
		p->precision++;
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
	return (0);
}
