/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 00:16:27 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/07/20 05:15:02 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_3D_H
# define _FT_3D_H
# include "libft.h"
# include <math.h>
# include "mlx.h"

typedef struct	s_window
{
	void		*screen;
	void		*mlx;
	size_t		large;
	size_t		height;
}				t_window;

typedef struct	s_3dpoint
{
	double		x;
	double		y;
	double		z;
	double		w;
}				t_3dpt;

typedef struct	s_3dvec
{
	double		x;
	double		y;
	double		z;
	double		w;
}				t_3dvec;

typedef struct	s_2dpoint
{
	int			x;
	int			y;
	int			color;
}				t_2dpt;

/*
** vertex.c
*/

t_3dpt			*new_3dpoint(double x, double y, double z);
t_3dvec			*new_vector(t_3dpt *p1, t_3dpt *p2);

/*
** vector.c
*/

t_3dvec			*add_vector(t_3dvec *v1, t_3dvec *v2);
t_3dvec			*sub_vector(t_3dvec *v1, t_3dvec *v2);
t_3dvec			*mult_3dvec(t_3dvec *v1, double mult);
t_3dvec			*norm_vector(t_3dvec *v);
t_3dvec			*opp_vector(t_3dvec *v);

/*
** vector2.c
*/

double			vect_magnitude(t_3dvec *v);
double			dotprod_vector(t_3dvec *v1, t_3dvec *v2);
t_3dvec			*crossprod_vector(t_3dvec *v1, t_3dvec *v2);
double			cos_3dvec(t_3dvec *v1, t_3dvec *v2);

/*
** matrix.c
*/

double			*new_matrix(void);
double			*copy_matrix(double *m1);
double			*mult_matrix(double *m1, double *m2);
void			translate_matrix(double *m, t_3dvec *v);
double			*rot_matrix(double angle, char axis);

/*
** matrix2.c
*/

double			*proj_matrix(double angl, double ratio, double nar, double far);
void			scale_matrix(double *mat, double scale);
t_3dpt			*matrix_point(double *mat, t_3dpt *p);

/*
** debug.c
*/

void			print_3dpt(t_3dpt *p);
void			print_3dvec(t_3dvec *v);
void			print_matrix(double *m);

#endif
