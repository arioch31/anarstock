/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 03:03:20 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/01/28 09:04:55 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list *arg_dissect(const char *str)
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
				return(NULL);//exit free?
			ft_lstapp(&start, ft_lstnew(test, ft_strlen(test) + 1));
			ptr += ft_strlen(test);
		}
	}
	return (start);
}

int controler(t_param *p, va_list ap)
{

	return(1);
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
				return (NULL);
		}
		ptr = ptr->next;
	}
	return (start);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	t_param	*test;
	t_list  *lst;
	t_list  *start;
	char    c;
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
	lst = arg_dissect(str);
	if (!lst)
		return (0);
	ft_lstaff(lst);
	va_start(ap, str);
	test = param_list(lst);
	while (test)
	{
		ft_putendl("test2");
	//	*(test->ptr) = ft_strdup("test ok");
		aff_param(test);
		test = test->next;
	}	
/*	start = lst;
	while(start)
	{
		if ((tmp = ((char*)start->content)))
			if (*tmp== '%')
			{
				if ((test = arg_decrypt(tmp)))
				{
					if (err_checker(test))
						ft_putendl("argument OK");
					else
						ft_putendl("argument error");
					//aff_param(test);
				}
				else
					return (0);
				tmp++;
				c = test->type;
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
					start->content = ft_ultoa_base(va_arg(ap, int), 10, 0);
				if (test)
				destr_param(test);

			}	
		start = start->next;
	}
*/
	va_end(ap);
	tmp = ft_strnew(0);
	start = lst;
	while (start)
	{
		tmp = ft_strjoin(tmp, start->content);
		start =start->next;
	}
	ft_putstr(tmp);

	return (1);
}
