/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 03:03:20 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/01/28 03:36:57 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main (void)
{
	int  d;
	char c;
	short i;
	unsigned long long	l;
	long long k;

	d = 88;
	c = -42;
	i = -1;

	l = 18446744073709551615ULL;//?
	k = -1;
	//d = ft_printf("%itest de%D valist:\n%D \n%ld\n", i,ULONG_MAX - (unsigned long long)k, ULONG_MAX-10 , k );
	while (++i < 51)
	{
	 ft_printf("%D \n",ULONG_MAX - (unsigned long long)i);
	printf("%lO max ull -%hd\n", ULONG_MAX-i, i);
	}
	/*
	   str = ft_strdup("test ok");
	   ft_putendl(padd_zero(str, 16));
	   str = ft_strdup("test ok");
	   ft_putendl(padd_right(str, 16));
	   str = ft_strdup("test ok");
	   ft_putendl(padd_left(str, 16));*/

	return (0);
}
