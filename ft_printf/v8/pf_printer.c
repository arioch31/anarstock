/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 19:17:39 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/05/11 05:18:55 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_int(int fd, t_param *p, uintmax_t nb, int base)
{
	int	i;

	i = int_strlen(nb, base);
	if (base == 10 && nb < 0)
		i++;

	if (p->withd && p->withd > i)
		paddeur(fd, p, i);
}

int	pf_int_route(int fd, t_param *p, va_list *ap)
{
	size_t		size_p;
	int			base
	if (!p->length)
		size_p = sizeof(int);
	else if (p->length == 'g')
		size_p = sizeof(short short int);
	else if (p->length == 'h')
		size_p = sizeof(short int);
	else if (p->length == 'l')
			size_p = sizeof(long int);
	else if (p->length == 'k')
			size_p = sizeof(long long int);
	else
		return (-1);
	if (p->type == 'o')
		base = 8;
	else if (p->type == 'x')
		base = 16;
	else
		base = 10;
	return (pf_int(fd, p, va_arg(ap, size_p), base));
}

int print_arg(int fd, char *str, va_list *ap, int len)
{
	t_param	p;
	int		ret;

	ft_bzero(&p, sizeof(t_param));
	if (!get_withd(p, str, ap))
		return (-1);
	else
	
}
