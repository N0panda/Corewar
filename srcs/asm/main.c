/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:07:28 by ythomas           #+#    #+#             */
/*   Updated: 2019/10/28 13:32:56 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		init_env(t_env *env)
{
	env->name = NULL;
	env->comment = NULL;
	env->file_name = NULL;
	env->file = NULL;
	env->actions = NULL;
	env->lab_list = NULL;
}

int				parse_and_get_params(char *av, t_env *env)
{
	init_env(env);
	if (av[ft_strlen(av) - 1] != 's')
		return (ft_error(2, av));
	else if (sizeof(av) > PROG_NAME_LENGTH)
		return (ft_error(4, av));
	if (get_and_copy_file(env, av) != 0)
		return (-1);
	if (build_actions(env, av) == -1)
		return (-1);
	return (0);
}

int				main(int ac, char **av)
{
	t_env	*env;
	int		i;

	if (ac < 2)
		return (ft_error(1, NULL));
	i = 0;
	while (++i < ac)
	{
		if (!(env = ft_memalloc(sizeof(t_env))))
			return (ft_error(3, av[i]));
		if (parse_and_get_params(av[i], env) != -1)
			create_binary_file(env);
		free_env(env);
	}
	return (0);
}
