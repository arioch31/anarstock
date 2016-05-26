/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 23:58:46 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/05/26 02:01:22 by aeguzqui         ###   ########.fr       */
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

int		main(int ac, char **av)
{
	char	*test;
	t_ruche	*ruche;
	int		ret;

	ruche = malloc(sizeof(t_ruche));
	ruche->list_salles = NULL;
	ruche->start = NULL;
	ruche->end = NULL;
	if (!ft_strequ(av[0], "./lem-in"))
	{
		ft_putendl("erreur, exécutable mal nommé");
		test = av[0];
		ft_putendl(test);
		return(0);
	}
	if (ac == 1 && verif_file(0, ruche) && !g_errmsg)
	{
		ft_putendl("succes!");
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
		aff_ruche(ruche);

	if ((ret = delim_ruche(ruche)))
		ft_putnbr(ret);
	return (0);
}
