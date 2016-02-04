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
		ft_printf("test %%o %o \n", i);
		printf("test %%o %o \n", i);

	return (0);
}
