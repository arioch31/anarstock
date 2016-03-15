/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 18:53:49 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/03/14 21:26:33 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	aff_state(t_controleur *c)
{
	if (!c)
		ft_putendl("controleur vide");
	else
	{
		ft_putendl("||base===================sommet===>>>");
		aff_pile(c->la);
		ft_putchar('\n');
		aff_pile(c->lb);
		ft_putendl("\n||base===================sommet===>>>");
		ft_putendl("journal:");
		aff_journal(c);
		ft_putstr("\nnb op :\t\t");
		ft_putnbr(c->nb_op);
		ft_putstr("\nlast op :\t");
		ft_putendl(STR_F[(int)*c->last_op]);
		ft_putstr("length totale :\t");
		ft_putnbr(c->length);
		ft_putstr("\nlength la :\t");
		ft_putnbr(c->la_len);
		ft_putstr("\nlength lb :\t");
		ft_putnbr(c->lb_len);
		ft_putstr("\nval mediane :\t");
		ft_putnbr(c->val_m);
		ft_putchar('\n');
	}
}

void	aff_pile(t_list *start)
{
	if (start)
	{
		if (start->next)
		{
			aff_pile(start->next);
			ft_putchar(' ');
		}
		ft_putnbr(*(int*)(start->content));
	}
}

int		pile_triee(t_list *p, int sens)
{
	if (!p)
		return (0);
	if (!p->next)
		return (1);
	if (sens && *(int*)p->content < *(int*)p->next->content)
		return (pile_triee(p->next, sens));
	if (!sens && *(int*)p->content > *(int*)p->next->content)
		return (pile_triee(p->next, sens));
	return (0);
}

void	del_list(void *content, size_t content_size)
{
	if (content)
		content = NULL;
	if (content_size)
		content_size = 0;
}

void	exit_error(t_list *origin, t_controleur *c)
{
	if (origin)
		ft_lstdel(&origin, &del_list);
	ft_putendl("erreur\n");
	if (c)
		destr_c(&c);
	exit(0);
}
