/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 23:58:46 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/06/10 19:30:38 by aeguzqui         ###   ########.fr       */
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

void	test_pathalacon(t_ruche *ruche)
{
	t_list	*ptr;
	t_salle	*ptr_salle;

	ptr = ruche->list_salles;
	while (ptr)
	{
		ptr_salle = *(t_salle**)ptr->content;
		if (is_used(ruche->short_path, ptr_salle))
		{
			ft_putstr(ptr_salle->name);
			ft_putendl(" is used in the shortest path");
		}
		ptr = ptr->next;
	}
}

int		main(int ac, char **av)
{
	char	*test;
	t_ruche	*ruche;
	int		ret;
	t_list	*path;

	ruche = init_ruche();
	if (!ft_strequ(av[0], "./lem-in"))
	{
		ft_putendl("erreur, exécutable mal nommé");
		test = av[0];
		ft_putendl(test);
		return(0);
	}
	if (ac == 1 && verif_file(0, ruche) && !g_errmsg)
	{
		ft_putendl("********************************\nformat fichier ok!");
	}
	else if (ac == 1)
	{
		ft_putendl("erreur fichier non valide!");
	}
	else
		ft_putendl("erreur input");
	if (g_errmsg)
	{
		ft_putendl("#########");
		ft_putendl(g_errmsg);
		ft_putendl("#########");
	}
	ret = 0;
	if (ruche)
	{
		if ((ret = delim_ruche(ruche)))
			{
				ft_putstr("ret delim ruche:");
				ft_putnbr(ret);
				ft_putchar('\n');
				if (ret > 1)
				{
					aff_path(ruche->short_path);
					aff_ruche(ruche);
				//	test_pathalacon(ruche);
					path = ft_lstnew(&ruche->start, sizeof(t_salle*));
					addstep_path(ruche, path, ruche->start);
					ft_putendl("sorti!");
					affmap(ruche->map_paths);
				}
			}
		else
			ft_putendl("erreur, start et end ne sont pas lies");
	}
	return (0);
}
