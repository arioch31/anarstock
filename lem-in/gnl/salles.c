/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   salles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 23:58:46 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/06/06 21:32:46 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_salle	*newsalle(char *line)
{
	t_salle		*new_salle;
	char		**tab;

	if (!line)
		return (nul_errmsg("pb line\n"));
	if (nb_words(line, ' ') != 3)
		return (0);
	tab = ft_strsplit(line, ' ');
	if (ft_strchr(tab[0], '-'))
		return (nul_errmsg("'-' présent dans le nom d'une salle\n"));
	if (*tab[0] == 'L')
		return (nul_errmsg("le nom d'une salle commence par 'L'\n"));
	new_salle = malloc(sizeof(t_salle));
	new_salle->liens = NULL;
	new_salle->name = ft_strdup(tab[0]);
	if (!(new_salle->coo_x = int_nozero(tab[1])) && !ft_strequ(tab[1], "0"))
		return (nul_errmsg("pb coordonées\n"));
	if (!(new_salle->coo_y = int_nozero(tab[2])) && !ft_strequ(tab[2], "0"))
		return (nul_errmsg("pb coordonées\n"));
	new_salle->dist_start = 0;
	new_salle->utile = 1;
	return (new_salle);
}

int		add_salle(t_ruche *ruche, char *line, int utile)
{
	t_salle	*salle;

	if (!(salle = newsalle(line)))
		return (0);
	if (!get_salle(salle, ruche))
		ft_lstapp(&(ruche->list_salles), ft_lstnew(&salle, sizeof(t_salle*)));
	else
		return (error_msg("salle deja presente\n"));
	if (utile)
		salle->utile = utile;
	if (utile == 2 || utile == 5)
		ruche->start = salle;
	if (utile > 2)
		ruche->end = salle;
	return (1);
}

char	*set_salles(int fd, t_ruche *ruche, char **line)
{
	int		ret;
	int		a;

	ret = 0;
	while (!ret)
	{
		a = id_line(fd, line);
		if ((a == 2 && ruche->start) || (a == 3 && ruche->end) ||
			(a == 5 && (ruche->start || ruche->end)) ||
			(a != 1 && a != 2 && a != 3 && a != 5))
			return (NULL);
		if (!add_salle(ruche, *line, a))
			ret = 1;
	}
	if (!(ruche->start && ruche->end))
		return (NULL);
	return (*line);
}

t_salle	*get_salle(t_salle *salle, t_ruche *ruche)
{
	t_salle	*ptr;
	t_list	*list_ptr;

	if (!ruche->list_salles)
		return (NULL);
	list_ptr = ruche->list_salles;
	ptr = *(t_salle**)list_ptr->content;
	while (!ft_strequ(salle->name, ptr->name) &&
		!(salle->coo_x == ptr->coo_x && salle->coo_y == ptr->coo_y))
	{
		list_ptr = list_ptr->next;
		if (!list_ptr)
			return (NULL);
		ptr = *(t_salle**)list_ptr->content;
	}
	return (ptr);
}

t_salle	*find_salle(char *name, t_ruche *ruche)
{
	t_salle	*ptr;
	t_list	*list_ptr;

	if (!ruche->list_salles)
		return (NULL);
	list_ptr = ruche->list_salles;
	ptr = *(t_salle**)list_ptr->content;
	while (!ft_strequ(name, ptr->name))
	{
		list_ptr = list_ptr->next;
		if (!list_ptr)
			return (NULL);
		ptr = *(t_salle**)list_ptr->content;
	}
	return (ptr);
}

int		set_liaison(char *line, t_ruche *ruche)
{
	t_salle		*salle1;
	t_salle		*salle2;
	char		**tab;

	if (!*line)
		return (error_msg("ligne vide liaison attendue"));
	if (nb_words(line, '-') != 2)
		return (error_msg("laison mal formatee"));
	tab = ft_strsplit(line, '-');
	if (!(salle1 = find_salle(tab[0], ruche)))
		return (error_msg("salle inconnue"));
	if (!(salle2 = find_salle(tab[1], ruche)))
		return (error_msg("salle inconnue"));
	if (is_link(salle1, salle2))
		return (error_msg("lien deja present"));
	ft_lstapp(&(salle1->liens), ft_lstnew(&salle2, sizeof(t_salle*)));
	ft_lstapp(&(salle2->liens), ft_lstnew(&salle1, sizeof(t_salle*)));
	free(tab[0]);
	free(tab[1]);
	free(tab);
	return (1);
}
