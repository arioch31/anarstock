/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 01:18:24 by aeguzqui          #+#    #+#             */
/*   Updated: 2015/12/03 17:50:11 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;
	t_list	*p;

	p = NULL;
	newlist = NULL;
	if (!lst)
		return (NULL);
	if ((newlist = ft_lstnew(f(lst)->content, f(lst)->content_size)))
	{
		p = lst->next;
		while (p)
		{
			ft_lstapp(&newlist, ft_lstnew(f(p)->content, f(p)->content_size));
			p = p->next;
		}
	}
	return (newlist);
}
