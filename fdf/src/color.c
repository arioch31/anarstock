/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 07:11:13 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/11/16 07:38:24 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_3d.h"

char	degrade_color(int pt, int len, char t1, char t2)
{
	return ((char)(pt / (double)len) * (t2 - t1) + t1);
}

int		degrade(int pt, int len, int color1, int color2)
{
	char	rgb1[3];
	char	rgb2[3];
	char	res[3];

	rgb1[2] = color1 % 256;
	rgb1[1] = color1 / 256 % 256;
	rgb1[0] = color1 / 256 / 256 % 256;
	rgb2[2] = color2 % 256;
	rgb2[1] = color2 / 256 % 256;
	rgb2[0] = color2 / 256 / 256 % 256;
	res[0] = degrade_color(pt, len, rgb1[0], rgb2[0]);
	res[1] = degrade_color(pt, len, rgb1[1], rgb2[1]);
	res[2] = degrade_color(pt, len, rgb1[2], rgb2[2]);
	return (res[0] * 256 * 256 + res[1] * 256 + res[2]);
}
