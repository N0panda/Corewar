/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:48:08 by ythomas           #+#    #+#             */
/*   Updated: 2019/10/28 18:32:24 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	int		get_size_op_bytes(t_line *act)
{
	int	param_size;
	int i;

	param_size = 0;
	i = -1;
	act->dist = 0;
	while (++i < act->nb_params)
		param_size = param_size + act->bit_type[i];
	return (param_size + act->ocp + 1);
}

int				set_octet_distance(t_env *env)
{
	int i;

	i = 0;
	while (env->actions[i])
	{
		if (env->actions[i]->type == ZZ_OP)
			env->actions[i]->octet = get_size_op_bytes(env->actions[i]);
		else
			env->actions[i]->octet = 0;
		i++;
	}
	return (0);
}

int				fill_actions_struct(t_env *env, char *file_name)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (env->file[i])
	{
		if (check_empty_line(env->file[i]) == 1)
		{
			env->actions[j]->id_line = j;
			if (ft_strstr(env->file[i], NAME_CMD_STRING)
				|| ft_strstr(env->file[i], COMMENT_CMD_STRING))
			{
				if (!(env->actions[j]->action_line = ft_strdup(env->file[i])))
					return (ft_error(6, file_name));
			}
			else if (!(env->actions[j]->action_line = epur_str(env->file[i])))
				return (ft_error(6, file_name));
			j++;
		}
		i++;
	}
	return (0);
}

int				parse_actions(t_env *env)
{
	int i;

	i = -1;
	while (env->actions[++i])
	{
		env->actions[i]->type = 0;
		if (parse_op_and_name(env, env->actions[i],
			env->actions[i]->action_line) == -1)
			return (-1);
	}
	i = -1;
	while (env->actions[++i])
	{
		if (env->actions[i]->type == ZZ_OP)
		{
			if (parse_param(env, env->actions[i]) == -1)
				return (-1);
			if (set_ocp_and_value(env, env->actions[i]) == -1)
				return (-1);
		}
		else
			env->actions[i]->ocp = 0;
	}
	return (0);
}

int				build_actions(t_env *env, char *file_name)
{
	if (fill_actions_struct(env, file_name) == -1)
		return (-1);
	if (parse_actions(env) == -1)
		return (-1);
	if (bad_spacing(env) == -1)
		return (-1);
	set_octet_distance(env);
	set_total_distance(env);
	set_distance_label_from_start(env);
	if (fill_label_param_value(env) == -1)
		return (-1);
	return (0);
}
