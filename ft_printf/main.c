/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 03:03:20 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/01/28 04:33:23 by aeguzqui         ###   ########.fr       */
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

	d = 88;
	c = -42;
	i = -1;
	
	j = 32767;//?
	k = -1;
	d = ft_printf("%itest de valist:\n%D \n%ld\n", i, j , k );
/*
	   str = ft_strdup("test ok");
	   ft_putendl(padd_zero(str, 16));
	   str = ft_strdup("test ok");
	   ft_putendl(padd_right(str, 16));
	   str = ft_strdup("test ok");
	   ft_putendl(padd_left(str, 16));*/

	return (0);
}
