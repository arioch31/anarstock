/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 03:09:28 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/05/28 13:51:36 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include "ft_printf.h"
#include <stdio.h>

int main (void)
{
//  wchar_t   test[] = {L'猫',L'猫' + 1, L'猫' +2,0x0373, 0x0374, 0x1750, 0x1751, 0x0};
  int i,j;
  char *truc;

  truc = setlocale(LC_ALL, "");
  i = ft_printf("\n%S", L"猫猫猫猫猫猫猫猫猫猫猫猫猫猫猫猫猫猫猫");
  j =    printf("\n%S", L"猫猫猫猫猫猫猫猫猫猫猫猫猫猫猫猫猫猫猫");

  printf("\nft %d\t pf %d\n", i, j);
  printf("%s\n",truc );
  /*j = printf("%2c", 0);
  printf("\n");
  printf("ft %d  \tpf %d", i, j);
*/


return (0);
}
