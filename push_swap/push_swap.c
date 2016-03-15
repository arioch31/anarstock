/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 01:13:08 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/03/15 05:53:19 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			set_ranks(t_list *start)
{
	t_list	*ptr;

	ptr = start;
	while (ptr)
	{
		ptr->content_size = rank(start, *(int*)ptr->content);
		ptr = ptr->next;
	}
}

t_list			*get_entry(int ac, char **av)
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

void			aff_journal(t_controleur *c)
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

t_controleur	*test_brute(t_list *origin)
{
	t_controleur	*d;
	t_controleur	*e;
	size_t				cpt;

	if (get_length(origin) > 20)
		return (NULL);
	d = init_c(origin);
	e = NULL;
	if ((d = monobrute(init_c(origin), 15)))
	{
		e = d;
		while ((d = monobrute(init_c(origin), d->nb_op)))
			e = d;
	}
	else
		ft_putendl("echec monobrute");
	cpt = 11;
	if (e && e->nb_op < cpt)
		cpt = e->nb_op;
	if ((d = brute(init_c(origin), cpt)))
	{
		while ((d = brute(init_c(origin), d->nb_op)))
			if (e->nb_op > d->nb_op)
				e = d;
	}
	else if (e)
		ft_putendl("echec brute");
	return (e);
}

int				main(int ac, char **av)
{
	t_list			*origin;
	t_controleur	*b;
//	t_controleur	*c;
//	t_controleur	*d;
	t_controleur	*e;

	if (ac < 3)
		exit_error(NULL, NULL);
	else
	{
		origin = get_entry(ac, av);
		aff_pile(origin);
		ft_putchar('\n');
//		c = init_c(origin);
		ft_putendl("\ninitalisation OK!");
		b = init_c(origin);
		ft_putnbr(solverv4(b));
		ft_putendl(" solver v4 OK!");
//		ft_putnbr(solver(c));
//		ft_putendl(" solver v1 OK!");
//		d = init_c(origin);
//		ft_putnbr(solverv3(d));
//		ft_putstr(" solver v3 OK!\n");
		ft_putendl("++++++++++++++++------++++++++++++++++++");
		if ((e = test_brute(origin)))
			aff_state(e);
	}
	return (0);
}
