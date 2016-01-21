/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:19:37 by aeguzqui          #+#    #+#             */
/*   Updated: 2015/12/01 15:29:09 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char *res;

	if ((res = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
	{
		ft_strcpy(res, str);
		return (res);
	}
	return (NULL);
}
