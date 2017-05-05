/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 21:33:04 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/04/27 00:10:48 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		lst_write(t_list *p)
{
	int	cpt;

	cpt = 0;
	while (p)
	{
		if (!p->content)
		{
			ft_putstr("(null)");
			cpt += 6;
		}
		else
		{
			write(1, p->content, p->content_size);
			cpt += p->content_size;
		}
		p = p->next;
	}
	return (cpt);
}

char	*lst_dup(t_list *lst)
{
	int		cpt;
	char	*ret;
	t_list	*p;

	cpt = 0;
	p = lst;
	while (p)
	{
		if (!p->content)
			cpt += 6;
		else
			cpt += p->content_size;
		p = p->next;
	}
	ret = ft_strnew(cpt);
	p = lst;
	while (p)
	{
		if (!p->content)
			ft_strncat(ret, "(null)", 6);
		else
			ft_strncat(ret, p->content, p->content_size);
		p = p->next;
	}
	return (ret);
}
