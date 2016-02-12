/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 10:34:41 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/12 03:03:56 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# define CONVERTERS "dDiuUoOxXeEfFaAgGcCsSpn%"
# define FLAGS		"hlLjtz"
# define PREFLAGS	"0-+ #"
# define NUMERICS	"0123456789"
# define INT_CONV	"dDiuUoOxX"
# define FLOAT_CONV "aAeEfFgG"
# define FLOAT_FORB "ghkzjt"
# define HASH_VALID	"eEfFgGoOxX"

typedef struct			s_param
{
	t_list				*ptr;
	size_t				p_index;
	char				*padding;
	size_t				withd;
	size_t				precision;
	char				length;
	char				type;
	struct s_param		*next;
}						t_param;

/*
** padder.c
*/

char					*padd_left(char *str, size_t size);
char					*padd_zero(char *str, size_t size);
char					*padd_right(char *str, size_t size);
char					*add_char(char *str, char c);

/*
**param.c
*/

t_param					*arg_decrypt(char *str);
t_list					*str_tolist(const char *str);
char					*arg_sub(const char *str);
t_param					*param_list(t_list *ptr);

/*
** buff_arg.c
*/

char					*buff_arg(char *res, t_param *p);
int						withd_modifier(t_param *p, int neg);
char					*buff_intstr(t_param *p, char *res, int neg);
char					*buff_decimal(t_param *p, intmax_t s);
char					*buff_u_base(t_param *p, uintmax_t s);

/*
**utils.c
*/

t_param					*new_param(void);
void					destr_param(t_param *p);
int						app_param(t_param **start, t_param *elem);

/*
**checker.c
*/

int						get_dollar(t_param *p, char *str);
int						get_sizes(t_param *p, char *str);
int						get_types(t_param *p, char *str);
int						check_char(t_param *p);
int						err_checker(t_param *p);

/*
** converter.c
*/

char					*conv_ws(t_param *p, va_list ap);
char					*conv_p(t_param *p, va_list ap);
void					conv_n(t_param *p, t_list *start, va_list ap);
char					*conv_d(t_param *p, va_list ap);
char					*conv_u(t_param *p, va_list ap);

/*
** ft_wchar.c
*/

long int				ft_wctolint(wchar_t wc);
int						ft_writewc(wchar_t wc);
char					*ft_wctostr(wchar_t wc);
char					*ft_strwctostr(wchar_t *wc);
int						ft_writeswc(wchar_t *wc);

/*
** ft_printf.c
*/
void					get_values(t_param *p, va_list ap, t_list *lst);
int						ft_printf(const char *str, ...);

#endif
