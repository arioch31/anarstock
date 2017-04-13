/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:14:48 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/04/13 02:21:59 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*arg_sub(const char *str)
{
	char	*sub;

	if (!str || *str != '%')
		return (NULL);
	sub = (char*)str;
	sub++;
	while (ft_strchr(PREFLAGS, *sub) || ft_strchr(FLAGS, *sub) \
			|| ft_strchr(NUMERICS, *sub) || ft_strchr(OTHER, *sub))
		sub++;
	if (ft_strchr(CONVERTERS, *sub))
		return (ft_strsub(str, 0, sub - str + 1));
	else
		return (NULL);
}

t_list		*str_tolist(const char *str)
{
	t_list	*start;
	char	*ptr;
	char	*test;

	start = NULL;
	ptr = (char*)str;
	while (*ptr)
	{
		if (!ft_strchr(ptr, '%'))
		{
			ft_lstapp(&start, ft_lstnew(ptr, ft_strlen(ptr) + 1));
			return (start);
		}
		else if (*ptr != '%')
		{
			test = ft_strsub(ptr, 0, ft_strchr(ptr, '%') - ptr);
			ft_lstapp(&start, ft_lstnew(test, ft_strlen(test) + 1));
			ptr = ft_strchr(ptr, '%');
		}
		if (!(test = arg_sub(ptr)))
			return (NULL);
		ft_lstapp(&start, ft_lstnew(test, ft_strlen(test) + 1));
		ptr += ft_strlen(test);
	}
	return (start);
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

t_list		*param_list(t_list *ptr)
{
	t_list *start;
	t_param	*elem;
	t_list	*list_elem;
	char	*tmp;

	start = NULL;
	while (ptr)
	{
		if (((tmp = (char*)ptr->content)) && *tmp == '%')
		{
			elem = malloc(sizeof(t_param));
			elem->ptr = ptr;
			list_elem = ft_lstnew(elem, sizeof(t_param*));
			ft_lstapp(&start, list_elem);
		}
		ptr = ptr->next;
	}
	return (start);
}

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	t_list	*params;
	t_list	*lst;
	char	*tmp;

	tmp = NULL;
	if (!str)
	{
		ft_putstr("(null)");
		return (1);
	}
	if (!(lst = str_tolist(str)))
		return (-1);
	if (!(params = param_list(lst)) && ft_lstlen(lst) > 1)
		return (-1);
//	va_start(ap, str);
//	get_values(p, ap, lst);
//	va_end(ap);
//	clear_params(p);
	return (lst_write(lst));
}
