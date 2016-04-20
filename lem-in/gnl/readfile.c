/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 23:58:46 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/04/06 00:19:40 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int	int_nozero(char *test)
{
	int	ret;

	ret = ft_atoi(test);
	if (!ret)
		return (0);
	if (!ft_strequ(ft_itoa(ret), test))
		return (0);
	else return (ret);
}

int	iscomment(char *test)
{
	int ret;
	if (*test != '#')
		return (0);
	if (ft_strequ(test, "##start"))
		return (2);
	if (ft_strequ(test, "##end"))
		return (3);
	return (1);
}

int 	id_line(int fd,char **line)
{
	int		ret;
	int 	utile;

	utile = 0;
	while (get_next_line(fd, line) && (ret = iscomment(*line)))
		if (ret > 1)
			utile += ret;
	return (utile);
}


int verif_file(int fd, t_ruche *ruche)
{
	char	*line;
	int		ret;

	if (id_line(fd, &line))
		return (0);
	if (!(ruche->nb_fourmis = int_nozero(line)))
		return (0);
	if (!(line = set_salles(fd, ruche)))
		return (0);
	while(set_liaison(line, ruche) && !id_line(fd, &line) && line);
	return (1);
}

int 	is_link(t_salle	*salle1, t_salle *salle2)
{
	t_list	*ptr;

	ptr = salle2->liens;
	while (ptr)
	{
		if (salle1 == (t_salle*)ptr->content)
			return (1);
		ptr = ptr->next;
	}
	ptr = salle1->liens;
	while (ptr)
	{
		if (salle2 == (t_salle*)ptr->content)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}
