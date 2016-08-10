/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 20:48:35 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/08/10 01:02:37 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H
# define _FDF_H
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

}				t_grid;

void			aff_grid(t_grid *grille);
t_grid			*new_grid(int fd);

#endif
