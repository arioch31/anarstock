/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 01:13:08 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/25 19:02:13 by aeguzqui         ###   ########.fr       */
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

	ptr = c->code_f;
	while (ptr != c->last_op)
	{
		ft_putstr(STR_F[(int)*ptr]);
		ft_putchar(' ');
		ptr++;
	}
	ft_putendl(STR_F[(int)*ptr]);
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
		ft_putendl("initalisation:");
		origin = get_entry(ac, av);
		c = init_c(origin);
		ft_putendl("initalisation OK!");
		ft_putnbr(solver(c));
		ft_putendl("solver v1 OK!");
		ft_putnbr(c->nb_op);
		ft_putendl(" operations");
		d = init_c(origin);
		ft_putnbr(solverv2(d));
		ft_putendl("solver v2 OK!");
		ft_putnbr(d->nb_op);
		ft_putendl(" operations");
		ft_putstr("results :\nv1\t");
		ft_putnbr(c->nb_op);
		ft_putstr("\nv2\t");
		ft_putnbr(d->nb_op);
		ft_putendl("\n++++++++++++++++------++++++++++++++++++");
		if (c->nb_op < 50)
		{
			while ((c = brute(init_c(origin), c->nb_op)))
			{
				ft_putnbr(c->nb_op);
				aff_journal(c);
			}
		}
		else
			ft_putendl("brute non testee, trop d'op");
	}
	return (0);
}
