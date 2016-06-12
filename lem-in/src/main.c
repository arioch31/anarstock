/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 23:58:46 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/06/12 18:32:37 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static char	*g_errmsg = NULL;

int		error_msg(char *msg)
{
	g_errmsg = ft_strjoin(g_errmsg, msg);
	return (0);
}

void	*nul_errmsg(char *msg)
{
	g_errmsg = ft_strjoin(g_errmsg, msg);
	return (NULL);
}

void	test_mapping(t_ruche *ruche)
{
	t_list	*ptr;

	ptr = ruche->list_maps;
	while (ptr)
	{
		aff_map(*(t_list**)ptr->content);
		ptr = ptr->next;
	}
}

int		start_moving(t_ruche *ruche)
{
	int		ret;
	int		ret2;
	t_list	*path;

	ret = 0;
	if (ruche && (ret = delim_ruche(ruche)))
	{
		path = ft_lstnew(&ruche->start, sizeof(t_salle*));
		addstep_path(ruche, path, ruche->start);
		select_paths(ruche);
		path = trim_paths(ruche);
		if (ret == 1)
			path = ruche->list_paths;
		ft_putendl("");
		ret2 = action(ruche, path);
		aff_map(path);
		ft_putnbr(ruche->nb_fourmis);
		ft_putendl(" fourmis");
		ft_putnbr(ret2);
		ft_putendl(" tours");
	}
	else
		return (error_msg("erreur, start et end ne sont pas lies"));
	return (1);
}

int		main(int ac, char **av)
{
	t_ruche	*ruche;

	ruche = init_ruche();
	if (ac == 1 && verif_file(0, ruche) && !g_errmsg)
		start_moving(ruche);
	else if (ac == 1)
		ft_putendl("erreur fichier non valide!");
	else
		ft_putendl(ft_strjoin("erreur input :", av[1]));
	if (g_errmsg)
		ft_putendl(g_errmsg);
	return (0);
}
