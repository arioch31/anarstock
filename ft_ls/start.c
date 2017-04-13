/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeguzqui <aeguzqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 02:03:59 by aeguzqui          #+#    #+#             */
/*   Updated: 2017/04/06 23:12:15 by aeguzqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		option_checker(t_env *env, char c)
{
	int flag;
	int flag2;

	if (!c || ((flag = ft_strindex("RlagdrucUtSf", c) + 1) && flag > 12))
		return (0);
	flag2 = 1 << (flag - 1);
	if (flag2 < 64)
		env->flags = (env->flags | flag2);
	else if (flag2 > 511)
		env->flags = (env->flags & 511) | flag2;
	else
		env->flags = (env->flags & 0xFFFFFE3F) | flag2;
	if (!AUTHORISE_U && (env->flags & F_USE_TIME_CR))
		exit(printf("-U n'est pas supporté par le système\n"));
	return (1);
}

int		option_reader(t_env *env, char *param)
{
	int cpt;

	cpt = 0;
	if (param && param[1])
	{
		while (param[++cpt])
			if (!option_checker(env, param[cpt]))
				exit(printf("option %c invalide\n", param[cpt]));
	}
	return (cpt);
}

t_env	*env_setup(int ac, char **av)
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
		if (av[cpt][0] != '-' || !option_reader(env, av[cpt]))
		{
			env->targets[env->nb_targets] = av[cpt];
			env->nb_targets++;
		}
	}
	return (env);
}

int		main(int ac, char **av)
{
	t_env		*env;
	int			i;

	env = env_setup(ac, av);
	i = 0;
	while (i < env->nb_targets)
	{
		printf("%s", i ? "\n" : "");
		explore_dir(env, env->targets[i]);
		i++;
	}
	if (env->nb_targets == 0)
		explore_dir(env, ".");
	free(env->targets);
	free(env);
	return (0);
}
