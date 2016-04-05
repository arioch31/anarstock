/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 04:42:17 by aeguzqui          #+#    #+#             */
/*   Updated: 2015/12/03 17:36:45 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(const char *s1, const char *s2, size_t size)
{
	if (s1 && s2)
	{
		if (ft_strncmp(s1, s2, size))
			return (0);
		return (1);
	}
	return (0);
}
