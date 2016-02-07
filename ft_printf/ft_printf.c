/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:14:48 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/04 18:57:46 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
char	*conv_p(t_param *p, va_list ap)
{
	unsigned long int 	i;

	p->type = 'x';
	p->padding = add_char(p->padding, '#');
	p->length = 'k';
	i = (unsigned long int)(va_arg(ap, void *));
	if (i)
		return (conv_u_base(p, i));
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
			p->ptr->content = buff_arg(add_char(NULL, (char)va_arg(ap, int)), p, 0);
		else if (p->type == '%')
			p->ptr->content = buff_arg(add_char(NULL, '%'), p, 0);
		else if (p->type == 's')
			p->ptr->content = ft_strdup(va_arg(ap, char *));
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
