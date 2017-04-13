/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 20:29:14 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/04/13 00:58:15 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strindex(char *str, char c)
{
	unsigned int i;

	i = 1;
	while (str[i - 1] && str[i - 1] != c)
		i++;
	return (i > ft_strlen(str) ? 0 : i);
}
