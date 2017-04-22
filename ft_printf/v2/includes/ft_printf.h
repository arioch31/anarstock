/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 10:34:41 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/04/22 02:15:48 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# define CONVERTERS "dDiuUoOxXcCsSpn%"
# define FLAGS		"hlLjtz"
# define PREFLAGS	"0-+ #"
# define NUMERICS	"0123456789"
# define OTHER		"$*."
# define F_ZERO 1
# define F_MINUS 2
# define F_PLUS 4
# define F_SPACE 8
# define F_DIESE 16

typedef struct			s_param
{
	t_list				*ptr;
	size_t				p_index;
	int					flags;
	size_t				withd;
	size_t				precision;
	char				length;
	char				type;
}						t_param;

typedef struct			s_printer
{
	int					dollars;
	t_list				*lst;
	t_list				*params;
	t_list				*args;
}						t_printer;

/*
** ft_printf.c
*/
int						ft_printf(const char *str, ...);

/*
** printer.c
*/
int		lst_write(t_list *p);
char	*lst_dup(t_list *lst);
/*
** ft_printf.c
*/

int		get_dollar(char *str);
int		get_sizes(t_param *p, char *str);
int		get_types(t_param *p, char *str);

#endif
