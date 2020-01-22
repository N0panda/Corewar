/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:43:21 by ythomas           #+#    #+#             */
/*   Updated: 2019/10/28 19:07:35 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			is_there_label(t_env *env, t_line *act)
{
	int		stat;

	stat = 0;
	act->op_position = -1;
	if (ft_strchr(act->action_tab[0], ':') && (stat = 2))
		if (create_label(env, act->action_tab[0]) == -1)
			return (ft_error(6, env->file_name));
	if (act->action_tab[1])
		return (0);
	if (stat == 2)
		act->type = ZZ_LAB;
	return (1);
}

int			get_instruction_on_line(t_env *env, t_line *act, t_op *op)
{
	int		i;
	int		stat;

	i = -1;
	if ((stat = is_there_label(env, act)) == -1)
		return (-1);
	else if (stat == 1)
		return (0);
	while (++i < T_OP_SIZE - 1)
	{
		if (ft_strcmp(op[i].name, act->action_tab[0]) == 0)
		{
			act->op_position = 0;
			act->instruction = op[i].code;
		}
		else if (act->action_tab[1]
			&& ft_strcmp(op[i].name, act->action_tab[1]) == 0)
		{
			act->op_position = 1;
			act->instruction = op[i].code;
		}
	}
	if (act->op_position == -1 && act->type != ZZ_LAB)
		return (parse_error(2, env->file_name, act->action_line));
	return (0);
}

int			check_line_op(t_env *env, t_line *act, char *line)
{
	t_op	*op;

	op = g_op_tab;
	if ((act->action_tab = ft_strsplit(line, ' ')) == NULL)
		return (ft_error(5, env->file_name));
	if ((get_instruction_on_line(env, act, op)) == -1)
		return (-1);
	return (0);
}

int			parse_op_and_name(t_env *env, t_line *act, char *line)
{
	int stat;

	stat = 0;
	if (line[0] == '.')
		stat = parse_name_comm(env, act, line);
	else
	{
		if (check_line_op(env, act, line) == -1)
			return (-1);
	}
	if (stat == -1)
		return (-1);
	return (0);
}
