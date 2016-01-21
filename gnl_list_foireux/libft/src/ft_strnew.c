/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 03:49:12 by aeguzqui          #+#    #+#             */
/*   Updated: 2015/12/09 14:58:30 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*str;
	unsigned int	i;

	str = NULL;
	i = 0;
	str = (char*)malloc((size + 1) * sizeof(char));
	if (str)
		while (i < size + 1)
		{
			str[i] = '\0';
			i++;
		}
	return (str);
}
