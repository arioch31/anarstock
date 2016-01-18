/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:53:58 by aeguzqui          #+#    #+#             */
/*   Updated: 2015/12/03 17:38:59 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*str;
    char            *start;

	str = NULL;
	if (s1 && s2 && (str = (char*)malloc(sizeof(char) * \
		(ft_strlen(s1) + ft_strlen(s2) + 1))))
	{
        start = str;
		while (*s1)
			*(str++) = *(s1++);
		while (*s2)
			*(str++) = *(s2++);
		*str = '\0';
	}
    else if (s1)
        return (ft_strdup(s1));
    else if (s2)
        return (ft_strdup(s2));
    else
        start = ft_strnew(0);
    return (start);
}
