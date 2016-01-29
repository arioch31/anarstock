/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 03:03:20 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/01/29 04:28:08 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_param	*new_param(void)
{
	t_param	*p;

	p = malloc(sizeof(t_param));
	p->p_index = 0;
	p->padding = ft_strnew(0);
	p->next = NULL;
	p->pp = NULL;
	p->withd = 0;
	p->precision = 0;
	p->length = 0;
	p->type = 0;
	p->ptr = malloc(sizeof(char*));
	return (p);
}

void	aff_param(t_param *p)
{
	ft_putendl("=============================================");
	ft_putstr("affichage parametres:\n index :\t");
	ft_putnbr(p->p_index);
	ft_putstr("\npadding :\t");
	ft_putstr(p->padding);
	ft_putstr("\n withd:  \t");
	ft_putnbr(p->withd);
	ft_putstr("\nprecision:\t");
	ft_putnbr(p->precision);
	ft_putstr("\nflags:  \t");
	if (p->length)
		ft_putchar(p->length);
	else
		ft_putchar('0');
	ft_putstr("\ntype: \t\t");
	if (p->type)
		ft_putchar(p->type);
	else
		ft_putchar('0');
	ft_putstr("\n str visée: \t");
	if (p->ptr && (p->ptr->content))
		ft_putendl(p->ptr->content);
	ft_putstr("\n\n");
}

void	destr_param(t_param *p)
{
	free(p->padding);
	p->padding = NULL;
	p->ptr = NULL;
	free(p);
}

t_param	*arg_decrypt(char *str)
{
	t_param	*p;
	char	*ptr;
	char	c;
	int		i;

	p = new_param();
	i = 0;
	if (*str != '%')
		return (NULL);
	if (get_dollar(p, str + 1) > 0)
		str = ft_strchr(str, '$') + 1;
	if (!get_sizes(p, str + 1))
		return (NULL);
	return (p);
}
