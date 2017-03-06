/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:08:50 by aeguzqui          #+#    #+#             */
/*   Updated: 2015/11/28 15:56:31 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int			i;
	int			j;
	const char	*ptr;

	ptr = NULL;
	if (!s2[0])
		return ((char*)s1);
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s1[i + j] == s2[j] || !s2[j])
		{
			if (s2[j] == '\0')
			{
				ptr = &s1[i];
				return ((char*)ptr);
			}
			j++;
		}
		i++;
	}
	return ((char*)ptr);
}
