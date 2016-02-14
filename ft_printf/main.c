/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 03:09:28 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/14 23:10:55 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main (void)
{
  int i,j;

  i = ft_printf("%2c", 0);
  ft_printf("\n");
  ft_printf("%-2c", 0);
  ft_printf("\n");

  /*j = printf("%2c", 0);
  printf("\n");
  printf("ft %d  \tpf %d", i, j);
*/


return (0);
}
