/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testgnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 19:28:41 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/05/25 21:18:48 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int	main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	**line;
	char	*test;

	ret = 0;
	test = ft_strnew(0);
	line = &test;
	if (ac > 1)
		fd = open(av[1], O_RDONLY);
	else
		fd = 0;
	while ((ret = get_next_line(fd, line)) && ret > 0)
	{
		ft_putnbr(ret);
		ft_putchar('>');
		ft_putendl(*line);
	}
	ft_putendl(*line);
	if (fd)
		close(fd);
	ft_putnbr(ret);
	return (0);
}
