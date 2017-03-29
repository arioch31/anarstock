/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 02:03:59 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/03/29 05:32:13 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		option_checker(t_env *env, char c)
{
	int flag;
	int flag2;

	if (!(flag = ft_strseekc("RlagdruUtcSf", c)) || flag > 11)
		return (0);
	flag2 = 1 << flag;
	if (flag2 < 64)
		env->flags = (env->flags | flag2);
	else
		env->flags = (env->flags & 63) | flag2;
	return (1);
}

int		option_reader(t_env *env, char *param)
{
	int cpt;

	cpt = 0;
	if (param)
		while (param[++cpt])
			if (!option_checker(env, param[cpt]))
				exit(printf("option %c invalide\n", param[cpt]));
	return (cpt);
}

const int	g_tab[4] = {0, 0, 0, 0};

void	test2(int ac, char **av, t_env *env)
{
	struct stat ptr;
	char		*lnk;
	int			i;

	i = 0;
	while (i < ac)
	{
		if (lstat(av[i], &ptr))
			printf("ls %s failed: %s", av[i], strerror(errno));
		else if (S_ISDIR(ptr.st_mode) && !(env->flags & F_NO_EXPLORE))
		{
			if (S_ISLNK(ptr.st_mode) && readlink(av[i], lnk, 250))
				print_dir_line(lnk);
			else
				print_dir_line(av[i]);
		}
		else
			print_line(&ptr, av[i], ".", (int*)g_tab);
		printf("\n");
		i++;
	}
	if (ac == 0)
		//print_dir_line(".");
		explore_dir(env, ".");
}

int		main(int ac, char **av)
{
	int		cpt;
	t_env	*env;

	cpt = 0;
	env = malloc(sizeof(t_env));
	env->targets = malloc(ac * sizeof(char*));
	env->nb_targets = 0;
	env->flags = 0;
	while (++cpt < ac)
	{
		if (av[cpt][0] == '-')
			option_reader(env, av[cpt]);
		else
		{
			env->targets[env->nb_targets] = av[cpt];
			env->nb_targets++;
		}
	}
	test2(env->nb_targets, env->targets, env);
	printf("testoptions %02x\n", env->flags);
	free(env->targets);
	free(env);
	return (0);
}
