/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 03:03:20 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/10 04:04:50 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_param		*arg_decrypt(char *str)
{
	t_param	*p;
	int		i;

	p = new_param();
	i = 0;
	if (*str != '%')
		return (NULL);
	if (get_dollar(p, str + 1) > 0)
		str = ft_strchr(str, '$');
	if (!get_sizes(p, str + 1))
		return (NULL);
	return (p);
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
			ft_lstapp(&start, ft_lstnew(ptr, ft_strlen(ptr)));
			return (start);
		}
		else
		{
			test = ft_strsub(ptr, 0, ft_strchr(ptr, '%') - ptr);
			ft_lstapp(&start, ft_lstnew(test, ft_strlen(test) + 1));
			ptr = ft_strchr(ptr, '%');
			if (!(test = arg_sub(ptr)))
				return (NULL);
			ft_lstapp(&start, ft_lstnew(test, ft_strlen(test) + 1));
			ptr += ft_strlen(test);
		}
	}
	return (start);
}

char		*arg_sub(const char *str)
{
	char	*sub;

	if (!str || *str != '%')
		return (NULL);
	sub = (char*)str;
	sub++;
	while (ft_strchr(PREFLAGS, *sub) || ft_strchr(FLAGS, *sub) \
			|| ft_strchr(NUMERICS, *sub) || *sub == '$' || *sub == '.')
		sub++;
	if (ft_strchr(CONVERTERS, *sub))
		return (ft_strsub(str, 0, sub - str + 1));
	else
		return (NULL);
}

t_param		*param_list(t_list *ptr)
{
	t_param *start;
	t_param	*elem;
	char	*tmp;

	start = NULL;
	while (ptr)
	{
		if (((tmp = (char*)ptr->content)) && *tmp == '%')
		{
			if ((elem = arg_decrypt(tmp)) && err_checker(elem))
			{
				elem->ptr = ptr;
				app_param(&start, elem);
			}
			else
				return (NULL);
		}
		ptr = ptr->next;
	}
	return (start);
}

char		*buff_arg(char *res, t_param *p)
{
	char	*str;

	if (!res)
		return (NULL);
	if (p->precision && (p->type == 's' || p->type == 'S'))
			str = ft_strsub(res, 0, p->precision);
	else
			str = ft_strdup(res);
	if (ft_strchr(p->padding, '-'))
		str = padd_right(str, p->withd);
	else
		str = padd_left(str, p->withd);
	return (str);
}
