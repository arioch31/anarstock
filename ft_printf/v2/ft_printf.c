/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:14:48 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/04/29 03:55:33 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		smell_param(t_printer *pri, t_list *ptr)
{
	int		i;
	char	*str;

	str = ptr->content;
	if ((i = smell_dollarz(pri, str, arg_size(str))) < 0
	|| (!i && pri->dollars))
		return (0);
	while (ft_strchr(NUMERICS, *(str + 1)))
		str++;
	if (*(++str) == '*' && ((i = smell_dollarz(pri, str, sizeof(int)) > 0)))
	{
		while (ft_strchr(NUMERICS, *(str + 1)))
			str++;
		if (*str == '.' && *(++str) == '*'
		&& smell_dollarz(pri, str, sizeof(int)) < 0)
			return (0);
	}
	return (1);
}

int		add_param_list(t_printer *pri, t_list *ptr)
{
	t_param	*elem;
	t_list	*list_elem;

	if (!smell_param(pri, ptr))
		return (0);
	list_elem = ft_lstnew(NULL, 0);
	elem = malloc(sizeof(t_param));
	ft_bzero(elem, sizeof(t_param));
	list_elem->content = elem;
	list_elem->content_size = sizeof(t_param*);
	elem->ptr = ptr;
	ft_lstapp(&(pri->params), list_elem);
	return (1);
}

int		arg_len(const char *str)
{
	char	*sub;

	if (!str || *str != '%')
		return (0);
	sub = (char*)str;
	sub++;
	while (ft_strchr(PREFLAGS, *sub) || ft_strchr(FLAGS, *sub) \
			|| ft_strchr(NUMERICS, *sub) || ft_strchr(OTHER, *sub))
		sub++;
	if (ft_strchr(CONVERTERS, *sub))
		return (sub - str + 1);
	else
		return (0);
}

int		str_tolist(const char *str, t_printer *pri)
{
	t_list	*elem;
	char	*ptr;
	int		test;

	start = NULL;
	ptr = (char*)str;
	while (*ptr)
	{
		if (!ft_strchr(ptr, '%'))
			test = ft_strlen(ptr);
		else if (*ptr != '%')
			test = ft_strchr(ptr, '%') - ptr;
		else if (!(test = arg_len(ptr)))
			return (-1);
		elem = ft_lstnew(NULL, 0);
		elem->content = ptr;
		elem->content_size = test;
		ft_lstapp(&(pri->lst), elem);
		if (*ptr = '%' && !add_param_list(pri, ft_lstlast(pri->lst)))
			return (-1);
		ptr += test;
	}
	return (ft_lstlen(pri->params));
}

int		get_values(t_printer *pri, va_list *ap)
{
	t_list	*ptr;

	ptr = pri->args;
	while (ptr)
	{
		if (!ptr->content_size)
			return (0);
		else
			ptr->content = va_arg(ap, ptr->content_size);
	}
	return (1);
}

int		clear_printer(t_printer *pri, int ret, char *msg)
{
	if (msg)
	{
		ft_putstr("ft_printf: ");
		ft_putstr(msg);
	}
	if (pri)
	{
		ft_lstdel(pri->lst, NULL);
		ft_lstdel(pri->args, NULL);
		ft_lstdel(pri->params, NULL);
		free(pri);
	}
	return (ret);
}

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	t_printer	*pri;
	int			i;

	if (!str)
	{
		ft_putstr("(null)");
		return (1);
	}
	pri = malloc(sizeof(t_printer));
	ft_bzero(pri, sizeof(t_printer));
	if ((i = str_tolist(str)) && i < 0)
		return (clear_printer(pri, -1, "incorrect parameters \n"));
	if (i && pri->dollars)
	{
		va_start(ap, str);
		i = get_values(pri, &ap);
		va_end(ap);
		if (!i)
			return (clear_printer(pri, -1, "$ incorrect format\n"));
	}
	return (lst_write(pri->lst));
}
