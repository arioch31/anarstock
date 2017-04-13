/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 23:50:45 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/04/13 05:43:10 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int main (int ac, char **av)
{
	int i, j;
	char **tab;

	i = 0;
	while (++i < ac)
	{
		tab = ft_strsplit_charset(av[i], " \t\nt");
		j = 0;
		while (tab[j])
			printf("%s\t", tab[j++]);
	}
	return (0);
}
