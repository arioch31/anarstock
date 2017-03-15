/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 20:14:33 by aeguzqui          #+#    #+#             */
/*   Updated: 2015/12/03 17:37:36 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		nb_words(const char *str, char c)
{
	unsigned int i;
	unsigned int nb;

	i = 0;
	nb = 0;
	while (i < ft_strlen(str))
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i])
		{
			nb++;
			while (str[i] != c && str[i])
				i++;
		}
	}
	return (nb);
}

static unsigned int	len_word(const char *str, char c)
{
	unsigned int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char				**ft_strsplit(const char *str, char c)
{
	char			**tab;
	unsigned int	i;
	unsigned int	j;

	tab = NULL;
	if (!str)
		return (NULL);
	if ((tab = (char**)malloc((nb_words(str, c) + 1) * sizeof(char*))))
	{
		i = 0;
		j = 0;
		while (i < ft_strlen(str))
		{
			while (str[i] == c)
				i++;
			if (str[i])
			{
				tab[j] = ft_strsub(str, i, len_word(&str[i], c));
				j++;
				i += len_word(&str[i], c);
			}
		}
		tab[j] = 0;
	}
	return (tab);
}
