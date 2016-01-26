/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 10:34:41 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/01/26 13:10:26 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define CONVERTERS "dDiuUoOxXeEfFaAgGcCsSp%"
# define FLAGS		"hlLjtz"
# define PREFLAGS	"0123456789-+. $"

char	*padd_left(char *str, size_t size);
char	*padd_zero(char *str, size_t size);
char	*padd_right(char *str, size_t size);

/*
typedef struct  s_param
{
void        *p$;//index du parametre visé suivi d'un $
t_flaglist    flags;// - et + # 0 ou ' '
size_t        withd;//min withd *-> le parametre du va_list sert de withd
size_t        precision;//max withd *->le parametre du va_list...
size_t        length;//precise la longueur du type visé (long, short etc)
char        type;
void        *p;//parametre de la fonction ft (va_list)
s_param     *next;

}            t_param;
typedef struct s_flaglist
{
    int left;
    int space;
    int plus;
    int hash;
    int zero;
}               t_flaglist;
*/

#endif
