/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 00:06:59 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/06/29 01:18:41 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

int	exiter(int keycode, void *param)
{
	if (keycode == 53)
	{
		write(1, "wtf\n", 4);
		exit(0);
	}
	ft_putnbr(keycode);
	return (0);
}

int	main(void)
{
	void	*ptr;
	void	*screen;

	ptr = mlx_init();
	screen = mlx_new_window(ptr, 200, 200, "windowstinks");
	mlx_key_hook(screen, &exiter, ptr);
	mlx_loop(ptr);
	return (0);
}
//https://gist.github.com/KokaKiwi/4052375
