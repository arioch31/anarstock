/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   salles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 23:58:46 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/04/06 00:19:40 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

t_salle	*newsalle(char *line)
{
	t_salle		*new_salle;
	char 		**tab;

	if (!line)
		return (NULL);
	if (nb_words(line, ' ') != 3)
		return (NULL);
	tab = ft_strsplit(line, ' ');
	if (ft_strchr(tab[0], '-'))
		return (NULL);
	new_salle = malloc(sizeof(t_salle));
	new_salle->liens = NULL;
	new_salle->name = ft_strdup(tab[0]);
	if (!(new_salle->coo_x = int_nozero(tab[1])) && !ft_strequ(tab[1], "0"))
		return (NULL);
	if (!(new_salle->coo_y = int_nozero(tab[2])) && !ft_strequ(tab[2], "0"))
		return (NULL);
	new_salle->utile = 1;
	return (new_salle);
}

int 	add_salle(t_ruche *ruche, char *line, int utile)
{
	t_salle	*salle;

	if ((salle = newsalle(line)))
		ft_lstadd(&(ruche->list_salles), ft_lstnew(&salle, sizeof(t_salle*)));
	else 
		return (0);
	if (utile)
		salle->utile = utile;
	if ((utile - 1) % 2)
		ruche->start = salle;
	if (utile > 2)
		ruche->end = salle;
	return (1);
}

char 	*set_salles(int fd, t_ruche *ruche)
{
	char	*line;
	int		ret;
	int 	a;

	ret = 0;
	while (!ret)
	{
		a = id_line(fd, &line);
		if ((a == 2  && ruche->start) || (a == 3  && ruche->end) ||
			(a == 5  && (ruche->start || ruche->end)) ||
			(a != 0 && a != 2 && a != 3 && a != 5))
			return (NULL);
		if (!add_salle(ruche, line, a))
			ret = 1;
	}
	if (!(ruche->start && ruche->end))
		return (NULL);
	return (line);
}

t_salle 	*get_salle(char *name, t_ruche *ruche)
{
	t_salle	*ptr;
	t_list	*list_ptr;

	list_ptr = ruche->list_salles;
	ptr = (t_salle*)list_ptr->content;
	while (!ft_strequ(name, ptr->name))
	{
		list_ptr = list_ptr->next;
		if (!list_ptr)
			return (NULL);
		ptr = (t_salle*)list_ptr->content;
	}
	return (ptr);
}

int 	set_liaison(char *line, t_ruche *ruche)
{
	t_salle		*salle1;
	t_salle		*salle2;
	char 		**tab;


	if (nb_words(line, '-') != 2)
		return (0);
	tab = ft_strsplit(line, '-');
	if (!(salle1 = get_salle(tab[0], ruche)) || 
		!(salle2 = get_salle(tab[1], ruche)) ||
		is_link(salle1, salle2))
		return(0);
	ft_lstadd(&(salle1->liens), ft_lstnew(&salle2, sizeof(t_salle*)));
	ft_lstadd(&(salle2->liens), ft_lstnew(&salle1, sizeof(t_salle*)));

	return (1);
}