/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 00:57:06 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/07/08 05:48:54 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_3d.h"

double		vect_magnitude(t_vector *v)
{
	return (sqrt(pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2)));
}

double		dotprod_vector(t_vector *v1, t_vector *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

t_vector	*crossprod_vector(t_vector *v1, t_vector *v2)
{
	t_vector	*vnew;

	vnew = malloc(sizeof(t_vector));
	vnew->x = (v1->y * v2->z) - (v1->z * v2->y);
	vnew->y = (v1->z * v2->x) - (v1->x * v2->z);
	vnew->z = (v1->x * v2->y) - (v1->y * v2->x);
	vnew->w = vect_magnitude(vnew);
	return (vnew);
}

double		cos_vector(t_vector *v1, t_vector *v2)
{
	return (dotprod_vector(v1, v2) / (vect_magnitude(v1) * vect_magnitude(v2)));
}
