/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:19:33 by ythomas           #+#    #+#             */
/*   Updated: 2019/10/23 13:50:26 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int			seek_label(t_env *env, char *str)
{
	t_label *tmp;

	tmp = env->lab_list;
	while (tmp)
	{
		if (ft_strcmp(str, tmp->label) == 0)
			return (tmp->position);
		tmp = tmp->next;
	}
	return (-1);
}

int					pos_in_tab(t_line *act, int position_label)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (i < position_label)
	{
		nb = nb + act->bit_type[i];
		i++;
	}
	if (act->ocp == 1)
		nb++;
	return (nb + 1);
}

int					set_param_value_on_line(t_env *env, t_line *act)
{
	int		i;
	int		nb;

	i = 0;
	while (i < act->nb_params)
	{
		if (act->param_type[i] == T_IND_LABEL
			|| (act->param_type[i] == T_DIR_LABEL))
		{
			nb = seek_label(env, ft_strchr(act->param_tab[i], ':') + 1);
			nb = nb - act->dist;
			act->param_final[i] = nb;
		}
		i++;
	}
	return (0);
}

int					fill_label_param_value(t_env *env)
{
	int		i;

	i = 0;
	while (env->actions[i])
	{
		if (set_param_value_on_line(env, env->actions[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}
