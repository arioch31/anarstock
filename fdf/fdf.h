/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 20:48:35 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/03/06 23:21:33 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H
# define _FDF_H
# include <stdlib.h>
# include "get_next_line.h"
# include "ft_3d.h"
# define W_LARGE 1600
# define W_HEIGHT 900

typedef struct	s_grid
{
	t_window	*w;
	t_list		*data;
	int			rows;
	int			lines;
	int			z_min;
	int			z_max;
	int			rect;
	double		*camera;
}				t_grid;

typedef struct	s_link
{
	t_list		*point1;
	t_list		*point2;
}				t_link;

typedef struct	s_obj
{
	t_list		*point;
	t_list		*links;
}				t_obj;

void	aff_grid(t_list *data);
int				*trad_grid(t_grid *grille);
t_grid			*new_grid(int fd);
void			init_3dpts(t_grid *gr);
void			init_2dgrid(t_grid *grille);

int				refresh(void *w_ptr);
t_2dpt	*as_2dpt(t_list *start, size_t index);
t_3dpt	*as_3dpt(t_list *start, size_t index);
void	draw_grid(t_grid *gr);

#endif
