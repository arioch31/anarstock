/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 20:48:35 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/08/02 04:34:41 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H
# define _FDF_H
# include "get_next_line.h"

typedef struct	s_grid
{
	t_list		*grid;
	int			rows;
	int			lines;
}				t_grid;

#endif
