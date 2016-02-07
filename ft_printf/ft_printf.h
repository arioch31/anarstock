/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 10:34:41 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/04 18:25:12 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# define CONVERTERS "dDiuUoOxXeEfFaAgGcCsSpn%"
# define FLAGS		"hlLjtz"
# define PREFLAGS	"0-+. #"
# define NUMERICS	"0123456789"
# define INT_CONV	"dDiuUoOxX"
# define FLOAT_CONV "aAeEfFgG"
# define FLOAT_FORB "ghkzjt"
# define HASH_VALID	"eEfFgGoOxX"

typedef struct			s_param
{
	t_list				*ptr;
	size_t				p_index;//index du parametre visé suivi d'un $
	char				*padding;
	size_t				withd;//min withd *-> le parametre du va_list sert de withd
	size_t				precision;//max withd *->le parametre du va_list... penser a '0' dans padding -> withd pr les int
	char				length;//precise la longueur du type visé (long, short etc)
	char				type;
	char				definer;
	struct s_param		*next;
}						t_param;

/*
** padder.c
*/

char					*padd_left(char *str, size_t size);
char					*padd_zero(char *str, size_t size);
char					*padd_right(char *str, size_t size);
char					*add_char(char *str, char c);
char					*padd_char(char *str, char c, int is_neg);

/*
**param.c
*/
int						check_type(t_param *p);
t_param					*arg_decrypt(char *str);
t_list					*str_tolist(const char *str);
char					*arg_sub(const char *str);
t_param					*param_list(t_list *ptr);

/*
**utils.c
*/
int						exit_where(char *msg);
void					aff_param(t_param *p);//voué a disparaitre!
t_param					*new_param(void);
void					destr_param(t_param *p);
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

char					*buff_arg(char *res, t_param *p, int is_neg);
char 					*conv_decimal(t_param *p, long long s);
char 					*conv_u_base(t_param *p, unsigned long long s);


/*
** ft_printf.c
*/

char					*conv_d(t_param *p, va_list ap);
char					*conv_u(t_param *p, va_list ap);
int						ft_printf(const char *str, ...);

#endif
