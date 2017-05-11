/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specific_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facorreg <facorreg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 10:39:48 by facorreg          #+#    #+#             */
/*   Updated: 2017/05/11 05:18:55 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static const t_printf		g_args[] =
{
	{'%', &percent_wrapper, 1},
	{'c', &putchar_wrapper, 256},
	{'s', &putstr_wrapper, 256},
	{'d', &putnbr_wrapper, 10},
	{'u', &print_unsigned, 10},
	{'x', &print_hex, 16},
	{'o', &print_oct, 8},
	{'p', &print_addr, 16},
	{'b', &base_wrapper, 2},
	{'C', &putwstr_wrapper, 256 * 4}
	{'S', &putwstr_wrapper, 256 * 4}
};

void				print_unsigned(t_param *param, void *target, int fd)
{
	ft_putnbr_base_fd((unsigned int)target, ???, fd);
}

void				print_addr(t_param *param, void *target, int fd)
{
	ft_putnbr_base_fd((unsigned long)target, 16, fd);
}

void				putnbr_wrapper(t_param *param, void *target, int fd)
{
	ft_putnbr_fd((int)target, fd);
}

void				percent_wrapper(t_param *param, void *target, int fd)
{
	ft_putchar_fd('%', fd);
}

void				putchar_wrapper(t_param *param, void *target, int fd)
{
	ft_putchar_fd((char)target, fd);
}

void				putstr_wrapper(t_param *param, void *target, int fd)
{
	ft_putstr_fd((char *)target, fd);
}
