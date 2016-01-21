/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:57:40 by aeguzqui          #+#    #+#             */
/*   Updated: 2015/11/30 18:05:11 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int		i;
	unsigned char		*ptr_dest;
	char				*buff;

	ptr_dest = (unsigned char *)dest;
	buff = (char*)malloc(n * sizeof(char));
	buff = ft_memcpy(buff, src, n);
	i = 0;
	while (i < n)
	{
		ptr_dest[i] = (unsigned char)buff[i];
		i++;
	}
	return (dest);
}
