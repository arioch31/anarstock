/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:14:48 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/10 00:13:12 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_values(t_param *p, va_list ap, t_list *lst)
{
	while (p)
	{
		if (p->type == 'p')
			p->ptr->content = conv_p(p, ap);
		else if (p->type == 'c')
			p->ptr->content = \
				buff_arg(add_char(NULL, (char)va_arg(ap, int)), p);
		else if (p->type == '%')
			p->ptr->content = buff_arg(add_char(NULL, '%'), p);
		else if (p->type == 's')
			p->ptr->content = buff_arg(va_arg(ap, char *), p);
		else if (p->type == 'C')
			p->ptr->content = buff_arg(ft_wctostr(va_arg(ap, wchar_t)), p);
		else if (p->type == 'S')
			p->ptr->content = buff_arg(ft_strwctostr(va_arg(ap, wchar_t *)), p);
		else if (p->type == 'd' || p->type == 'i')
			p->ptr->content = conv_d(p, ap);
		else if (p->type == 'n')
			conv_n(p, lst, ap);
		else if (ft_strchr(INT_CONV, p->type))
			p->ptr->content = conv_u(p, ap);
		p = p->next;
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
	va_start(ap, str);
	p = param_list(lst);
	get_values(p, ap, lst);
	va_end(ap);
	tmp = ft_lstcat(lst);
	ft_putstr(tmp);
	return (ft_strlen(tmp));
}
