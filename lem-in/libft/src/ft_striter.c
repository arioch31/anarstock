/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:23:40 by aeguzqui          #+#    #+#             */
/*   Updated: 2015/11/30 13:58:44 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *str, void (*f)(char*))
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	while (i < ft_strlen(str))
	{
		ptr = &str[i];
		f(ptr);
		i++;
	}
}
