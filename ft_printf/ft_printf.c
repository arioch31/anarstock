/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:14:48 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/08 13:20:40 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	t_param	*p;
	t_param	*p2;
	t_list  *lst;
	t_list  *start;
	char	*tmp;

	if(!str)
	{
		ft_putendl("NULL");
		return (1);
	}
	if (!str[ft_lenword(str, '%')])
	{
		ft_putendl(str);
		return (1);
	}
	lst = str_tolist(str);
	if (!lst)
		return (0);
	va_start(ap, str);
	p = param_list(lst);
	p2 = p;
	while (p)
	{
		if (p->type == 'p')
			p->ptr->content = conv_p(p, ap);
		else if (p->type == 'c')
			p->ptr->content = buff_arg(add_char(NULL, (char)va_arg(ap, int)), p);
		else if (p->type == '%')
			p->ptr->content = buff_arg(add_char(NULL, '%'), p);
		else if (p->type == 's')
			p->ptr->content = buff_arg(va_arg(ap, char *), p);
		else if (p->type == 'd' || p->type == 'i')
			p->ptr->content = conv_d(p, ap);
		else if (p->type == 'n')
			conv_n(p, lst, ap);
		else if (ft_strchr(INT_CONV, p->type))
			p->ptr->content = conv_u(p, ap);
		p = p->next;
	}
	va_end(ap);
	tmp = NULL;
	start = lst;
	while (start)
	{
		tmp = ft_strjoin(tmp, (start->content ? start->content : "NULL"));
		start =start->next;
	}
	ft_putstr(tmp);
	return (1);
}
