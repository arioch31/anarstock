/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 01:47:01 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/07/25 01:39:16 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_3d.h"

double	*proj_matrix(double angle, double ratio, double near, double far)
{
	double	*m;

	m = new_matrix();
	m[0] = 1 / (ratio * tan(angle * M_PI / 360));
	m[5] = 1 / tan(angle * M_PI / 360);
	m[10] = (near + far) / (near - far);
	m[11] = 2 * far * near / (near - far);
	m[14] = -1;
	m[15] = 0;
	return (m);
}

void	scale_matrix(double *mat, double scale)
{
	int i;

	i = 0;
	while (i < 11)
	{
		if ((i + 1) % 4)
			mat[i] *= scale;
		i++;
	}
}

t_3dpt	*matrix_point(double *mat, t_3dpt *p)
{
	double		x;
	double		y;
	double		z;
	double		w;

	x = mat[0] * p->x + mat[1] * p->y + mat[2] * p->z + mat[3] * p->w;
	y = mat[4] * p->x + mat[5] * p->y + mat[6] * p->z + mat[7] * p->w;
	z = mat[8] * p->x + mat[9] * p->y + mat[10] * p->z + mat[11] * p->w;
	w = mat[12] * p->x + mat[13] * p->y + mat[14] * p->z + mat[15] * p->w;
	return (new_3dpoint(x, y, z));
}
