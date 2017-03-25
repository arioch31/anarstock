/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 00:03:15 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/03/25 05:43:52 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	aff_test(t_list *l)
{
	ft_putstr((char*)l->content);
	ft_putchar('\t');
}

int		cmp_test(t_list *l1, t_list *l2)
{
	int	i1;
	int	i2;

	i1 = ft_atoi(l1->content);
	i2 = ft_atoi(l2->content);
	return (i1 - i2);
}

int		main(int ac, char **av)
{
	t_list	*lst;
	t_list	*test;
	t_list	*test2;
	t_list	*test3;
	int		i;

	if (ac > 1)
	{
		i = 0;
		while (++i < ac)
			ft_lstadd(&lst, ft_lstnew((av[i]), ft_strlen(av[i])));
		ft_lstaff(lst, &aff_test);
		test = ft_lstnew("666", 3);
		test->next = ft_lstnew("667", 3);
		test->next->next = ft_lstnew("668", 3);
		test3 = test->next;
		test2 = ft_lstget(lst, 5);
		ft_lstaff(test, &aff_test);
		ft_putendl("=============");
		ft_lstinsert_one(&(test2), &(test->next->next));
		ft_lstaff(lst, &aff_test);
		ft_lstaff(test2, &aff_test);
		//ft_lstinsert_one(&(lst->next), &test2);
		//getchar();
		//ft_lstaff(lst, &aff_test);
	}
}
