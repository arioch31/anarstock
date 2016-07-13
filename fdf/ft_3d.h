/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 00:16:27 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/07/13 04:23:17 by aeguzqui         ###   ########.fr       */
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
	double		w;
}				t_point;

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
	double		w;
}				t_vector;

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

double			*new_matrix(void);
double			*copy_matrix(double *m1);
double			*mult_matrix(double *m1, double *m2);
void			translate_matrix(double *m, t_vector *v);
double			*rot_matrix(double angle, char axis);

/*
** matrix2.c
*/

double			*proj_matrix(double angl, double ratio, double nar, double far);
void			scale_matrix(double *mat, double scale);
t_point			*matrix_point(double *mat, t_point *p);

/*
** debug.c
*/

void			print_point(t_point *p);
void			print_vector(t_vector *v);
void			print_matrix(double *m);

#endif
