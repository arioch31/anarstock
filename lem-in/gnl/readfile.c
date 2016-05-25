/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 23:58:46 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/05/25 21:28:47 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		int_nozero(char *test)
{
	int	ret;

	ret = ft_atoi(test);
	if (!ret)
		return (0);
	if (!ft_strequ(ft_itoa(ret), test))
		return (0);
	else
		return (ret);
}

int		iscomment(char *test)
{
	if (*test != '#')
		return (0);
	if (ft_strequ(test, "##start"))
		return (2);
	if (ft_strequ(test, "##end"))
		return (3);
	return (1);
}

int		id_line(int fd, char **line)
{
	int		ret;
	int		utile;
	int		ret2;

	ret = 0;
	utile = 0;
	while ((ret = get_next_line(fd, line)) && ret > 0)
	{
		ft_putendl(*line);
		if ((ret2 = iscomment(*line)) && ret2 > 1)
			utile += ret2;
		if (!ret2 && utile)
			return (utile);
		if (!ret2)
			return (1);
	}
	if (ret < 1)
	{
		*line = ft_strnew(0);
		return (0);
	}
	return (1);
}

int		verif_file(int fd, t_ruche *ruche)
{
	char	*line;
	int		ret;

	ret = 0;
	if ((ret = id_line(fd, &line)) && ret != 1)
		return (error_msg("erreur com invalide"));
	if (!(ruche->nb_fourmis = int_nozero(line)))
		return (error_msg("erreur nb fourmis"));
	if (!(set_salles(fd, ruche, &line)))
		return (error_msg("erreur format des salles"));
	while (set_liaison(line, ruche) && (ret = id_line(fd, &line)))
		;
	return (1);
}

int		is_link(t_salle *salle1, t_salle *salle2)
{
	t_list	*ptr;

	ptr = salle2->liens;
	while (ptr)
	{
		if (salle1 == *(t_salle**)ptr->content)
			return (1);
		ptr = ptr->next;
	}
	ptr = salle1->liens;
	while (ptr)
	{
		if (salle2 == *(t_salle**)ptr->content)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}
