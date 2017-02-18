/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:35:36 by aeguzqui          #+#    #+#             */
/*   Updated: 2015/11/27 00:12:14 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int		i;
	void				*ptr;
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;

	ptr_dest = (unsigned char*)dest;
	ptr_src = (const unsigned char*)src;
	i = 0;
	while (i < n && ptr_src[i] != (unsigned char)c)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	if (ptr_src[i] == (unsigned char)c && i < n)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
		ptr = dest + i;
		return (ptr);
	}
	return (NULL);
}
