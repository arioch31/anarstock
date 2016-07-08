/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 06:39:53 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/07/08 06:40:44 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putdouble(double nb, int precision)
{
	int		expo;
	int		cpt;

	expo = 1;
	cpt = 0;
	while (cpt++ < precision)
		expo *= 10;
	ft_putnbr((int)nb);
	ft_putchar('.');
	if (precision)
		ft_putnbr((int)(nb * expo) % expo);
}
