/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:47:38 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/01/15 04:55:24 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *str, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	i = 0;
	sub = NULL;
	if (str && (sub = (char*)malloc((len + 1) * sizeof(char))))
	{
		while (i < len && str[start + i])
		{
			sub[i] = str[start + i];
			i++;
		}
		sub[i] = '\0';
	}
	return (sub);
}
