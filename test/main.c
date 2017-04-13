/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 23:50:45 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/04/13 03:07:15 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void f1(int i)
{
	printf("f1 -> %d\n", i);
}

void f2(int i)
{
	printf("f2 -> %d\n", i);
}

void f3(int i)
{
	printf("f3 -> %d\n", i);
}

void f4(int i)
{
	printf("f4 -> %d\n", i);
}

typedef void (*fct)(int i);

static const fct	g_tab[] =
{
	[0] = f1,
	[6] = f2,
	[1] = f3,
	[2] = f4,
};

int main (void)
{
	int i;

	i = -1;
	while (++i < 8)
	{
		if (!g_tab[i])
		printf("tab[%d] vide\n", i);
		else
			g_tab[i](i);
	}
	printf("%2$*4$.*3$d %d\n",8, 6, 4, 9);
	return (0);
}
