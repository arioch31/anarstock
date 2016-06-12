/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 23:58:46 by aeguzqui          #+#    #+#             */
/*   Updated: 2016/06/11 01:07:34 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LEMIN_H
# define _LEMIN_H
# include "get_next_line.h"


typedef	struct	s_fourmi
{
	int			name;
	t_list		*path;
	int 		finished;

}				t_fourmi;

typedef	struct	s_salle
{
	char		*name;
	int			coo_x;
	int			coo_y;
	int			utile;
	t_list		*liens;
	int			occupee;
	int			dist_start;
	t_fourmi	*fourmi;
}				t_salle;

typedef struct	s_ruche
{
	int			nb_fourmis;
	int			rest;
	t_list		*fourmis;
	t_list		*dispo;
	t_list		*list_salles;
	t_salle		*start;
	t_salle		*end;
	t_list		*short_path;
	t_list		*list_paths;
	t_list		*list_maps;
}				t_ruche;

/*
**fourmi.c
*/
int		action(t_ruche *ruche, t_list *map);


/*
**salles.c
*/

t_salle			*newsalle(char *line);
int				add_salle(t_ruche *ruche, char *line, int utile);
char			*set_salles(int fd, t_ruche *ruche, char **line);
t_salle			*get_salle(t_salle *salle, t_ruche *ruche);
t_salle			*find_salle(char *name, t_ruche *ruche);

/*
**utils.c
*/
int				set_liaison(char *line, t_ruche *ruche);
int				nb_vliaisons(t_salle *salle);

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
void			test_mapping(t_ruche *ruche);

/*
**debug.c
*/
void			aff_couvee(t_list *fourmis);
void			aff_liens(t_salle *salle);
void			aff_path(t_list *path);
void			aff_map(t_list *list_paths);
void			aff_salle(t_list *list);
void			aff_ruche(t_ruche *ruche);

/*
**ruche.c
*/

int				delim_ruche(t_ruche *ruche);
void			next_step(t_ruche *ruche, t_salle *current);
void			addstep_short(t_ruche *ruche, t_salle *current);
t_ruche			*init_ruche(void);

/*
**pathfinder.c
*/
void			add_paths(t_ruche *ruche, t_list *pathlist);
void			select_paths(t_ruche *ruche);
t_list			*trim_paths(t_ruche *ruche);
int				addstep_path(t_ruche *ruche, t_list *path, t_salle *current);

void			list_clear(void *content, size_t content_size);
void			clear_salle(t_list *list);
void			clear_map(t_list *map);
void			clear_listmap(t_list *list_maps);
void			clear_ruche(t_ruche *ruche);
/*
**crossing.c
*/

t_list			*map_in_list(t_list *map, t_list *listmap);
int				path_in_map(t_list *path, t_list *listpath);
int				map_equ(t_list *pathlist1, t_list *pathlist2);
int				is_used(t_list *path, t_salle *salle);
int				path_equ(t_list *path1, t_list *path2);
int				crossing(t_ruche *ruche, t_list *path1, t_list *path2);
int				multicross(t_ruche *ruche, t_list *pathlist, t_list *path);

#endif
