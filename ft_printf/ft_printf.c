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
#include <stdarg.h>

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	char	*tmp;
	char 	*foireux;
	char 	*foireux2;
	
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
	va_start(ap, str);
	foireux = ft_strdup(str);
	while (ft_lenword(foireux, '%') != ft_strlen(foireux) && (foireux = ft_strchr(foireux, '%') + 1))
	{
		if (*foireux == 'd')
			tmp = ft_strjoin(str, ft_itoa(va_arg(ap, int)));
		if (*foireux == 'c')
		{
			foireux2 = malloc(1);
			*foireux2 =  va_arg(ap, int);
			tmp = ft_strjoin(tmp, foireux2);
		}
		if (*foireux == 's')
			tmp = ft_strjoin(tmp, va_arg(ap, char* ));
		ft_putendl(tmp);
	}
	ft_putendl(tmp);
	va_end(ap);
	return (1);
}

char **decoupe_string(char *str)
{
	char 	**tab;
	int		nb;
	int		i;

	i = 0;
	nb = 1;
	while(str[i])
	{
		i += ft_lenword(str, '%');
		while (str[i] && !ft_ispace(str[i]))//!!!!!!!! pas espace en fait, mais caratere de conversion
			i++;
		nb++;
	}	
	
}

int main (void)
{
	int  d;
	char c;
	char *str;

	d = 88;
	c = ';';
	str = "test ok";

	d = ft_printf("test de valist:  %d texte %c\t%s\n", d, c, str);
	return (0);
}
