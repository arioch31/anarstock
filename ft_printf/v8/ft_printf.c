/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:14:48 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/05/11 02:02:27 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int		inner_pf(int fd, const char *str, va_list *ap)
{
	char	*ptr;
	int		test;
	int		ret;

	while (*str)
	{
		if (*str == '%' && (test = arg_len(str)))
		{
			str += test;
			test = print_arg(fd, str, ap, ret);
		}
		else if (*str == '%' && !(test > 0))
			return (-1);
		else
		{
			if (!(ptr2 = ft_strchr(str, '%')))
				test = ft_strlen(str);
			else
				test = ptr - str;
			write(fd, &str, test);
			str += test;
		}
		ret += test;
	}
	return (ret);
}

int		ft_vprintf(int fd, const char *str, ...)
{
	va_list		ap;
	int			ret;

	if (!str)
	{
		ft_putstr_fd("(null)", fd);
		return (1);
	}
	if (!(ret = check_format(str) || !(ret > 0)))
		return (-1);
	if (!ret)
	{
		ft_putstr_fd(str, fd);
		return (ft_strlen(str));
	}
	va_start(ap, str);
	ret = inner_pf(fd, str, &ap);
	va_end(ap);
	return (ret);
}

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	int			ret;

	if (!str)
	{
		ft_putstr("(null)");
		return (1);
	}
	if (!(ret = check_format(str) || !(ret > 0)))
		return (-1);
	if (!ret)
	{
		ft_putstr(str);
		return (ft_strlen(str));
	}
	va_start(ap, str);
	ret = inner_pf(1, str, &ap);
	va_end(ap);
	return (ret);
}
