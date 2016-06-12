/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 17:21:55 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/06/12 17:23:07 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_mouv(t_salle *salle, int name)
{
	ft_putchar('L');
	ft_putnbr(name);
	ft_putchar('-');
	ft_putstr(salle->name);
	ft_putchar('\t');
}

void	aff_couvee(t_list *fourmis)
{
	t_fourmi *ptr;

	while (fourmis)
	{
		ptr = *(t_fourmi**)fourmis->content;
		ft_putnbr(ptr->name);
		ft_putstr("ready!\n");
		fourmis = fourmis->next;
	}
}

int		is_used(t_list *path, t_salle *salle)
{
	t_list	*ptr;
	t_salle	*ptr_salle;

	ptr = path;
	while (ptr)
	{
		ptr_salle = *(t_salle**)ptr->content;
		if (ptr_salle == salle)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

int		path_equ(t_list *path1, t_list *path2)
{
	t_list	*ptr1;
	t_list	*ptr2;

	ptr1 = path1;
	ptr2 = path2;
	while (ptr1 && ptr2)
	{
		if (*(t_salle**)ptr2->content != *(t_salle**)ptr2->content)
			return (0);
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
		if (!ptr1 - !ptr2)
			return (0);
	}
	return (1);
}
