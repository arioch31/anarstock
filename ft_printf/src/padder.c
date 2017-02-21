/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 12:06:56 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/10 02:11:16 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*padd_left(char *str, size_t size)
{
	char		*res;
	size_t		i;

	i = 0;
	if (ft_strlen(str) < size)
	{
		res = malloc(sizeof(char) * (size + 1));
		while (i + ft_strlen(str) < size)
			res[i++] = ' ';
		res[i] = '\0';
		ft_strcat(res, str);
		free(str);
		return (res);
	}
	else
		return (str);
}

char	*padd_right(char *str, size_t size)
{
	char		*res;
	size_t		i;

	if (ft_strlen(str) < size)
	{
		res = ft_strnew(size + 1);
		ft_strcat(res, str);
		i = ft_strlen(str);
		while (i < size)
			res[i++] = ' ';
		res[i] = '\0';
		free(str);
		return (res);
	}
	else
		return (str);
}

char	*padd_zero(char *str, size_t size)
{
	char		*res;
	size_t		i;

	i = 0;
	if (ft_strlen(str) < size)
	{
		res = ft_strnew(size);
		while (i + ft_strlen(str) < size)
			res[i++] = '0';
		res[i] = '\0';
		ft_strcat(res, str);
		free(str);
		return (res);
	}
	else
		return (str);
}

char	*add_char(char *str, char c)
{
	char	*tmp;

	tmp = ft_strnew(1);
	*tmp = c;
	return (ft_strjoin(tmp, str));
}
