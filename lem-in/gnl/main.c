/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 23:58:46 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/04/06 00:19:40 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static char	*err_msg = NULL;

int error_msg(char *msg)
{
	err_msg = ft_strjoin(err_msg, msg);
	return (0);
}
void	*nul_errmsg(char *msg)
{
	err_msg = ft_strjoin(err_msg, msg);
	return (NULL);
}
int	main(int ac, char **av)
{
	char	*test;
	t_ruche	*ruche;

	ruche = malloc(sizeof(t_ruche));
	ruche->list_salles = NULL;
	ruche->start = NULL;
	ruche->end = NULL;

	
	if (ac == 1 && verif_file(0, ruche))
	{
		ft_putendl("succes!");
		
	}
	else if (ac == 1)
		ft_putendl("erreur fichier");
	else
		ft_putendl("erreur input");
	if (err_msg)
		ft_putendl(err_msg);
	if (ruche)
		aff_ruche(ruche);
		
	return (0);
}
