/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 10:34:41 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/05/11 05:18:55 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# define CONVERTERS "dDiuUoOxXcCsSpn%"
# define INT_CONV	"diuxo"
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
	int					flags;
	size_t				withd;
	size_t				precision;
	char				length;
	char				type;
	void				*target;
}						t_param;

/*
** ft_printf.c
*/
int						ft_printf(const char *str, ...);
int						ft_vprintf(int fd, const char *str, ...);

/*
** printer.c
*/

/*
** ft_printf.c
*/
int						get_prec(t_param *p, const char *str, va_list *ap);
int						get_withd(t_param *p, const char *str, va_list *ap);
int						get_types(t_param *p, char *str);

#endif
