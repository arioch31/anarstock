/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 20:36:02 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/04/21 21:54:08 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_wctolint(wchar_t wc)
{
	if (wc < 0x80)
		return ((long int)wc);
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

char		*ft_wctostr(wchar_t wc)
{
	char		*res;
	char		c;
	int			i;
	long long	tmp;

	i = 0;
	if (!wc)
		return (ft_strdup("\0"));
	tmp = ft_wctolint(wc);
	res = ft_strnew(5);
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
	res[i] = '\0';
	return (res);
}

char		*ft_strwctostr(wchar_t *wc)
{
	char		*str;
	char		*ptr;
	char		*ptr2;

	if (wc == 0)
		return (NULL);
	str = NULL;
	while (*wc)
	{
		ptr = ft_wctostr(*wc);
		ptr2 = ft_strjoin(str, ptr);
		free(ptr);
		free(str);
		str = ptr2;
		wc++;
	}
	return (str);
}
