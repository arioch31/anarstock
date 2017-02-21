/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:47:08 by aeguzqui          #+#    #+#             */
/*   Updated: 2015/11/27 00:19:13 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		i;
	const unsigned char *p_s1;
	const unsigned char *p_s2;

	p_s1 = (const unsigned char*)s1;
	p_s2 = (const unsigned char*)s2;
	i = 0;
	while (i < n && p_s1[i] == p_s2[i])
		i++;
	if (i == n)
		return (0);
	return (p_s1[i] - p_s2[i]);
}
