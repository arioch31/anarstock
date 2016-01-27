/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:06:28 by aeguzqui          #+#    #+#             */
/*   Updated: 2015/12/07 15:19:09 by aeguzqui         ###   ########.fr       */
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

void		ft_lstaff(t_list *lst)
{
	ft_lstiter(lst, &aff_elem);
    ft_putchar('\n');
}
