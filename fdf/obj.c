/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 01:49:39 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/03/07 03:07:42 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	print_2dpt(t_2dpt *pt)
{
	ft_putnbr(pt->x);
	ft_putchar(',');
	ft_putnbr(pt->y);
}

void	debug(t_obj *ob)
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
		lnk = (t_link*)ptr->content;
		ft_putstr("link: ");
		if (lnk->p1)
		print_2dpt((t_2dpt*)lnk->p1->content);
		ft_putstr(" => ");
		print_2dpt((t_2dpt*)lnk->p2->content);
		ft_putchar('\n');
		ptr = ptr->next;
	}
}

t_list	*new_link(t_list *p1, t_list *p2)
{
	t_list	*ret;
	t_link	*lnk;

	lnk = malloc(sizeof(t_link));
	lnk->p1 = p1;
	lnk->p2 = p2;
	ret = ft_lstnew(lnk, sizeof(t_link*));
	return (ret);
}

void	order_links(t_grid *gr, t_obj *ob)
{
	int		i;
	t_list	*ptr1;
	t_list	*ptr2;

	i = 0;
	if (gr->rect)
		while (i < gr->rows * gr->lines)
		{
			ptr1 = ft_lstgetnb(ob->point, i);
			if (i + 1 % gr->rows)
			{
				ptr2 = ft_lstgetnb(ob->point, i + 1);
				ft_lstapp(&(ob->links), new_link(ptr1, ptr2));
			}
			if (i < (gr->rows - 1) * gr->lines)
			{
				ptr2 = ft_lstgetnb(ob->point, i + 1 + gr->rows);
				ft_lstapp(&(ob->links), new_link(ptr1, ptr2));
			}
			i++;
		}
	else
		printf("not rectangle so GTFO\n");
}

t_obj	*create_obj(t_grid *gr)
{
	t_list	*p1;
	t_list	*p2;
	t_obj	*ob;

	ob = malloc(sizeof(t_obj));
	ft_bzero(ob, sizeof(t_obj));
	p1 = gr->data;
	p2 = *(t_list**)p1->content;
	while (p1 && p2)
	{
		ft_lstapp(&ob->point, ft_lstnew(p2->content, p2->content_size));
		p2 = p2->next;
		if (!p2)
		{
			p1 = p1->next;
			if (p1)
				p2 = *(t_list**)p1->content;
		}
	}
	order_links(gr, ob);
	return (ob);
}
