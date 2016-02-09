/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 20:36:02 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/09 21:32:01 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_wctolint(wchar_t wc)
{
	if (wc < 0x80)
		return ((int)wc);
	if (wc < 0x1000)
		return (0xc080 + ((wc / 0x40) * 0x100) + (wc % 0x40));
	if (wc < 0x20000)
		return (0xe08080 + (wc / 0x1000) * 0x10000  \
				+ (wc % 0x1000 / 0x40) * 0x100 + wc % 0x40);
	else
		return (0xf0808080 + ((wc % 0x200000) / 0x40000) * 0x1000000 \
				+ ((wc % 0x40000) / 0x1000) * 0x10000 \
				+ (wc % 0x1000 / 0x40) * 0x100 + wc % 0x40);
}

int			ft_writewc(wchar_t wc)
{
	long long	tmp;
	char		part[4];
	int			i;

	i = 0;
	tmp = ft_wctolint(wc);
	part[0] = (char)(tmp / 0x1000000);
	part[1] = (char)(tmp % 0x1000000 / 0x10000);
	part[2] = (char)(tmp % 0x10000 / 0x100);
	part[3] = (char)(tmp % 0x100);
	if (part[0])
		write(1, &part[1], 1);
	if (part[1])
		write(1, &part[2], 1);
	if (part[2])
		write(1, &part[3], 1);
	if (part[3])
		write(1, &part[4], 1);
	i = !!part[1] + !!part[2] + !!part[3] + !!part[0];
	return (i);
}

char		*ft_wctostr(wchar_t wc)
{
	char		*res;
	char		c;
	int			i;
	long long	tmp;

	i = 0;
	tmp = ft_wctolint(wc);
	res = ft_strnew(4);
	c = (char)(tmp / 0x1000000);
	if (c)
		res[i++] = c;
	c = (char)(tmp % 0x1000000 / 0x10000);
	if (c)
		res[i++] = c;
	c = (char)(tmp % 0x10000 / 0x100);
	if (c)
		res[i++] = c;
	c = (char)(tmp % 0x100);
	if (c)
		res[i++] = c;
	return (res);
}

char		*ft_strwctostr(wchar_t *wc)
{
	char		*str;

	while (*wc)
	{
		str = ft_strjoin(str, ft_wctostr(*wc));
		wc++;
	}
	return (str);
}

int			ft_writeswc(wchar_t *wc)
{
	int			i;

	i = 0;
	while (*(wc + i))
	{
		ft_writewc(*(wc + i));
		i++;
	}
	return (i);
}
