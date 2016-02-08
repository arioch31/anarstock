/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wc_gestion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:08:33 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/08 14:14:42 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long int  ft_wctoint(wchar_t wc)
{
  if (wc < 0x7f)
    return ((int)wc);
  if (wc < 0x800)
      return (0xc080 +(wc / 0x80) * 0x100 + wc % 0x80);
  if (wc < 0x10000)
    return (0xd08080 +(wc / 0x1000)* 0x10000  + ((wc % 0x1000 / 0x80) * 0x100 + wc % 0x80);
  else
    return (0xe0808080 + (wc / 0x40000) * 0x1000000 + ((wc % 0x40000) / 0x1000)* 0x10000 + (wc % 0x1000 / 0x80) * 0x100 + wc % 0x80);
}
