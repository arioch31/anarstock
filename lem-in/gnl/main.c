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
		ft_putnbr(ruche->nb_fourmis);
		
	}
	else if (ac == 1)
		ft_putendl("erreur");
	else
		ft_putendl("erreur2");
	
	return (0);
}
