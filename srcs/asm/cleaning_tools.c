/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:20:57 by ythomas           #+#    #+#             */
/*   Updated: 2019/10/28 18:49:21 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void			free_label(t_env *env)
{
	t_label		*tmp;

	while (env->lab_list != NULL)
	{
		tmp = env->lab_list;
		env->lab_list = env->lab_list->next;
		ft_strdel(&tmp->label);
		ft_memdel((void**)&tmp);
	}
}

static void			free_two_dim(t_line *act)
{
	int i;

	if (act->action_tab)
	{
		i = -1;
		while (act->action_tab[++i])
			ft_strdel(&act->action_tab[i]);
		ft_memdel((void**)&act->action_tab);
	}
	if (act->param_tab)
	{
		i = -1;
		while (act->param_tab[++i])
			ft_strdel(&act->param_tab[i]);
		ft_memdel((void**)&act->param_tab);
	}
}

static void			free_action(t_line *act)
{
	if (act->bit_type != NULL)
		ft_memdel((void**)&act->bit_type);
	if (act->action_line != NULL)
		ft_memdel((void**)&act->action_line);
	if (act->param_code != NULL)
		ft_memdel((void**)&act->param_code);
	if (act->param_final != NULL)
		ft_memdel((void**)&act->param_final);
	if (act->param_type != NULL)
		ft_memdel((void**)&act->param_type);
	free_two_dim(act);
}

static void			clean_actions(t_env *env)
{
	int		i;

	i = -1;
	if (env->actions)
	{
		while (env->actions[++i])
		{
			free_action(env->actions[i]);
			ft_memdel((void**)&env->actions[i]);
		}
		ft_memdel((void**)&env->actions);
	}
}

int					free_env(t_env *env)
{
	int i;

	if (env->name != NULL)
		ft_strdel(&env->name);
	if (env->comment != NULL)
		ft_strdel(&env->comment);
	if (env->file_name != NULL)
		ft_strdel(&env->file_name);
	if (env->file != NULL)
	{
		i = -1;
		while (env->file[++i])
			ft_strdel(&env->file[i]);
		ft_memdel((void**)&env->file);
	}
	clean_actions(env);
	free_label(env);
	ft_memdel((void**)&env);
	return (-1);
}
