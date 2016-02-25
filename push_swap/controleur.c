/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controleur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 17:41:56 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/20 18:33:54 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list			*new_pile(t_list *origin)
{
	t_list		*new_p;
	t_list		*ptr;

	new_p = NULL;
	while (origin)
	{
		ptr = malloc(sizeof(t_list));
		ptr->content_size = origin->content_size;
		ptr->content = origin->content;
		ptr->next = NULL;
		ft_lstapp(&new_p, ptr);
		origin = origin->next;
	}
	return (new_p);
}

t_controleur	*init_c(t_list *start)
{
	t_controleur *c;

	c = malloc(sizeof(t_controleur));
	c->la = new_pile(start);
	c->lb = NULL;
	c->length = get_length(c->la);
	c->la_len = c->length;
	c->lb_len = 0;
	if (c->length)
		c->val_m = *(int*)get_ranker(c->la, get_length(c->la) / 2 + 1)->content;
	c->phase = 0;
	
	c->nb_op = 0;
	c->last_op = NULL;
	c->size_codef = c->la_len * c->la_len;
	c->code_f = ft_strnew(c->size_codef);
	return (c);
}

t_controleur	*copie_c(t_controleur *c)
{
	t_controleur	*d;

	d = init_c(NULL);
	d->la = new_pile(c->la);
	d->lb = new_pile(c->lb);
/*
	d->op_j = ft_strdup(c->op_j);
	
	d->last_op = ft_strdup(c->last_op);
*/
	d->nb_op = c->nb_op;
	d->length = c->length;
	d->la_len = get_length(d->la);
	d->lb_len = get_length(d->lb);
	d->phase = c->phase;
	d->val_m = c->val_m;
	d->code_f = malloc(sizeof(char) * c->size_codef);
	d->size_codef = c->size_codef;
	d->code_f = ft_strncpy(d->code_f, c->code_f,c->size_codef);
	if (c->last_op)
	d->last_op = d->code_f + ft_strlen(c->code_f) - 1;
	else
		d->last_op = NULL;
	return (d);
}

void			destr_c(t_controleur **c)
{
	if (c)
	{
		ft_lstdel(&((*c)->la), &del_list);
		ft_lstdel(&((*c)->lb), &del_list);
	//	free((*c)->op_j);
	//	free((*c)->last_op);
		free(*c);
		*c = NULL;
	}
}

int				ad_op(t_controleur *c, int code_f)
{
	if (code_f > 10)
		return (0);
/*	if (c->op_j && *(c->op_j))
		c->op_j = ft_strjoin(c->op_j, ft_strjoin(" ", str_f[code_f]));
	else
		c->op_j = ft_strdup(str_f[code_f]);
	if (c->last_op)
		free(c->last_op);
	c->last_op = ft_strdup(str_f[code_f]);
*/	c->nb_op++;

	if (!c->last_op)
	{
		c->last_op = c->code_f;
	}
	else
		c->last_op++;

	*c->last_op = (char)code_f;

	*(c->last_op + 1) = '\0';

	return (1);
}
