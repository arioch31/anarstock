/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 04:28:40 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/03/07 17:13:11 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# define STR_F (char*[]){"sa","pa","ra","rb","rr","ss","rrr","rrb","rra","pb","sb"}

enum	e_codef
{
	SA,
	PA,
	RA,
	RB,
	RR,
	SS,
	RRR,
	RRB,
	RRA,
	PB,
	SB
};

typedef struct	s_controleur
{
	size_t		length;
	t_list		*la;
	size_t		la_len;
	t_list		*lb;
	size_t		lb_len;
	int			val_m;
	size_t		nb_op;
	int			phase;
	char		*code_f;
	char		*last_op;
	size_t		size_codef;
}				t_controleur;

typedef int	(*t_fpile)(int, t_controleur*);

/*
**push_swap.c
*/

t_list			*get_entry(int ac, char **av);
void			aff_journal(t_controleur *c);

/*
** operations.c
*/

t_list			*get_last(t_list *start);
t_list			*get_prelast(t_list *start);
void			rot_pile(t_list **start);
void			revrot_pile(t_list **start);
int				swap_pile(t_list **start);

/*
**pusher.c
*/

int				ps_swap(int cible, t_controleur *c);
int				ps_push(int cible, t_controleur *c);
int				ps_rot(int cible, t_controleur *c);
int				ps_revrot(int cible, t_controleur *c);
void			push_piler(t_list **l1, t_list **l2);

/*
**controleur.c
*/

t_list			*new_pile(t_list *origin);
t_controleur	*init_c(t_list	*start);
t_controleur	*copie_c(t_controleur	*c);
void			destr_c(t_controleur **c);
int				ad_op(t_controleur *c, int code_f);

/*
**utils.c
*/

size_t			rank(t_list *start, int value);
t_list			*get_valued(t_list *start, int value);
t_list			*get_ranker(t_list *start, size_t index);
size_t			get_length(t_list *start);
size_t			get_sublength(t_list *start, int borne, int sens);

/*
**debug.c
*/

void			aff_pile(t_list *start);
void			aff_state(t_controleur *c);
void			del_list(void *content, size_t content_size);
void			exit_error(t_list *origin, t_controleur *c);
int				pile_triee(t_list *p, int sens);

/*
**solver.c
*/

int				solver(t_controleur *c);
int				solverv2(t_controleur *c);
int				solverv3(t_controleur *c);
int				mover(t_controleur *c, int cible);
int				mover_v2(t_controleur *c);

/*
**brute.c
*/

t_controleur	*brute(t_controleur *parent, size_t it_max);
t_controleur	*monobrute(t_controleur *parent, size_t it_max);

/*
**canceler.c
*/

void	c_pa(t_controleur *c);
void	c_pb(t_controleur *c);
void	c_sa(t_controleur *c);
void	c_sb(t_controleur *c);
void	c_ss(t_controleur *c);
void	c_ra(t_controleur *c);
void	c_rb(t_controleur *c);
void	c_rr(t_controleur *c);
void	c_rra(t_controleur *c);
void	c_rrb(t_controleur *c);
void	c_rrr(t_controleur *c);

# define TAB_F (t_fpile[4]){ps_push, ps_swap, ps_rot, ps_revrot}
# define CTAB_F (void fct(t_controleur)){c_sa, c_pa, c_ra, c_rb, c_rr, c_ss, c_rrr, c_rrb, c_rra, c_pb, c_sb}
#endif
