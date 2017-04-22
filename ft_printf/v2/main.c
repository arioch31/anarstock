/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 03:09:28 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/04/22 02:06:43 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int x,y;

	printf("\n%s\n", "test");
	ft_printf("lolol %1$d %slolol%s", 8, "tets", "test");

	printf("\n\n%12$d  %3$+*1$.*2$d %4$d", 8, 25, 5, 9);

	return (0);
}
