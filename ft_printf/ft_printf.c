/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 03:03:20 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/01/21 06:00:15 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include "ft_printf.h"
#include <stdarg.h>


char    *arg_sub(const char *str)
{
    char    *sub;
    char    *charset;
    char    *charset2;

    charset = "0123456789-+. $hlLjtz";
    charset2 = "dDiuUoOxXeEfFaAgGcCsSp%";
    sub = (char*)str;
    if (*str != '%')
        return (NULL);
    sub++;
    while (ft_strchr(charset, *sub))
        sub++;
    if (ft_strchr(charset2, *sub))
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
        test = ft_strsub(ptr, 0, ft_strchr(ptr, '%') - ptr);
        ft_lstapp(&start, ft_lstnew(test, ft_strlen(test)));
        ptr = ft_strchr(ptr, '%');
        if (!(test = arg_sub(ptr)))
            return(NULL);
        ft_lstapp(&start, ft_lstnew(test, ft_strlen(test)));
        ptr += ft_strlen(test);
        if(!ft_strchr(ptr, '%'))
        {
            ft_lstapp(&start, ft_lstnew(ptr, ft_strlen(ptr)));
            return (start);
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
    // ft_lstaff(start);
    ft_lstaff(l_sp);
    start = l_sp;
    va_start(ap, str);
    l_vp = NULL;
    while(start)
    {
        tmp = ((char*)start->content);
        if (*tmp== '%')
        {
            if (ft_strchr("dDioOuUxX", tmp[ft_strlen(tmp) - 1]))
            elem= ft_lstnew(&va_arg(ap, int),sizeof(int));
        //    else if (ft_strchr("aAeEfFgG", tmp[ft_strlen(tmp) - 1]))
        //    elem= ft_lstnew(va_arg(ap, float),sizeof(float));
            ft_lstapp(&l_vp, elem);
        }
        start = start->next;
    }
    va_end(ap);
    ft_lstaff(l_vp);
    tmp = ft_strnew(0);
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
    str = "test ok";

    d = ft_printf("%lutest de valist:%d %% %d", 8,9,256 , str);
    return (0);
}
