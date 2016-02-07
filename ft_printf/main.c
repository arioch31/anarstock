/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 03:03:20 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/04 18:55:41 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main (void)
{
	int  d;
	char c;
	short i, j ,k;

	d = 42;
	c = -42;
	i = -1;

	j = 32767;//?
	k = -1;
	 ft_printf("\"test %%i %%c %% test de valist: %%D  %%ldaaaaa\", i, d,j , k \n");

	 ft_printf("test %i %c %% test de valist: %D  %ldaaaaa\n", i, d, j , k );
	ft_printf("test %%c %c \n", d);
	ft_printf("test ft %%hho %hho \n", i);
	printf("test pf %%hho %hho \n", i);

	ft_printf("test ft %% #x %#x \n", i);
	printf("test pf %%#x %#x \n", i);

	ft_printf("test ft %%x %x \n", i);
	printf("test pf %%x %x \n", i);

	ft_printf("test ft %%#X %#X \n", i);
	printf("test pf %%#X %#X \n", i);

	ft_printf("test ft %%u %u \n", i);
	printf("test pf %%u %u \n", i);
	
	ft_printf("test ft %%i %i \n", i);
	printf("test pf %%i %i \n", i);


	ft_printf("test ft %%hhu %hhu \n", i);
	printf("test pf %%hhu %hhu \n", i);

	ft_printf("test ft %%c %c \n", d + 513);
	printf("test pf %%c %c \n", d + 513);


	ft_printf("test ft %%s %s \n", "test ok!");
	return (0);
}
