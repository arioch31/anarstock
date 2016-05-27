/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 01:13:08 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/05/27 23:37:18 by aeguzqui         ###   ########.fr       */
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
	size_t			cpt;

	if (get_length(origin) > 50)
		return (NULL);
	d = init_c(origin);
	e = NULL;
	if ((d = monobrute(init_c(origin), 15)))
	{
		e = d;
		while ((d = monobrute(init_c(origin), d->nb_op)))
			e = d;
	}
	cpt = 9;
	if (e && e->nb_op < cpt)
		cpt = e->nb_op;
	if ((d = brute(init_c(origin), cpt)))
	{
		e = d;
		while ((d = brute(init_c(origin), d->nb_op)))
			if (e->nb_op > d->nb_op)
				e = d;
	}
	return (e);
}

int				main(int ac, char **av)
{
	t_list			*origin;
	t_controleur	*b;

	if (ac < 2)
		exit_error(NULL, NULL);
	else
	{
		origin = get_entry(ac, av);
		if ((b = test_brute(origin)))
			aff_journal(b);
		else
		{
			b = init_c(origin);
			solverv4(b);
			if (b->nb_op < 1000)
				aff_journal(b);
			else
			{
				ft_putnbr(b->nb_op);
				ft_putendl(" operations effectuees");
			}
		}
	}
	return (0);
}
