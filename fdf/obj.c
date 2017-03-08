/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 01:49:39 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/03/08 04:07:31 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_3d.h"

void	clear_link(void *ptr, size_t size)
{
	t_link *lnk;

	(void)size;
	lnk = *(t_link**)ptr;
	lnk->p1 = NULL;
	lnk->p2 = NULL;
	free(lnk);
}

void	free_obj(t_obj *ob)
{
	if (ob)
	{
		ft_lstdel(&ob->links, &clear_link);
		ft_lstdel(&ob->point, NULL); //delete_pt a coder (3d?)
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
