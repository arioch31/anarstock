/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 04:28:40 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/02/20 18:34:30 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"


typedef struct s_controleur
{
	size_t		length;
	t_list		*la;
	size_t		la_len;
	t_list		*lb;
	size_t		lb_len;
	int 		val_m;
	char		*op_j;
	size_t		nb_op;
	char		*last_op;
	int 		phase;
}				t_controleur;

typedef int (*t_fpile)(int, t_controleur*);

/*
**push_swap.c
*/
t_list *get_entry(int ac, char **av);



/*
** operations.c
*/

t_list  *get_last(t_list *start);
t_list  *get_prelast(t_list *start);
void  	rot_pile(t_list **start);
void  	revrot_pile(t_list **start);
int 	swap_pile(t_list **start);

/*
**pusher.c
*/

int 	ps_swap(int cible, t_controleur *c);
int		ps_push(int cible, t_controleur *c);
int 	ps_rot(int cible, t_controleur *c);
int 	ps_revrot(int cible, t_controleur *c);
void 	push_piler(t_list **l1, t_list **l2);

/*
**controleur.c
*/

t_list			*new_pile(t_list *origin);
t_controleur	*init_c(t_list	*start);
t_controleur	*copie_c(t_controleur	*c);
void 	destr_c(t_controleur **c);
int		ad_op(t_controleur *c, char *name);

/*
**utils.c
*/

size_t 	rank(t_list *start, int value);
t_list		*get_valued(t_list *start, int value);
t_list 		*get_ranker(t_list *start, size_t index);
size_t 			get_length(t_list *start);
size_t 			get_sublength(t_list *start, int borne, int sens);


/*
**debug.c
*/
void 	aff_pile(t_list *start);
void 	aff_state(t_controleur *c);
void 	del_list(void* content, size_t content_size);
void 	exit_error(t_list *origin, t_controleur *c);
int 	pile_triee(t_list *p);
/*
**solver.c
*/

int 	solver(t_controleur *c);
int 	solverv2(t_controleur *c);

t_controleur	*brute(t_controleur *parent, size_t it_max);

#endif
