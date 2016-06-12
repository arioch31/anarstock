/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 04:10:56 by aeguzqui          #+#    #+#             */
/*   Updated: 2015/11/30 14:10:38 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*test;
	char			*test2;
	unsigned int	i;

	i = 0;
	test = NULL;
	if (size > 0)
	{
		test = malloc(size * sizeof(char));
		if (test)
		{
			test2 = (char*)test;
			while (i < size)
			{
				test2[i] = 0;
				i++;
			}
		}
	}
	return (test);
}
