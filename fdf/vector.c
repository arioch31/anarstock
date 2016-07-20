/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 00:57:06 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/07/08 03:53:51 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_3d.h"

t_3dvec	*add_vector(t_3dvec *v1, t_3dvec *v2)
{
	t_3dvec	*vnew;

	vnew = malloc(sizeof(t_3dvec));
	vnew->x = v1->x + v2->x;
	vnew->y = v1->y + v2->y;
	vnew->z = v1->z + v2->z;
	vnew->w = vect_magnitude(vnew);
	return (vnew);
}

t_3dvec	*sub_vector(t_3dvec *v1, t_3dvec *v2)
{
	t_3dvec	*v3;
	t_3dvec	*v4;

	v3 = opp_vector(v2);
	v4 = add_vector(v1, v3);
	free(v3);
	return (v4);
}

t_3dvec	*mult_3dvec(t_3dvec *v1, double mult)
{
	t_3dvec	*vnew;

	vnew = malloc(sizeof(t_3dvec));
	vnew->x = v1->x * mult;
	vnew->y = v1->y * mult;
	vnew->z = v1->z * mult;
	vnew->w = vect_magnitude(vnew);
	return (vnew);
}

t_3dvec	*norm_vector(t_3dvec *v)
{
	t_3dvec	*v2;
	double		mag;

	v2 = malloc(sizeof(t_3dvec));
	mag = vect_magnitude(v);
	v2->x = v->x / mag;
	v2->y = v->y / mag;
	v2->z = v->z / mag;
	v2->w = 1;
	return (v2);
}

t_3dvec	*opp_vector(t_3dvec *v)
{
	t_3dvec	*v2;

	v2 = malloc(sizeof(t_3dvec));
	v2->x = -v->x;
	v2->y = -v->y;
	v2->z = -v->z;
	v2->w = v->w;
	return (v2);
}
