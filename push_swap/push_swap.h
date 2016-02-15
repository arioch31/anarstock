/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 04:28:40 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/15 04:51:49 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

void exit_error(void);
t_list  *crea_pile(int nb, int *tab);
void aff_pile(t_list *start);
int *get_numbers(int ac, char **av);
void print_tab(int *tab, size_t size);

t_list  *get_last(t_list *start);
t_list  *get_prelast(t_list *start);
void  rot_pile(t_list **start);
void  revrot_pile(t_list **start);
int swap_pile(t_list **start);

void push_piler(t_list **l1, t_list **l2);


#endif
