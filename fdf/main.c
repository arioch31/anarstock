/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 20:32:05 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/11/14 23:09:10 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		test(t_grid *grille);

int		main(int ac, char **av)
{
	int		fd;
	int		*tab;
	int		i;
	t_grid	*grille;
	double	*mat_proj;

	if (ac != 2 || !(fd = open(av[1], O_RDONLY)))
		return (0);
	grille = new_grid(fd);
	aff_grid(grille);
	ft_putchar('\n');
	i = 0;
	while (i < grille->rows * grille->lines)
	{
		print_3dpt(grille->l_3dpts[i]);
		i++;
	}
	test(grille);
	return (0);
}
