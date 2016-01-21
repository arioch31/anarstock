/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:40:23 by aeguzqui          #+#    #+#             */
/*   Updated: 2015/12/09 15:00:29 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *str, char (*f)(char))
{
	char			*dest;
	unsigned int	i;

	i = 0;
	if (!str)
		return (NULL);
	dest = (char*)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (dest)
	{
		while (i < ft_strlen(str))
		{
			dest[i] = f(str[i]);
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}
