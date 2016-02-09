/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 03:03:20 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/10 00:40:08 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

int main(void)
{
	int  d;

	int i, j ,k;
	int		*ptr;
	int		test;
	int		tab[80];
	wchar_t	c;
	wchar_t	*s_test;
	wchar_t *str;

	setlocale(LC_ALL, "");

	test = 0;
	if (test)
	{
		ft_printf("\"test %%i %%c %% test de valist: %%D  %%ldaaaaa\", i, d,j , k \n");
		ft_printf("test %i %c %% test de valist: %D  %ldaaaaa\n", i, d, j , k );
		ft_printf("test %%c %c \n", d);
		ft_printf("test ft %%#hho %#hho \n", i);
		printf("test pf %%#hho %#hho \n", (char)i);
		ft_printf("test ft %%#x %#x \n", i);
		printf("test pf %%#x %#x \n", i);
		ft_printf("test ft %%x %x \n", i);
		printf("test pf %%x %x \n", i);
		ft_printf("_________________________________");
		ft_printf("test %%d %d", k);
		printf("test %%d %d", k);
		ft_printf("test ft %%#X %#X \n", i);
		printf("test pf %%#X %#X \n", i);
		ft_printf("test ft %%u %u \n", i);
		printf("test pf %%u %u \n", i);
		ft_printf("test ft %%i %i \n", i);
		printf("test pf %%i %i \n", i);
		ft_printf("test ft %%hhu %hhu \n", i);
		printf("test pf %%hhu %hhu \n", (char)i);
		ft_printf("test ft %%hhu %hhu \n", (char)i);
		printf("test pf %%hhu %hhu \n", (char)i);
		ft_printf("test ft %%hhd %hhd \n", (char)250);
		printf("test pf %%hhd %hhd \n", (char)250);
		ft_printf("test ft %%c %c \n", d + 513);
		printf("test pf %%c %c \n", d + 513);
		ft_printf("test ft %%s %s \n", "test ok!");
		ft_printf("_________________________________");
		ft_printf("test ft %%p %p \n", NULL);
		printf("test pf %%p %p \n", NULL);
		ft_printf("test ft %%p %p \n", &d);
		printf("test pf %%p %p \n", &d);
		ft_printf("_________________________________");
		ft_printf("test ft %%p %p \n", &k);
		printf("test pf %%p %p \n", &k);
		ft_printf("test ft %%p %p \n", NULL);
		printf("test pf %%p %p \n", NULL);
		ft_printf("test ft %%p %p \n", &i);
		printf("test pf %%p %p \n", &i);
		ft_printf("test2 ------------------------------------\n");
		printf("test1 ------------------------------------\n");
		ft_printf("_________________________________");
  	str = malloc(sizeof(wchar_t) * 12);
  	c = 42;
	  *str = c;
	  *(str + 1) = c + 1;
	  *(str + 2) = c + 2;
	  *(str + 3) = c + 3;
	  *(str + 4) = 42;
		ft_printf("%%S = \t%S \n",str);
		printf("%%S = \t%S \n",str);
	  c = 42;
	  *(str + 5) = c;
	  *(str + 6) = c + 1;
	  *(str + 7) = c + 2;
	  *(str + 8) = c + 3;
		ft_printf("%%S = \t%S \n",str);
		printf("%%S = \t%S \n",str);
	  c = 5210;
	  *(str + 9) = c + 1;
	  *(str + 10) = c + 2;
	  *(str + 11) = c + 3;
		ft_printf("%%S = \t%S \t%S\n",str, str + 4);
		printf("%%S = \t%S \t%S\n",str, str + 4);
		ft_printf("%%S = \t%S \n",str);
		printf("%%S = \t%S \n",str);
	}

	ft_printf(NULL);
	ft_printf("This is a simple test.\n");
	i = ft_printf("ft%3c",0);
	ft_putendl("");
	j = printf("pf%3c", 0);

	printf("\nft %d \tpf %d",i, j);
	return (0);
}
