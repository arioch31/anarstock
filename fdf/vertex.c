/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 00:15:43 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/07/20 05:16:48 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_3d.h"

t_3dpt		*new_3dpoint(double x, double y, double z)
{
	t_3dpt *ptr;

	ptr = malloc(sizeof(t_3dpt));
	ptr->x = x;
	ptr->y = y;
	ptr->z = z;
	return (ptr);
}

t_3dvec		*new_vector(t_3dpt *p1, t_3dpt *p2)
{
	t_3dvec	*v;

	v = malloc(sizeof(t_3dvec));
	v->x = p1->x - p2->x;
	v->y = p1->y - p2->y;
	v->z = p1->z - p2->z;
	v->w = sqrt(pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2));
	return (v);
}

t_2dpt		*new_2dpt(int x, int y, int color)
{
	t_2dpt	*pt;

	pt = malloc(sizeof(t_2dpt));
	pt->x = x;
	pt->y = y;
	pt->color = color;
	return (pt);
}
