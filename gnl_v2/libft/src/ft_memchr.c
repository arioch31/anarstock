/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:38:01 by aeguzqui          #+#    #+#             */
/*   Updated: 2015/11/27 02:44:51 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	void				*ptr;
	unsigned int		i;
	const unsigned char *ptr_str;

	ptr_str = (const unsigned char*)str;
	ptr = NULL;
	i = 0;
	while (i < n)
	{
		if (ptr_str[i] == (unsigned char)c)
		{
			ptr = (void *)str + i;
			return (ptr);
		}
		i++;
	}
	return (ptr);
}
