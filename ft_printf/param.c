/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 03:03:20 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/04 18:23:50 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_type(t_param *p)
{
/*	if (p->type = 'c' && !p->length)
		p->definer = 'c';
	else if (ft_strchr(INT_CONV, p->type))
	{
		(p->length == 'g' ? p->definer = 'c' : );
		(p->length == 'h' ? p->definer = 's' : );
		(p->length == 'l' ? p->definer = 'l' : );
		(p->length == 'k' ? p->definer = 'L' : p->definer = 'i');
	}
	else if (ft_strchr(FLOAT_CONV, p->type))
	{
		(p->length == 'l' ? p->definer = 'd' : );
		(p->length == 'k' || p->length == 'L' ? p->definer = 'D' : p->definer = 'f');

	}
	else if (p->type == 'n' || p->type == 'p')
		//go_fuck_yourself;
		ft_putendl("not yet");
	else if (p->type == '%')
		return (1);
	else 
		return (0);
*/	return (1);
}

t_param	*arg_decrypt(char *str)
{
	t_param	*p;
	char	*ptr;
	char	c;
	int		i;

	p = new_param();
	i = 0;
	if (*str != '%')
		return (NULL);
	if (get_dollar(p, str + 1) > 0)
		str = ft_strchr(str, '$') + 1;
	if (!get_sizes(p, str + 1) || !check_type(p))
	{
		ft_putendl("get_size foiré");
		return (NULL);
	}
	return (p);
}

t_list *str_tolist(const char *str)
{
	t_list  *start;
	char    *ptr;
	char    *test;

	start = NULL;
	ptr = (char*)str;
	while (*ptr)
	{
		if(!ft_strchr(ptr, '%'))
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
				return(0);
			ft_lstapp(&start, ft_lstnew(test, ft_strlen(test) + 1));
			ptr += ft_strlen(test);
		}
	}
	return (start);
}

char	*arg_sub(const char *str)
{
	char	*sub;

	if (!str || *str != '%')
		return (NULL);
	sub = (char*)str;
	sub++;
	while (ft_strchr(PREFLAGS, *sub) || ft_strchr(FLAGS, *sub) \
			|| ft_strchr(NUMERICS, *sub) || *sub == '$')
		sub++;
	if (ft_strchr(CONVERTERS, *sub))
		return (ft_strsub(str, 0, sub - str + 1));
	else
		return (NULL);
}

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
			{
				ft_putendl("param_list foiré");
				return (NULL);
			}
		}
		ptr = ptr->next;
	}
	return (start);
}