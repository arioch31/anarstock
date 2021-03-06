/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:06:28 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/03/25 00:13:23 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	aff_elem(t_list *lst)
{
	ft_putchar('"');
	ft_putstr((char*)lst->content);
	ft_putchar('"');
	ft_putstr("->");
	ft_putnbr(lst->content_size);
	ft_putchar('\t');
	lst = lst->next;
}

void		ft_lstaff(t_list *lst, void (*f)(t_list *elem))
{
	if (f)
		ft_lstiter(lst, f);
	else
		ft_lstiter(lst, &aff_elem);
	ft_putchar('\n');
}
