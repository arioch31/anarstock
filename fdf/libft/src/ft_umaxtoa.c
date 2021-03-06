/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_umaxtoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 22:26:56 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/09 22:52:14 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_temp(char *res, uintmax_t nb, int base, int maj)
{
	uintmax_t				coeff;
	unsigned int			i;
	char					*charset;
	char					*charset_maj;

	i = 0;
	charset = ft_strdup("0123456789abcdef");
	charset_maj = ft_strdup("0123456789ABCDEF");
	coeff = base;
	while (coeff < nb && coeff * base > coeff)
		coeff = coeff * base;
	while (coeff > nb)
		coeff = coeff / base;
	while (coeff > 0)
	{
		if (maj)
			res[i] = charset_maj[nb / coeff];
		else
			res[i] = charset[nb / coeff];
		nb = nb % coeff;
		coeff = coeff / base;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char		*ft_umaxtoa_base(uintmax_t n, int base, int maj)
{
	char		*res;
	int			nb;
	uintmax_t	cpt;

	res = NULL;
	if (base < 2 || base > 16)
		return (NULL);
	if (n == 0)
		return (ft_strdup("0"));
	cpt = n;
	nb = 1;
	while (cpt)
	{
		nb++;
		cpt = cpt / base;
	}
	if ((res = (char*)malloc(nb * sizeof(char))))
		res = ft_temp(res, n, base, maj);
	return (res);
}
