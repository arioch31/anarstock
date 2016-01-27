/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 03:03:20 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/01/26 17:53:00 by aeguzqui         ###   ########.fr       */
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
        else //factoriser ca
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

int	ft_printf(const char *str, ...)
{
    va_list	ap;
	t_param	*test;
    t_list  *lst;
    t_list  *start;
    t_list  *elem;
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
    start = lst;
    va_start(ap, str);
    while(start)
    {
        if ((tmp = ((char*)start->content)))
            if (*tmp== '%')
            {
           if ((test = arg_decrypt(tmp)))
				{
                   				//aff_param(test);
                destr_param(test);
				}
           tmp++;
             while(!ft_strchr(CONVERTERS,*tmp))
                    tmp++;
				c = *(tmp);
                if (c == '%')
                {
                    free(start->content);
                    tmp = ft_strnew(2);
                    *tmp = '%';
                    start->content = tmp;
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
	}
        start = start->next;
    }
	va_end(ap);
	ft_lstaff(lst);
    tmp = ft_strnew(0);
    start = lst;
    while (start)
    {
        tmp = ft_strjoin(tmp, start->content);
        start =start->next;
    }
    ft_putchar('\n');
    ft_putendl(tmp);
    
    return (1);
}

int main (void)
{
    int  d;
    char c;
    
    d = 88;
    c = ';';
    
	ft_putstr("%itest de%% valist:%d %hhd %c\n");
	d = ft_printf("%itest de%% valist:%d %hhd %c\n", 8,9,256 , 42);
	/*
	str = ft_strdup("test ok");
    ft_putendl(padd_zero(str, 16));
    str = ft_strdup("test ok");
    ft_putendl(padd_right(str, 16));
    str = ft_strdup("test ok");
    ft_putendl(padd_left(str, 16));*/

	return (0);
}
