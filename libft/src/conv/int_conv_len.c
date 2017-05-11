/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_conv_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 04:43:49 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/05/11 04:45:58 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	uint_strlen(uintmax_t n, int base)
{
	int			nb;
	uintmax_t	cpt;

	cpt = n;
	nb = 1;
	while (cpt)
	{
		nb++;
		cpt = cpt / base;
	}
	return (nb);
}

int	int_strlen(intmax_t n)
{
	int			nb;
	intmax_t	cpt;

	nb = 1;
	if (n < 0)
	{
		nb++;
		cpt = -n;
	}
	else
		cpt = n;
	while (cpt)
	{
		nb++;
		cpt = cpt / base;
	}
	return (nb);
}
