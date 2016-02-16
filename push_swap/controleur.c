#include "push_swap.h"

t_controleur	*init_c(t_list	*start)
{
	t_controleur *c;

	if (!start)
		return (NULL);
	c = malloc(sizeof(t_controleur));
	c->op_j = ft_strnew(0);
	c->nb_op = 0;
	c->la = ft_lstcpy(start);
	c->lb = NULL;
	return (c);
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

int pile_triee(t_list *p)
{
	if (!p)
		return (0);
	if (!p->next)
		return (1);
	if (*(int*)p->content > *(int*)p->next->content)
		return(pile_triee(p->next));
	return (0);
}