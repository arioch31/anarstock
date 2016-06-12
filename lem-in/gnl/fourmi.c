/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fourmi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 00:46:52 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/06/11 00:47:21 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	ponte_fourmis(t_ruche *ruche, int nb)
{
	t_fourmi	*proto;
	int 	i;

	i = 0;
	while (i < nb)
	{
		i++;
		proto = malloc(sizeof(t_fourmi));
		proto->path = NULL;
		proto->finished = 0;
		proto->name = i;
		ft_lstapp(&ruche->fourmis, ft_lstnew(&proto, sizeof(t_fourmi*)));
	}
	if(!ruche->dispo)
		ruche->dispo = ruche->fourmis;
	ruche->rest += i;
	return (i);
}

void		print_mouv(t_salle *salle, int name)
{
	ft_putchar('L');
	ft_putnbr(name);
	ft_putchar('-');
	ft_putstr(salle->name);
	ft_putchar('\t');
}

int		mouv(t_ruche *ruche, t_salle *p1, t_salle *p2)
{
	if (p1->occupee && (p2 == ruche->end || !p2->occupee))
	{
		p2->occupee++;
		if (p1 != ruche->start)
		{
			p2->fourmi = p1->fourmi;
			p1->fourmi = NULL;
			p1->occupee = 0;
			print_mouv(p2, p2->fourmi->name);
			if (p2 == ruche->end)
				ruche->rest--;
		}
		else if (p2 == ruche->end)
			while (ruche->dispo)
			{
				p2->fourmi = *(t_fourmi**)ruche->dispo;
				print_mouv(p2, p2->fourmi->name);
				ruche->rest--;
				ruche->dispo = ruche->dispo->next;
			}
		else if (ruche->dispo)
		{
			p2->fourmi = *(t_fourmi**)ruche->dispo->content;
			print_mouv(p2, p2->fourmi->name);
			ruche->dispo = ruche->dispo->next;
			p1->occupee = ft_lstlen(ruche->dispo);
		}
		return (1);
	}
	return (0);
}

void		recc_mouv(t_ruche *ruche, t_list *path)
{
	if (path)
	{
		recc_mouv(ruche, path->next);
		if (path->next)
			mouv(ruche, *(t_salle**)path->content, *(t_salle**)path->next->content);
	}
}

void		turn(t_ruche *ruche, t_list *map)
{
		t_list		*ptr_path;
		t_list		*ptr_map;

		ptr_map = map;
		while (ruche->rest && ptr_map)
		{
			ptr_path = *(t_list**)ptr_map->content;
			recc_mouv(ruche, ptr_path);
			ptr_map = ptr_map->next;
		}
}	

int		action(t_ruche *ruche, t_list *map)
{
	int	cpt;

	cpt = 0;
	ponte_fourmis(ruche, ruche->nb_fourmis);
	while (ruche->rest)
	{
		cpt++;
		turn(ruche, map);
		ft_putendl("");
	}
	return (cpt);
}