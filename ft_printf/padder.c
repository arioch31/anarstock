/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 12:06:56 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/01/26 15:18:26 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *padd_left(char *str, size_t size)
{
	char	*res;
	int i;

	i = 0;
	if (ft_strlen(str) < size)
	{
		res = malloc(sizeof(char) * (size + 1));
		while (i < size - ft_strlen(str))
			res[i++] = ' ';
		res[i] = '\0';
		ft_strcat(res, str);
		free(str);
	return (res);
	}
	else
		return (str);
}

char *padd_right(char *str, size_t size)
{
	char	*res;
	int i;

	if (ft_strlen(str) < size)
	{
		res = ft_strnew (size + 1);
		ft_strcat(res, str);
		i = ft_strlen(str);;
		while (i < size )
			res[i++] = ' ';
		res[i] = '\0';
		free(str);
		return (res);
	}
	else
		return (str);
}

char *padd_zero(char *str, size_t size)
{
	char	*res;
	int i;

	i = 0;
	if (ft_strlen(str) < size)
	{
		res = malloc(sizeof(char) * (size + 1));
		while (i < size - ft_strlen(str))
			res[i++] = '0';
		res[i] = '\0';
		ft_strcat(res, str);
		free(str);
	return (res);
	}
	else
		return(str);
}

char *padd_space(char *str, int is_neg)
{
	if (!is_neg)
		return (ft_strjoin(" ", str));
	return (str);
}

char	*padd_plus(char *str, int is_neg)
{
	if (!is_neg)
		return (ft_strjoin("+", str));
	return (str);
}
