/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 03:03:20 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/05/28 13:47:15 by aeguzqui         ###   ########.fr       */
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
