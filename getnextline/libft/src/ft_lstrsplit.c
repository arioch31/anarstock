/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 20:14:33 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/01/05 13:40:52 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	len_word(const char *str, char c)
{
	unsigned int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

t_list				*ft_lstrsplit(const char *str, char c)
{
	t_list			*lst;
	t_list			*elem;
	unsigned int	i;
	unsigned int	n;

	lst = NULL;
	if (!str)
		return (NULL);
	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i])
		{
			n = len_word(&str[i], c);
			elem = ft_lstnew(ft_strsub(str, i, n), n);
			ft_lstapp(&lst, elem);
			i += n;
			if (n == 0)
				i++;
		}
	}
	return (lst);
}
