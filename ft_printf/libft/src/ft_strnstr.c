/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:08:50 by aeguzqui          #+#    #+#             */
/*   Updated: 2015/11/28 16:02:29 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	char			*ptr;

	ptr = NULL;
	if (!s2[0])
		return ((char*)s1);
	i = 0;
	while (s1[i] && i < n)
	{
		j = 0;
		while ((s1[i + j] && s1[i + j] == s2[j] && i + j < n) || !s2[j])
		{
			if (s2[j] == '\0')
			{
				ptr = (char*)&s1[i];
				return (ptr);
			}
			j++;
		}
		i++;
	}
	return (ptr);
}
