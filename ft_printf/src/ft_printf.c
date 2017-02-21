/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:14:48 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/05/28 13:57:18 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_values(t_param *p, va_list ap, t_list *lst)
{
	while (p)
	{
		if (p->type == 'p')
			p->ptr->content = conv_p(p, ap);
		else if (p->type == 'c' || p->type == 'C' || p->type == '%')
			conv_c(p, ap);
		else if (p->type == 's')
		{
			p->ptr->content = buff_arg(va_arg(ap, char *), p);
			p->ptr->content_size = ft_strlen(p->ptr->content) + 1;
		}
		else if (p->type == 'S')
		{
			p->ptr->content = conv_ws(p, ap);
			p->ptr->content_size = ft_strlen(p->ptr->content) + 1;
		}
		else if (p->type == 'n')
			conv_n(p, lst, ap);
		else if (p->type == 'd')
			p->ptr->content = conv_d(p, ap);
		else if (ft_strchr(INT_CONV, p->type))
			p->ptr->content = conv_u(p, ap);
		p = p->next;
	}
}

int		lst_write(t_list *p)
{
	int	cpt;

	cpt = 0;
	while (p)
	{
		if (!p->content)
		{
			ft_putstr("(null)");
			cpt += 6;
		}
		else
		{
			write(1, p->content, p->content_size - 1);
			cpt += p->content_size - 1;
		}
		p = p->next;
	}
	return (cpt);
}

void	clear_params(t_param *p)
{
	if (p)
	{
		if (p->next)
			clear_params(p->next);
		destr_param(p);
	}
}

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	t_param	*p;
	t_list	*lst;
	char	*tmp;

	tmp = NULL;
	if (!str)
	{
		ft_putstr("(null)");
		return (1);
	}
	if (!(lst = str_tolist(str)))
		return (0);
	p = param_list(lst);
	va_start(ap, str);
	get_values(p, ap, lst);
	va_end(ap);
	clear_params(p);
	return (lst_write(lst));
}
