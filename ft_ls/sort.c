/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 04:12:37 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/04/06 23:10:35 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		alpha_cmp(t_list *l1, t_list *l2)
{
	return (ft_strcmp(((t_entry*)l2->content)->name,
	((t_entry*)l1->content)->name));
}

int		size_cmp(t_list *l1, t_list *l2)
{
	int x;

	if ((x = ((int)((t_entry*)l1->content)->data->st_size
	- ((t_entry*)l2->content)->data->st_size)))
		return (x);
	return (alpha_cmp(l1, l2));
}

int		time_a_cmp(t_list *l1, t_list *l2)
{
	int x;

	if ((x = (int)(((t_entry*)l1->content)->data->st_atimespec.tv_sec -
	((t_entry*)l2->content)->data->st_atimespec.tv_sec)))
		return (x);
	if ((x = (int)(((t_entry*)l1->content)->data->st_atimespec.tv_nsec -
	((t_entry*)l2->content)->data->st_atimespec.tv_nsec)))
		return (x);
	return (alpha_cmp(l1, l2));
}

int		time_m_cmp(t_list *l1, t_list *l2)
{
	int x;

	if ((x = (int)(((t_entry*)l1->content)->data->st_mtimespec.tv_sec -
	((t_entry*)l2->content)->data->st_mtimespec.tv_sec)))
		return (x);
	if ((x = (int)(((t_entry*)l1->content)->data->st_mtimespec.tv_nsec -
	((t_entry*)l2->content)->data->st_mtimespec.tv_nsec)))
		return (x);
	return (alpha_cmp(l1, l2));
}

int		time_c_cmp(t_list *l1, t_list *l2)
{
	int x;

	if ((x = (int)(((t_entry*)l1->content)->data->st_ctimespec.tv_sec -
	((t_entry*)l2->content)->data->st_ctimespec.tv_sec)))
		return (x);
	if ((x = (int)(((t_entry*)l1->content)->data->st_ctimespec.tv_nsec -
	((t_entry*)l2->content)->data->st_ctimespec.tv_nsec)))
		return (x);
	return (alpha_cmp(l1, l2));
}

int		time_cr_cmp(t_list *l1, t_list *l2)
{
	int x;

	if ((x = (int)(((t_entry*)l1->content)->data->st_birthtimespec.tv_sec -
	((t_entry*)l2->content)->data->st_birthtimespec.tv_sec)))
		return (x);
	if ((x = (int)(((t_entry*)l1->content)->data->st_birthtimespec.tv_nsec -
	((t_entry*)l2->content)->data->st_birthtimespec.tv_nsec)))
		return (x);
	return (alpha_cmp(l1, l2));
}

t_list	*sort_choose(t_env *env, t_list *lst)
{
	int (*f)(t_list *l1, t_list *l2);

	if (env->flags & F_NO_SORT)
		return (lst);
	if (env->flags & F_SORT_SIZE)
		f = &size_cmp;
	else if (env->flags & F_SORT_TIME)
	{
		if (env->flags & F_USE_TIME_A)
			f = &time_a_cmp;
		else if (env->flags & F_USE_TIME_CH)
			f = &time_c_cmp;
		else if (env->flags & F_USE_TIME_CR)
			f = &time_cr_cmp;
		else
			f = &time_m_cmp;
	}
	else
		f = &alpha_cmp;
	if (env->flags & F_REV_ORDER)
		return (ft_lst_tri_as(lst, f));
	else
		return (ft_lst_tri_ds(lst, f));
}
