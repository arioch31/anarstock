/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 10:34:41 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/01/26 17:25:07 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define CONVERTERS "dDiuUoOxXeEfFaAgGcCsSpn%"
# define FLAGS		"hlLjtz"
# define PREFLAGS	"0-+. #"
# define NUMERICS	"0123456789"

typedef struct  s_param
{
	size_t        p_index;//index du parametre visé suivi d'un $
	char			*padding;
	size_t        withd;//min withd *-> le parametre du va_list sert de withd
	size_t        precision;//max withd *->le parametre du va_list...
	char        length;//precise la longueur du type visé (long, short etc)
	char        type;
	void        *pp;//parametre de la fonction ft (va_list)
    char        **ptr;
	struct s_param     *next;

}            t_param;

/*
 * * padder.c
 */
char	*padd_left(char *str, size_t size);
char	*padd_zero(char *str, size_t size);
char	*padd_right(char *str, size_t size);
char	*padd_space(char *str, int is_neg);
char	*padd_plus(char *str, int is_neg);
/*
 * *param.c
 */
t_param *new_param(void);
void    aff_param(t_param *p);//voué a disparaitre!
void    destr_param(t_param *p);
t_param *arg_decrypt(char *str);
/*
 * *checker.c
 */
int     get_dollar(t_param *p, char *str);
int     get_sizes(t_param *p, char *str);
int     get_types(t_param *p, char *str);
char    *arg_sub(const char *str);
#endif
