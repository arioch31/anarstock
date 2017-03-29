/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 04:12:37 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/03/29 05:36:41 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		time_a_cmp(t_list *l1, t_list *l2)
{
	return ((int)(((t_entry*)l1->content)->data->st_atimespec.tv_sec -
	((t_entry*)l2->content)->data->st_atimespec.tv_sec));
}

int		time_m_cmp(t_list *l1, t_list *l2)
{
	return ((int)(((t_entry*)l1->content)->data->st_mtimespec.tv_sec -
	((t_entry*)l2->content)->data->st_mtimespec.tv_sec));
}

int		time_c_cmp(t_list *l1, t_list *l2)
{
	return ((int)(((t_entry*)l1->content)->data->st_ctimespec.tv_sec -
	((t_entry*)l2->content)->data->st_ctimespec.tv_sec));
}

int		size_cmp(t_list *l1, t_list *l2)
{
	return ((int)((t_entry*)l1->content)->data->st_size
	- ((t_entry*)l2->content)->data->st_size);
}

t_list	*sort_choose(t_env *env, t_list *lst)
{
	int (*f)(t_list *l1, t_list *l2);

	if (env->flags & F_NO_SORT)
		return (lst);
	if (env->flags & F_SORT_SIZE)
		f = &size_cmp;
	else if (env->flags & F_SORT_TIME_M)
		f = &time_m_cmp;
	else if (env->flags & F_SORT_TIME_A)
		f = &time_a_cmp;
	else if (env->flags & F_SORT_TIME_CH)
		f = &time_c_cmp;
	else
		return (lst);
	if (env->flags & F_REV_ORDER)
		return (ft_lst_tri_as(lst, f));
	else
		return (ft_lst_tri_ds(lst, f));
}
