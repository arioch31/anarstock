/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 03:03:20 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/01/28 04:56:54 by aeguzqui         ###   ########.fr       */
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
		if(p->length == 'l' && p->type >= 'a' && p->type <= 'x' && p->type != 'n' && p->type != 'p')
		{
			p->length = 0;
			p->type += 'A' - 'a';
		}
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

int 	err_checker(t_param *p)
{
	char	*ptr;

	ptr = p->padding;
	if (p->withd && p->precision > p->withd)
	   return (0);	
	while (*(ptr++))
		if (ft_strchr(ptr + 1, *ptr))
			return (0);
	if ((p->type == 's' || p->type == 'S') && (*(p->padding) && *(p->padding) != '-'))
			return (0);
	if (ft_strchr(FLOAT_CONV, p->type) && ft_strchr(FLOAT_FORB, p->length))
			return (0);
	 if ((p->type == 'c' || p->type == 'C') && 
			 (p->precision || (*(p->padding) && *(p->padding) != '-')))
			return (0);
	 if (ft_strchr(INT_CONV, p->type) && p->length == 'L')
		return (0);
	 if (ft_strchr(p->padding, '#') && (!ft_strchr(HASH_VALID, p->type)
				 || ft_strchr(p->padding,' ') || ft_strchr(p->padding,'0')))
		return (0);
	 if (p->type == '%')
		return (!ft_strequ(*(p->ptr), "%%"));
	 if (p->type == 'n')
		return (!ft_strequ(*(p->ptr), "%n"));
	return (1);
}
