/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 03:55:16 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/07/08 07:17:04 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_3d.h"

t_matrix	*new_matrix(void)
{
	t_matrix	*mat;
	int			i;
	int			j;

	mat = malloc(sizeof(t_matrix));
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			*mat[i][j] = 0.0;
	}
	i = -1;
	while (++i < 4)
		*mat[i][i] = 1.0;
	return (mat);
}

t_matrix	*copy_matrix(t_matrix *m1)
{
	t_matrix	*m2;
	int			i;
	int			j;

	m2 = new_matrix();
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			*m2[i][j] = *m1[i][j];
	}
	return (m2);
}

t_matrix	*mult_matrix(t_matrix *m1, t_matrix *m2)
{
	t_matrix	*m3;
	int			i;
	int			j;
	int			k;

	m3 = new_matrix();
	ft_putstr("test intra mult_matrix m0.1 =>");
	print_matrix(m1);
	ft_putstr("test intra mult_matrix m0.2 =>");
	print_matrix(m2);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			*m3[i][j] = 0.0;
			k = -1;
			while (++k < 4)
				*m3[i][j] += *m1[i][k] * *m2[k][j];
		}
	}
	return (m3);
}

void		translate_matrix(t_matrix *m, t_vector *v)
{
	*m[0][3] += v->x;
	*m[1][3] += v->y;
	*m[2][3] += v->z;
	*m[3][3] += v->w;
}

t_matrix	*rot_matrix(double angle, char axis)
{
	t_matrix	*mat;

	mat = new_matrix();
	if (axis == 'x')
	{
		*mat[1][1] = cos(angle);
		*mat[2][2] = cos(angle);
		*mat[1][2] = -sin(angle);
		*mat[2][1] = sin(angle);
	}
	else if (axis == 'y')
	{
		*mat[0][0] = cos(angle);
		*mat[2][2] = cos(angle);
		*mat[0][2] = -sin(angle);
		*mat[2][0] = sin(angle);
	}
	else if (axis == 'z')
	{
		*mat[1][1] = cos(angle);
		*mat[0][0] = cos(angle);
		*mat[1][0] = -sin(angle);
		*mat[0][1] = sin(angle);
	}
	return (mat);
}
