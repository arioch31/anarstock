/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 00:16:27 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/03/08 03:23:21 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_3D_H
# define _FT_3D_H
# include "libft.h"
# include <math.h>
# include "mlx.h"

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

typedef struct	s_img
{
	void		*addr;
	char		*start;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_window
{
	t_2dpt		*center;
	void		*screen;
	void		*mlx;
	int			large;
	int			height;
	double		*mat_cam;
	double		*mat_proj;
	t_img		*img;
}				t_window;

typedef struct	s_link
{
	t_list		*p1;
	t_list		*p2;
}				t_link;

typedef struct	s_obj
{
	t_list		*point;
	t_list		*links;
}				t_obj;

t_obj			*create_obj(void);
void			add_pt(t_obj *ob, t_list *pt_ptr);
void			new_link(t_obj *ob, t_list *p1, t_list *p2);
void			clear_link(void *ptr, size_t size);
void			free_obj(t_obj *ob);

int				key_dispatch(int keycode, void *param);

/*
** color.c
*/
char			degrade_color(int pt, int len, char t1, char t2);
int				degrade(int pt, int len, int color1, int color2);

/*
** vertex.c
*/

t_3dpt			*new_3dpoint(double x, double y, double z);
t_3dvec			*new_vector(t_3dpt *p1, t_3dpt *p2);
t_2dpt			*new_2dpt(int x, int y, int color);

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
void			print_2dpt(t_2dpt *pt);
void			print_3dpt(t_3dpt *p);
void			print_3dvec(t_3dvec *v);
void			print_matrix(double *m);
void			debug_link(t_list *ptr);

/*
** draw.c
*/

int				visible(t_2dpt *pt, t_window *w);
int				draw_point(t_2dpt *pt, t_window *w);
void			get_next_pt(t_2dpt *p1, t_2dpt *p2, t_2dpt *pt, t_window *w);
void			draw_line(t_2dpt *p1, t_2dpt *p2, t_window *w);

#endif
