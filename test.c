/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:08:33 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/08 17:13:03 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include <stdio.h>

long int  ft_wctoint(wchar_t wc)
{
  if (wc < 0x80)
    return ((int)wc);
  if (wc < 0x1000)
      return (0xc080 +((wc / 0x40) * 0x100) + (wc % 0x40));
  if (wc < 0x20000)
    return (0xe08080 +(wc / 0x1000)* 0x10000  + (wc % 0x1000 / 0x40) * 0x100 + wc % 0x40);
  else
    return (0xf0808080 + ((wc % 0x200000) / 0x40000) * 0x1000000 + ((wc % 0x40000) / 0x1000) * 0x10000 + (wc % 0x1000 / 0x40) * 0x100 + wc % 0x40);
}

int   test_write(wchar_t *wc)
{
    long int  tmp;
    int       part1, part2, part3, part4;

    while (*wc)
    {
      tmp = ft_wctoint(*wc);

      part1 = (int)(tmp / 0x1000000);
      if (part1)
        write(1, &part1, 1);
      part2 = (int)(tmp % 0x1000000 / 0x10000);
      if (part2)
        write(1, &part2, 1);
      part3 = (int)(tmp % 0x10000 / 0x100);
      if (part3)
        write(1, &part3, 1);
      part4 = (int)(tmp % 0x100);
      if (part4)
        write(1, &part4, 1);
      wc++;
    }
    return (1);
}

int main (void)
{
  wchar_t c;
  wchar_t *str;
  int i;


  i = 0;
  printf("%s\n",setlocale(LC_ALL, ""));
//c = 945;
//c = 8178;
c = 32415;
  *str = c;
  *(str + 1) = c + 1;
  *(str + 2) = c + 2;
  *(str + 3) = c + 3;
  *(str + 4) = 42;
  *(str + 5) = 0;
  test_write(str);
  c = 0;
  printf("\n%S\n", str);
/*
  while (i < 0x2000)
  {
    printf("%C\t%d\n", c + i, (int)(c + i));
    i++;
  }
*/
}
