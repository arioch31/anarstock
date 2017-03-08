/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_fdf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 02:03:33 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/03/08 02:30:01 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	order_links(t_grid *gr, t_obj *ob)
{
	int		i;
	t_list	*ptr1;
	t_list	*ptr2;

	i = 1;
	if (gr->rect)
		while (i <= gr->rows * gr->lines)
		{
			ptr1 = ft_lstgetnb(ob->point, i);
			if (i % gr->rows && (ptr2 = ft_lstgetnb(ob->point, i + 1)))
				new_link(ob, ptr1, ptr2);
			if (i <= (gr->rows - 1) * gr->lines &&
			(ptr2 = ft_lstgetnb(ob->point, i + gr->rows)))
				new_link(ob, ptr1, ptr2);
			i++;
		}
	else
		printf("not rectangle so GTFO\n");
}

void	debug_obj(t_obj *ob)
{
	t_list	*ptr;
	t_link	*lnk;

	ptr = ob->point;
	while (ptr)
	{
		print_2dpt((t_2dpt*)ptr->content);
		ft_putchar('\t');
		ptr = ptr->next;
	}
	ft_putendl("\nend list points\nstarting links debug:");
	ptr = ob->links;
	while (ptr)
	{
		debug_link(ptr);
		ptr = ptr->next;
	}
}

int		fill_obj(t_grid *gr, t_obj *ob)
{
	t_list	*p1;
	t_list	*p2;

	p1 = gr->data;
	p2 = *(t_list**)p1->content;
	while (p1 && p2)
	{
		add_pt(ob, ft_lstnew(p2->content, p2->content_size));
		p2 = p2->next;
		if (!p2)
		{
			p1 = p1->next;
			if (p1)
				p2 = *(t_list**)p1->content;
		}
	}
	order_links(gr, ob);
	return (1);
}
