/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 23:58:46 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/06/07 00:33:55 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LEMIN_H
# define _LEMIN_H
# include "get_next_line.h"

typedef	struct	s_salle
{
	char		*name;
	int			coo_x;
	int			coo_y;
	int			utile;
	t_list		*liens;
	int			occupee;
	int			dist_start;
}				t_salle;

typedef struct	s_ruche
{
	int			nb_fourmis;
	t_list		*list_salles;
	t_salle		*start;
	t_salle		*end;
	t_list		*short_path;
}				t_ruche;

/*
**salles.c
*/

t_salle			*newsalle(char *line);
int				add_salle(t_ruche *ruche, char *line, int utile);
char			*set_salles(int fd, t_ruche *ruche, char **line);
t_salle			*get_salle(t_salle *salle, t_ruche *ruche);
t_salle			*find_salle(char *name, t_ruche *ruche);
int				set_liaison(char *line, t_ruche *ruche);

/*
**readfile.c
*/

int				int_nozero(char *test);
int				iscomment(char *test);
int				id_line(int fd, char **line);
int				verif_file(int fd, t_ruche *ruche);
int				is_link(t_salle	*salle1, t_salle *salle2);

/*
**main.c
*/

int				error_msg(char *msg);
void			*nul_errmsg(char *msg);

/*
**debug.c
*/
void			aff_liens(t_salle *salle);
void			aff_path(t_list *path);
void			aff_salle(t_list *list);
void			aff_ruche(t_ruche *ruche);

/*
**ruche.c
*/

int				delim_ruche(t_ruche *ruche);
void			next_step(t_ruche *ruche, t_salle *current);
int				test_shortpath(t_ruche *ruche);

/*
**pathfinder.c
*/

int				is_used(t_list *path, t_salle *salle);

#endif
