/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 20:48:35 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/11/07 20:40:42 by aeguzqui         ###   ########.fr       */
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
	t_list		*grid;
	int			rows;
	int			lines;
	int			z_min;
	int			z_max;
	int			*tab;
	t_3dpt		**l_3dpts;
	t_2dpt		**l_2dpts;
}				t_grid;

typedef struct	s_obj
{
	t_list		*point;
}				t_obj;

void			aff_grid(t_grid *grille);
int				*trad_grid(t_grid *grille);
t_grid			*new_grid(int fd);

#endif
