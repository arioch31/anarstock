/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 03:55:16 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/07/13 01:20:19 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_3d.h"

double	*new_matrix(void)
{
	double		*mat;
	int			i;
	int			j;

	mat = malloc(sizeof(double) * 16);
	i = -1;
	while (++i < 16)
	{
		mat[i] = 0.0;
	}
	i = -1;
	while (++i < 4)
		mat[i * 5] = 1.0;
	return (mat);
}

double	*copy_matrix(double *m1)
{
	double		*m2;
	int			i;

	m2 = new_matrix();
	i = -1;
	while (++i < 16)
		m2[i] = m1[i];
	return (m2);
}

double	*mult_matrix(double *m1, double *m2)
{
	double		*m3;
	int			i;
	int			j;
	int			k;

	m3 = new_matrix();
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			m3[i * 4 + j] = 0.0;
			k = -1;
			while (++k < 4)
				m3[i * 4 + j] += m1[i * 4 + k] * m2[k * 4 + j];
		}
	}
	return (m3);
}

void	translate_matrix(double *m, t_vector *v)
{
	m[3] += v->x;
	m[7] += v->y;
	m[11] += v->z;
	m[15] += v->w;
}

double	*rot_matrix(double angle, char axis)
{
	double	*mat;

	mat = new_matrix();
	if (axis == 'x')
	{
		mat[5] = cos(angle);
		mat[10] = cos(angle);
		mat[6] = -sin(angle);
		mat[9] = sin(angle);
	}
	else if (axis == 'y')
	{
		mat[0] = cos(angle);
		mat[10] = cos(angle);
		mat[2] = -sin(angle);
		mat[8] = sin(angle);
	}
	else if (axis == 'z')
	{
		mat[5] = cos(angle);
		mat[0] = cos(angle);
		mat[4] = -sin(angle);
		mat[1] = sin(angle);
	}
	return (mat);
}
