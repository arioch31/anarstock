/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 03:03:20 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/01/25 19:13:06 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
//#include "ft_printf.h"

char		*arg_cutter(const char *arg)
{
	int		i;
	char	charset[22] = "0123456789$+- #hljztL.";
	char	charset2[23] = "dDiuUxXoOfFeEgGaAcCsSpn";

	i = 1;
	if (arg[0] != '%')
		return (NULL);
	while (ft_strchr(charset, arg[i]))
		i++;
	if (ft_strchr(charset2, arg[i]))
		return (ft_strsub(arg, 0, i + 1));
	else
		return (NULL);
}

t_list		*arg_dissect(const char *str)
{
	t_list	*start;
	char	*tmp;

	start = NULL;
	while (*str)
	{
		tmp = ft_strsub(str, 0, ft_lenword(str, '%'));
		if (*tmp)
		{
			ft_lstapp(&start, ft_lstnew(tmp, ft_strlen(tmp)));
			ft_putstr("->");
			ft_putendl(tmp);
			str += ft_lenword(str, '%');
		}
		if (*(str + 1) == '%')
		{
			ft_lstapp(&start, ft_lstnew("%", 1));
			str += 2;
		}
		else if ((tmp = arg_cutter(str)))
		{
			ft_lstapp(&start, ft_lstnew(tmp, ft_strlen(tmp)));
			str += ft_strlen(tmp);
		}
		else
			return (NULL);//exit(wrong format param)?
	}
	return (start);
}

void		delet(void *content, size_t content_size)
{
	ft_bzero(content, content_size);
	free(content);
	content_size = 0;
}

int			ft_printf(const char *str, ...)
{
	va_list	ap;
	char	*buffer;
	t_list	*test;
	t_list	*start;

	if (!str)
	{
		ft_putendl("NULL");
		return (1);
	}
	if (!str[ft_lenword(str, '%')])
	{
		ft_putendl(str);
		return (1);
	}
	test = NULL;
	test = arg_dissect(str);
	if (test)
		ft_lstaff(test);
	start = test;
	buffer = ft_strnew(0);
	while (test)
	{
		buffer = ft_strjoin(buffer, test->content);
		test = test->next;
	}
	ft_lstdel(&start, *delet);
	ft_putendl("test");
	ft_putendl(buffer);
	ft_lstaff(start);
	return (1);
}

int			main(void)
{
	int  d;
	char c;
	char *str;

	d = 88;
	c = ';';
	str = "test ok";
		ft_putendl("%hhftest de valist: % hhd%s coin-coin %n test  d %0$hhljd %% %1.112S%d");
	d =  ft_printf("%hhftest de valist: % hhd%s coin-coin %n test  d %0$hhljd %% %1.112S%d", d, c, str);
	return (0);
}
