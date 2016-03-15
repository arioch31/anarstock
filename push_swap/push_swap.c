/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 01:13:08 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/03/15 00:03:31 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		set_ranks(t_list *start)
{
	t_list	*ptr;

	ptr = start;
	while (ptr)
	{
		ptr->content_size = rank(start, *(int*)ptr->content);
		ptr = ptr->next;
	}
}

t_list		*get_entry(int ac, char **av)
{
	int				i;
	unsigned int	j;
	long int		test;
	char			*charset;
	t_list			*start;

	charset = ft_strdup("0123456789+-");
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
	free(charset);
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
	else
		ft_putendl("aucune operation requise");
}

int			main(int ac, char **av)
{
	t_list			*origin;
	t_controleur	*b;
	t_controleur	*c;
	t_controleur	*d;
	t_list			*ptr;

	if (ac < 3)
		exit_error(NULL, NULL);
	else
	{
		origin = get_entry(ac, av);
		c = init_c(origin);
		ptr = c->la;
		while (ptr)
		{
			ft_putnbr(ptr->content_size);
			ft_putchar('\t');
			ptr = ptr->next;
		}
		ft_putchar('\n');
		aff_pile(origin);
		ft_putendl("\ninitalisation OK!");
		b = init_c(origin);
		ft_putnbr(solverv4(b));
		ft_putendl(" solver v4 OK!");
		ft_putnbr(solverv2(c));
		ft_putendl(" solver v2 OK!");
		d = init_c(origin);
		ft_putnbr(solverv3(d));
		ft_putstr(" solver v3 OK!\nresults :\nv1\t");
		ft_putnbr(b->nb_op);
		ft_putstr("\nv2\t");
		ft_putnbr(c->nb_op);
		ft_putstr("\nv3\t");
		ft_putnbr(d->nb_op);
		ft_putendl("\n++++++++++++++++------++++++++++++++++++");
/*
		if (d->nb_op < 300)
			aff_state(d);
		if (d->nb_op < 100)
		{
			while ((d = monobrute(init_c(origin), d->nb_op)))
			{
				ft_putnbr(d->nb_op);
				aff_journal(d);
				aff_pile(d->la);
				ft_putchar('\n');
			}
		}
		else
			ft_putendl("brute non testee, trop d'op");
*/
/*		if (get_length(origin) < 9)
		{
			if ((d = monobrute(init_c(origin), 2 * get_length(origin))))
			{
				while ((d = monobrute(init_c(origin), d->nb_op)))
				aff_state(d);
			}
			else
				ft_putendl("echec monobrute en moins de length x2");
			if ((d = brute(init_c(origin), 2 * get_length(origin))))
				aff_state(d);
			else
				ft_putendl("echec brute en moins de length x2");
		}
*/	}
	return (0);
}
