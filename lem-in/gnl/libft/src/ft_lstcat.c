/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 21:18:07 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/10 00:05:12 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lstcat(t_list *start)
{
	char	*tmp;

	tmp = ft_strnew(0);
	while (start)
	{
		tmp = ft_strjoin(tmp, (start->content ? start->content : "(null)"));
		start = start->next;
	}
	return (tmp);
}
