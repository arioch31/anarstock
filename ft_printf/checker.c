/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 03:03:20 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/01/26 17:53:00 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int get_dollar(t_param *p, char *str)
{
    int i;

    i = 0;
    if (*str != '0' && ft_strchr(NUMERICS, *str))
    {
        i = ft_atoi(str);
        while (ft_strchr(NUMERICS, *str))
            str++;
        if (*str == '$')
        {
            if (!i)
                return (-1);
            p->p_index = i;
            return (1);
        }
    }
    p->p_index = 0;
    return (0);
}

int get_sizes(t_param *p, char *str)
{
    while (ft_strchr(PREFLAGS, *str))
        p->padding = ft_strjoin(p->padding, ft_strsub(str++, 0, 1));
    p->withd = ft_atoi(str);
    while (ft_strchr(NUMERICS, *str))
        str++;
    if (*str == '.')
    {
        p->precision = ft_atoi(++str);
        while (ft_strchr(NUMERICS, *str))
            str++;
    }
    return (get_types(p, str));
}

int get_types(t_param *p, char *str)
{
    if ((*str == 'h' || *str == 'l') && *str == *(str + 1))
    {
        p->length = *(str) - 1;
        str += 2;
    }
    else if (ft_strchr(FLAGS, *str))
        p->length = *(str++);
    if (ft_strchr(CONVERTERS, *str))
    {
        p->type = *str;
        return (1);
    }
    return (0);
}

char    *arg_sub(const char *str)
{
    char    *sub;
    
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
