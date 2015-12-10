/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:53:58 by aeguzqui          #+#    #+#             */
/*   Updated: 2015/12/03 17:38:59 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	str = NULL;
	if (s1 && s2 && (str = (char*)malloc(sizeof(char) * \
		(ft_strlen(s1) + ft_strlen(s2) + 1))))
	{
		while (i < ft_strlen(s1))
		{
			str[i] = s1[i];
			i++;
		}
		while (j < ft_strlen(s2))
		{
			str[i + j] = s2[j];
			j++;
		}
		str[i + j] = '\0';
	}
	return (str);
}
