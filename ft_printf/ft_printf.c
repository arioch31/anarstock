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
		
		else if (p->type == 'd' || p->type == 'i')
		{
			if (p->length == 'l')
				p->ptr->content = conv_u_base(p, (long long)va_arg(ap, long int));	
			else if (p->length == 'k')	
				p->ptr->content = conv_u_base(p, (long long)va_arg(ap, long long));
			else if (p->length == 'h')
				p->ptr->content = conv_u_base(p, (short int)va_arg(ap, int));
			else if (p->length == 'g')
				p->ptr->content = conv_u_base(p, (char)va_arg(ap, int));
			else
				p->ptr->content = conv_u_base(p, (int)va_arg(ap, int));
		}
		else if (ft_strchr(INT_CONV, p->type))
		{
			if (p->length == 'l')
				p->ptr->content = conv_u_base(p, (unsigned long long)va_arg(ap, unsigned long int));	
			else if (p->length == 'k')	
				p->ptr->content = conv_u_base(p, (unsigned long long)va_arg(ap, long long));
			else if (p->length == 'h')
				p->ptr->content = conv_u_base(p, (unsigned short int)va_arg(ap, unsigned int));
			else if (p->length == 'g')
				p->ptr->content = conv_u_base(p, (unsigned char)va_arg(ap, unsigned int));
			else
				p->ptr->content = conv_u_base(p, (unsigned int)va_arg(ap, unsigned int));
		}
		else if (p->type == '%')
			p->ptr->content = buff_arg(add_char(NULL, '%'), p, 0);
		else if (p->type == 's')
			p->ptr->content = ft_strdup(va_arg(ap, char *));
			
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
