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

typedef struct s_controleur
{
	t_list		*la;
	t_list		*lb;
	char		*op_j;
	int			nb_op;
}				t_controleur;

/*
**push_swap.c
*/
void del_list(void* content, size_t content_size);
void exit_error(t_list *origin, t_controleur *c);
void aff_pile(t_list *start);
t_list *get_entry(int ac, char **av);

/*
** operations.c
*/

t_list  *get_last(t_list *start);
t_list  *get_prelast(t_list *start);
void  rot_pile(t_list **start);
void  revrot_pile(t_list **start);
int swap_pile(t_list **start);

/*
**pusher.c
*/

void push_piler(t_list **l1, t_list **l2);
int 	ps_swap(int cible, t_controleur *c);
int		ps_push(int cible, t_controleur *c);
int 	ps_rot(int cible, t_controleur *c);
int 	ps_revrot(int cible, t_controleur *c);

/*
**controleur.c
*/
t_controleur	*init_c(t_list	*start);
void 	aff_state(t_controleur *c);
int		ad_op(t_controleur *c, char *name);
int pile_triee(t_list *p);

#endif
