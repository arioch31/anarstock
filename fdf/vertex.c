/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 00:15:43 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/07/08 06:39:05 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_3d.h"

t_point		*new_point(double x, double y, double z)
{
	t_point *ptr;

	ptr = malloc(sizeof(t_point));
	ptr->x = x;
	ptr->y = y;
	ptr->z = z;
	return (ptr);
}

t_vector	*new_vector(t_point *p1, t_point *p2)
{
	t_vector	*v;

	v = malloc(sizeof(t_vector));
	v->x = p1->x - p2->x;
	v->y = p1->y - p2->y;
	v->z = p1->z - p2->z;
	v->w = sqrt(pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2));
	return (v);
}
