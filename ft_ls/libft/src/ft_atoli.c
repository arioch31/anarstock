/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoli.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:46:42 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/06/08 16:24:09 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atoli(char *str)
{
	int			i;
	long int	res;
	int			neg;

	neg = 0;
	i = 0;
	res = 0;
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		neg = 1;
		i++;
	}
	if (str[i] == '+' && !neg)
		i++;
	while (ft_isdigit(str[i]))
	{
		res = 10 * res + str[i] - 48;
		i++;
	}
	if (neg)
		res = -res;
	return (res);
}
