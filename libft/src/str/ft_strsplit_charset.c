/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_charset.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 20:14:33 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/04/13 05:37:55 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		nb_words_charset(const char *str, char *charset)
{
	unsigned int i;
	unsigned int nb;

	i = 0;
	nb = 0;
	while (i < ft_strlen(str))
	{
		while (ft_strchr(charset, str[i]))
			i++;
		if (str[i])
		{
			nb++;
			while (str[i] && !ft_strchr(charset, str[i]))
				i++;
		}
	}
	return (nb);
}

static unsigned int	len_word_charset(const char *str, char *charset)
{
	unsigned int i;

	i = 0;
	while (str[i] && !ft_strchr(charset, str[i]))
		i++;
	return (i);
}

static void			tab_fill(const char *str, char *charset, char **tab)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;
	unsigned int	len_word;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		while (ft_strchr(charset, str[i]))
			i++;
		if (str[i])
		{
			len_word = len_word_charset(&str[i], charset);
			tab[j] = ft_strsub(str, i, len_word);
			j++;
			i += len_word;
		}
	}
}

char				**ft_strsplit_charset(const char *str, char *charset)
{
	char			**tab;
	unsigned int	i;

	tab = NULL;
	if (!str || !charset)
		return (NULL);
	if ((i = nb_words_charset(str, charset))
	&& (tab = (char**)malloc((i + 1) * sizeof(char*))))
	{
		tab[i] = NULL;
		tab_fill(str, charset, tab);
	}
	return (tab);
}
