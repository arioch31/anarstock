/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:18:28 by aeguzqui          #+#    #+#             */
/*   Updated: 2015/12/02 16:02:49 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;
	int		i;

	ptr = NULL;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == c)
		{
			ptr = (char*)&str[i];
			return (ptr);
		}
		i--;
	}
	return (ptr);
}
