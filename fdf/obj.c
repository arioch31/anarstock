/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 01:49:39 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/03/08 03:25:54 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_3d.h"

void	clear_link(void *ptr, size_t size)
{
	t_list *ptr2;
	t_link *lnk;

	(void)size;
	ft_putendl("\nstarting links debug:");
	ptr2 = (t_list*)ptr;
	lnk = *(t_link**)ptr;
	ft_putendl("casts OK!");
	print_2dpt((t_2dpt*)lnk->p1->content);
	ft_putstr(" => ");
	print_2dpt((t_2dpt*)lnk->p2->content);
	lnk->p1 = NULL;
	lnk->p2 = NULL;
	ft_putendl("nulls OK!");
	free(lnk);
	ft_putendl("free OK!");
}

void	free_obj(t_obj *ob)
{
	if (ob)
	{
		ft_lstdel(&ob->links, &clear_link);
		ft_lstdel(&ob->point, NULL);
		free(ob);
	}
}

t_obj	*create_obj(void)
{
	t_obj	*ob;

	ob = malloc(sizeof(t_obj));
	ft_bzero(ob, sizeof(t_obj));
	return (ob);
}

void	add_pt(t_obj *ob, t_list *pt_ptr)
{
	ft_lstapp(&ob->point, pt_ptr);
}

void	new_link(t_obj *ob, t_list *p1, t_list *p2)
{
	t_list	*ret;
	t_link	*lnk;

	lnk = malloc(sizeof(t_link));
	lnk->p1 = p1;
	lnk->p2 = p2;
	ret = ft_lstnew(&lnk, sizeof(t_link**));
	ft_lstapp(&(ob->links), ret);
}
