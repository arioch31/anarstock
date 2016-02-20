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
	t_list		*new_pile;
	t_list		*ptr;

	new_pile = NULL;
	while (origin)
	{
		ptr = malloc(sizeof(t_list));
		ptr->content_size = origin->content_size;
		ptr->content = origin->content;
		ft_lstapp(&new_pile, ptr);
		origin = origin->next;
	}
	return (new_pile);
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
	c->op_j = ft_strnew(0);
	c->nb_op = 0;
	c->last_op = ft_strnew(0);
	return (c);
}

t_controleur	*copie_c(t_controleur *c)
{
	t_controleur	*d;

	d = init_c(NULL);
	d->op_j = ft_strdup(c->op_j);
	d->la = new_pile(c->la);
	d->lb = new_pile(c->lb);
	d->nb_op = c->nb_op;
	d->length = c->length;
	d->la_len = get_length(d->la);
	d->lb_len = get_length(d->lb);
	d->phase = c->phase;
	d->val_m = c->val_m;
	d->last_op = c->last_op;
	return (d);
}

void			destr_c(t_controleur **c)
{
	if (c)
	{
		ft_lstdel(&((*c)->la), &del_list);
		ft_lstdel(&((*c)->lb), &del_list);
		free((*c)->op_j);
		free((*c)->last_op);
		free(*c);
		*c = NULL;
	}
}

int				ad_op(t_controleur *c, char *name)
{
	if (!name)
		return (0);
	if (c->op_j && *(c->op_j))
		c->op_j = ft_strjoin(c->op_j, ft_strjoin(" ", name));
	else
		c->op_j = ft_strdup(name);
	c->last_op = ft_strdup(name);
	c->nb_op++;
	return (1);
}
