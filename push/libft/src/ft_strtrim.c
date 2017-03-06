/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 19:05:47 by aeguzqui          #+#    #+#             */
/*   Updated: 2015/11/28 20:14:00 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *str)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	if (ft_strlen(str) == 0)
		return ("\0");
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (i == ft_strlen(str))
		return ("\0");
	j = ft_strlen(str) - 1;
	while (str[j] == ' ' || str[j] == '\t' || str[j] == '\n')
		j--;
	if (i == 0 && j == ft_strlen(str) - 1)
		return ((char*)str);
	return (ft_strsub(str, i, j - i + 1));
}
