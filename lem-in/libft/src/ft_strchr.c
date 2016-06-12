/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:08:34 by aeguzqui          #+#    #+#             */
/*   Updated: 2015/12/02 16:02:25 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	char *ptr;

	ptr = NULL;
	while (*src != 0 && *src != c)
		src++;
	if (*src == c)
		ptr = (char*)src;
	return (ptr);
}
