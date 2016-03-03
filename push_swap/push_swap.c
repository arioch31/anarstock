/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 01:13:08 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/03/03 19:35:44 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list		*get_entry(int ac, char **av)
{
	int				i;
	unsigned int	j;
	long int		test;
	char			charset[] = "0123456789+-";
	t_list			*start;

	start = NULL;
	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (j < ft_strlen(av[i]))
			if (!ft_strchr(charset, av[i][j++]))
				exit_error(start, NULL);
		test = ft_atoli(av[i]);
		if ((unsigned long int)test != (unsigned long int)(int)test)
			exit_error(start, NULL);
		if (get_valued(start, test))
			exit_error(start, NULL);
		ft_lstapp(&start, ft_lstnew(&test, sizeof(int)));
	}
	return (start);
}

void		aff_journal(t_controleur *c)
{
	char	*ptr;

	if (c->nb_op > 0)
	{
		ptr = c->code_f;
		while (ptr != c->last_op)
		{
			ft_putstr(STR_F[(int)*ptr]);
			ft_putchar(' ');
			ptr++;
		}
		ft_putendl(STR_F[(int)*ptr]);
	}
}

int			main(int ac, char **av)
{
	t_list			*origin;
	t_controleur	*c;
	t_controleur	*d;

	if (ac < 3)
		exit_error(NULL, NULL);
	else
	{
		origin = get_entry(ac, av);
		c = init_c(origin);
		ft_putendl("\ninitalisation OK!");
		ft_putnbr(solverv2(c));
		ft_putendl("solver v2 OK!");
		d = init_c(origin);
		ft_putnbr(solverv3(d));
		ft_putstr("solver v3 OK!\nresults :\nv2\t");
		ft_putnbr(c->nb_op);
		ft_putstr("\nv3\t");
		ft_putnbr(d->nb_op);
		ft_putendl("\n++++++++++++++++------++++++++++++++++++");
		if (d->nb_op < 50)
		{
			while ((d = monobrute(init_c(origin), d->nb_op)))
			{
				ft_putnbr(d->nb_op);
				aff_journal(d);
			}
		}
		else
			ft_putendl("brute non testee, trop d'op");
	}
	return (0);
}
