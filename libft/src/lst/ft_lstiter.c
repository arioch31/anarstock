/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 01:08:09 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/04/21 21:42:48 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (lst)
	{
		f(lst);
		if (lst->next)
			ft_lstiter(lst->next, f);
	}
}

void	*ft_lstiter_ret(t_list *lst, void *(*f)(t_list *elem, void *r), void *ret)
{
	if (lst)
	{
		f(lst, ret);
		if (lst->next)
			ft_lstiter_ret(lst->next, f, ret);
	}
	return (ret);
}

void	*ft_lstiter_ret_rev(t_list *lst, void *(*f)(t_list *elem,  void *r), void *ret)
{
	if (lst)
	{
		if (lst->next)
			ft_lstiter_ret_rev(lst->next, f, ret);
		f(lst, ret);
	}
	return (ret);
}
