/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 03:03:20 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/08 14:15:54 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

int main(void)
{
	int  d;
	char c;
	short i, j ,k;
	int		*ptr;
	int		test;
	int		tab[80];
	wchar_t	c_test;
	wchar_t	*s_test;
	setlocale(LC_ALL, "");
	d = 42;
	c = -42;
	i = 0;
	while (i < 80)
	{
		tab[i] = d + i;
		i++;
	}

	c_test = 42;

	j = 32767;//?
	k = -1;
	ptr = malloc(sizeof(int));
	s_test = (wchar_t *)ptr;
	*s_test = c_test;
	*(s_test + 1) = 947;
	tab[0] = (int)c_test;
	tab[1] = 948;
	d = 947;
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
		ft_printf("test ft %%p %p \n", &k);
		printf("test pf %%p %p \n", &k);
		ft_printf("test ft %%p %p \n", NULL);
		printf("test pf %%p %p \n", NULL);
		ft_printf("test ft %%p %p \n", &i);
		printf("test pf %%p %p \n", &i);
		ft_printf("test ptr %d\n", *ptr);
		ft_printf("test ft %%n %n %d\n", ptr, *ptr, j);
		ft_printf("test ptr %d\n", *ptr);
		printf("test 123456789 pf %%n %n %d %d\n", ptr, *ptr, j);
		ft_printf("test ptr %d\n", *ptr);
	}
	ft_printf("_________________________________");
	ft_printf("test ft %%p %p \n", NULL);
	printf("test pf %%d %d \n", tab[0]);
	printf("test pf %%C %C \n", c_test);
	printf("test pf %%C %C \n", 947);
	printf("test pf %%S %S \n", s_test);
	write(1, tab, 8);
	return (0);
}
