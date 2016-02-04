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

t_param	*param_list(t_list *ptr)
{
	t_param *start;
	t_param	*last;
	t_param	*elem;
	char	*tmp;

	start = NULL;
	last = NULL;
	while (ptr)
	{
		if (((tmp = (char*)ptr->content)) && *tmp == '%')
		{
		  	if ((elem = arg_decrypt(tmp)) && err_checker(elem))
			{
				elem->ptr = ptr;
				if (start)
				{
					last->next = elem;
					last = last->next;
				}
				else
				{
					last = elem;
					start = last;
				}
			}
			else
				return (NULL);
		}
		ptr = ptr->next;
	}
	return (start);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	t_param	*p;
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
	while (p)
	{
		if (p->type == 'c')
			p->ptr->content = buff_arg(add_char(NULL, (char)va_arg(ap, int)), p, 0);
		if (p->type == 'd' || p->type == 'i')
				p->ptr->content = conv_decimal(p, (long long)va_arg(ap, int));
		if (p->type == '%')
				p->ptr->content = buff_arg(add_char(NULL, '%'), p, 0);
		if (p->type == 'o')
						p->ptr->content = conv_u_base(p, (unsigned long long)va_arg(ap, int), 8);

		p = p->next;
	}
	va_end(ap);
	tmp = NULL;
	start = lst;
	while (start)
	{
		tmp = ft_strjoin(tmp, start->content);
		start =start->next;
	}
	ft_putstr(tmp);
	return (1);
}
/*	start = lst;
	while(start)
	{
		if ((tmp = ((char*)start->content)))
			if (*tmp== '%')
			{
				if ((p = arg_decrypt(tmp)))
				{
					if (err_checker(p))
						ft_putendl("argument OK");
					else
						ft_putendl("argument error");
					//aff_param(p);
				}
				else
					return (0);
				tmp++;
				c = p->type;
				if (c == '%')
				{
					free(start->content);
					start->content = ft_strdup("%");
				}
				if (c == 'c')
				{
					free(start->content);
					tmp = ft_strnew(2);
					*tmp = (char)va_arg(ap, int);
					start->content = tmp;
				}
				else if (c == 'd' || c == 'i')
					start->content = ft_itoa(va_arg(ap, int));
				else if (c == 'D')
					start->content = ft_ultoa_base_base(va_arg(ap, int), 10, 0);
				if (p)
				destr_param(p);
			}
		start = start->next;
	}*/
