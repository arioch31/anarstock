/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 03:09:28 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/12 04:33:11 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main (void)
{

  ft_printf(NULL);
  ft_printf("\n");

  ft_printf("%d", 1);
  ft_printf("\n");
  ft_putendl("test %%%%%%%%%%%%%%%%%%%%%%%%%%");

  ft_printf("%%");
  ft_printf("\n");
   ft_printf("%d is one\n", 1);
   ft_printf("%lld", -9223372036854775807 - 1);

/*
    ft_printf("%5%");
    ft_printf("\n");

    ft_printf("%-5%");
    ft_printf("\n");

 ft_printf("%.0%");
 ft_printf("\n");

   ft_printf("%%", "test");
   ft_printf("\n");

 ft_printf("%   %", "test");
 */return (0);
}
