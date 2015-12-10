/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 22:26:56 by aeguzqui          #+#    #+#             */
/*   Updated: 2015/12/07 19:51:04 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_temp(char *res, int nb)
{
	int				coeff;
	unsigned int	i;

	i = 0;
	coeff = 1000000000;
	if (nb < 0)
	{
		nb = -nb;
		res[i] = '-';
		i++;
	}
	while (coeff > nb)
		coeff = coeff / 10;
	while (coeff > 0)
	{
		res[i] = nb / coeff + 48;
		nb = nb % coeff;
		coeff = coeff / 10;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char		*ft_itoa(int n)
{
	char *res;

	res = NULL;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if ((res = (char*)malloc(12 * sizeof(char))))
		res = ft_temp(res, n);
	return (res);
}
