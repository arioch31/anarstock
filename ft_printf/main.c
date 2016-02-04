/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 03:03:20 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/04 18:39:03 by aeguzqui         ###   ########.fr       */
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
	d = ft_printf("\"test %%i %%c %% test de valist: %%D  %%ldaaaaa\", i, j , k \n");

	d = ft_printf("test %i %c %% test de valist: %D  %ldaaaaa\n", i, j , k );
/*
	   str = ft_strdup("test ok");
	   ft_putendl(padd_zero(str, 16));
	   str = ft_strdup("test ok");
	   ft_putendl(padd_right(str, 16));
	   str = ft_strdup("test ok");
	   ft_putendl(padd_left(str, 16));*/

	return (0);
}
