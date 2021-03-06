/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 23:50:45 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/04/23 23:40:04 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int i;
	t_list *lst;

	i = 0;
	lst = ft_lstxnew(ac);
	while (i < ac)
	{
		ft_lstget(lst, i + 1)->content = av[i];
		i++;
	}
	ft_lstaff(lst, NULL);
	printf("%2$*3$.*3$s %1$d\n", 24, 'e', "poop");
	return (0);
}
