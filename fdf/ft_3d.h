/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 00:16:27 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/07/08 06:39:05 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_3D_H
# define _FT_3D_H
# include "libft.h"
# include <math.h>

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
}				t_point;

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
	double		w;
}				t_vector;

typedef double	t_matrix[4][4];

/*
** vertex.c
*/

t_point			*new_point(double x, double y, double z);
t_vector		*new_vector(t_point *p1, t_point *p2);

/*
** vector.c
*/

t_vector		*add_vector(t_vector *v1, t_vector *v2);
t_vector		*sub_vector(t_vector *v1, t_vector *v2);
t_vector		*mult_vector(t_vector *v1, double mult);
t_vector		*norm_vector(t_vector *v);
t_vector		*opp_vector(t_vector *v);

/*
** vector2.c
*/

double			vect_magnitude(t_vector *v);
double			dotprod_vector(t_vector *v1, t_vector *v2);
t_vector		*crossprod_vector(t_vector *v1, t_vector *v2);
double			cos_vector(t_vector *v1, t_vector *v2);

/*
** matrix.c
*/

t_matrix		*new_matrix(void);
t_matrix		*copy_matrix(t_matrix *m1);
t_matrix		*mult_matrix(t_matrix *m1, t_matrix *m2);
void			translate_matrix(t_matrix *m, t_vector *v);
t_matrix		*rot_matrix(double angle, char axis);

/*
** debug.c
*/

void			print_point(t_point *p);
void			print_vector(t_vector *v);
void			print_matrix(t_matrix *m);

#endif
