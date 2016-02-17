#include "push_swap.h"


t_controleur	*init_c(t_list	*start)
{
	t_controleur *c;

	c = malloc(sizeof(t_controleur));
	c->la = ft_lstcpy(start);
	c->lb = NULL;
	c->length = get_length(c->la);
	c->la_len = c->length;
	c->lb_len = 0;
	if (c->length)
		c->val_m = *(int*)get_ranker(c->la, get_length(c->la) / 2 + 1)->content;
	c->phase = 0;
	c->op_j = ft_strnew(0);
	c->nb_op = 0;
	return (c);
}

t_controleur	*copie_c(t_controleur	*c)
{
	t_controleur 	*d;

	d= init_c(NULL);
	d->op_j = ft_strdup(c->op_j);
	d->la = ft_lstcpy(c->la);
	d->lb = ft_lstcpy(c->lb);
	d->nb_op = c->nb_op;
	d->length =	c->length ;
	d->la_len = get_length(d->la);
	d->lb_len = get_length(d->lb);
	d->phase = c->phase;
	d->val_m = c->val_m;
	return (d);
}

void 	destr_c(t_controleur *c)
{
	if (c)
  	{
      ft_lstdel(&(c->la), &del_list);
      ft_lstdel(&(c->lb), &del_list);
      free(c->op_j);
      free(c);
  	}
}

int	ad_op(t_controleur *c, char *name)
{
	if (!name)
		return (0);
	if (c->op_j && *(c->op_j))
		c->op_j = ft_strjoin(c->op_j, ft_strjoin(" ", name));
	else
		c->op_j = ft_strdup(name);
	c->nb_op++;
	return (1);
}
