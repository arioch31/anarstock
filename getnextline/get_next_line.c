/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:31:55 by aeguzqui          #+#    #+#             */
/*   Updated: 2015/12/14 17:04:30 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	static t_list	*list = NULL;
	t_list			*ptr;
	char 			*input;

	if (!list && (input = ft_read(fd)))
		list = ft_lstrsplit(input, '\n');
/*	if (*line)
		free(*line);
*/	if (list)
	{
		*line = ft_strdup(list->content);
		ptr = list->next;
		free(list->content);
		free(list);
		list = ptr;
		if (list->next)
			return (1);
		return (0);
	}
	return(-1);
}

char	*ft_read(int const fd)
{
    char	*buffer;
    char	*input;
    int		octets_lus;
    int		len;
    
    len = 0;
    input = NULL;
    buffer = (char*)malloc(BUF_SIZE + 1);
    if (!buffer)
        return (NULL);
    while ((octets_lus = read(fd, buffer, BUF_SIZE)))
    {
        if (octets_lus == -1)
            return (NULL);
        len += octets_lus;
        input = enlarge_input(input, buffer, len, octets_lus);
        input[len] = '\0';
    }
    free(buffer);
    return (input);
}

char	*enlarge_input(char *input, char *buffer, int len, int octets_lus)
{
    char	*tmp;
    int		i;
    
    tmp = (char*)malloc(len + 1);
    if (!tmp)
        return (NULL);
    i = 0;
    if (input)
    {
        while (i < len - octets_lus)
        {
            tmp[i] = input[i];
            i++;
        }
        free(input);
    }
    i = 0;
    while (i < octets_lus)
    {
        tmp[i + len - octets_lus] = buffer[i];
        i++;
    }
    return (tmp);
}
