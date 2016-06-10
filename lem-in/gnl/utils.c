/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 16:46:23 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/06/10 17:00:59 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	list_clear(void *content, size_t content_size)
{
	content = NULL;
	content_size = 0;
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
	if (ft_strequ(tab[0], tab[1]))
		return (error_msg("salle liee avec elle meme"));
	if (!(salle1 = find_salle(tab[0], ruche)))
		return (error_msg("salle inconnue"));
	if (!(salle2 = find_salle(tab[1], ruche)))
		return (error_msg("salle inconnue"));
	if (is_link(salle1, salle2))
		return (error_msg("lien deja present"));
	ft_lstadd(&(salle1->liens), ft_lstnew(&salle2, sizeof(t_salle*)));
	ft_lstadd(&(salle2->liens), ft_lstnew(&salle1, sizeof(t_salle*)));
	free(tab[0]);
	free(tab[1]);
	free(tab);
	return (1);
}

int		nb_vliaisons(t_salle *salle)
{
	int		ret;
	t_list	*ptr;
	t_salle	*p_salle;

	ret = 0;
	ptr = salle->liens;
	while (ptr)
	{
		p_salle = *(t_salle**)ptr->content;
		if (p_salle->utile)
			ret++;
		ptr = ptr->next;
	}
	return (ret);
}
