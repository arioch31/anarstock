/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 03:03:20 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/01/26 13:20:37 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>


char    *arg_sub(const char *str)
{
    char    *sub;
    
    if (!str || *str != '%')
        return (NULL);
    sub = (char*)str;
    sub++;
    while (ft_strchr(PREFLAGS, *sub) || ft_strchr(FLAGS, *sub))
        sub++;
    if (ft_strchr(CONVERTERS, *sub))
        return (ft_strsub(str, 0, ++sub - str));
    else
        return (NULL);
}

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
            if(*ptr)
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
            ft_lstapp(&start, ft_lstnew(test, ft_strlen(test)));
            ptr += ft_strlen(test);
        }
    }
    return (start);
}

int	ft_printf(const char *str, ...)
{
    va_list	ap;
    t_list  *l_sp;
    t_list  *l_vp;
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
    l_sp = arg_dissect(str);
    if (!l_sp)
        return (0);
    ft_lstaff(l_sp);
    start = l_sp;
    va_start(ap, str);
    l_vp = NULL;
    while(start)
    {
        if ((tmp = ((char*)start->content)))
            if (*tmp== '%')
            {
                c = *(tmp+1);
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
                 //   start->content = padd_zero(ft_itoa(va_arg(ap, int)), 3);
                //       else if (c == 'u')
                //       start->content = ft_itoa((unsigned int)va_arg(ap, int));
                /* else if (c == 'o')
                 return (ft_printoctal(ap));
                 else if (c == 'x')
                 return (ft_printhexa(ap));
                 else if (c == 'p')
                 return (ft_printvoid(ap));
                 else if (c == '%')
                 return (ft_putchar(c));
                 else if (c == 's')
                 return (ft_printstr(ap));*/
            }
        //if (ft_strchr("dDioOuUxX", tmp[ft_strlen(tmp) - 1]))
        //  elem= ft_lstnew(va_arg(ap, int),sizeof(int));
        //else if (ft_strchr("aAeEfFgG", tmp[ft_strlen(tmp) - 1]))
        //  elem= ft_lstnew(va_arg(ap, float),sizeof(float));
        
        start = start->next;
    }
    va_end(ap);
    ft_lstaff(l_sp);
    tmp = ft_strnew(0);
    start = l_sp;
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
    char *str;
    
    d = 88;
    c = ';';
    
    
    str = ft_strdup("test ok");
	d = ft_printf("%itest de%% valist:%d %i %c", 8,9,256 , 42);
    ft_putendl(padd_zero(str, 16));
    str = ft_strdup("test ok");
    ft_putendl(padd_right(str, 16));
    str = ft_strdup("test ok");
    ft_putendl(padd_left(str, 16));
	return (0);
}
