/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:14:48 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/05/05 02:26:36 by aeguzqui         ###   ########.fr       */
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
	char	*ptr2;
	int		test;
	int		ret;

	ptr = (char*)str;
	while (*ptr)
	{
		if (!(ptr2 = ft_strchr(ptr, '%')))
			test = ft_strlen(ptr);
		else if (*ptr != '%')
			test = ptr2 - ptr;
		else if (!(test = arg_len(ptr)))
			return (-1);
		else
		{
			ptr += test;
			test = 0;
			ret += print_arg(fd, ptr, ap, ret);
		}
		write(fd, &ptr, test);
		ptr += test;
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
