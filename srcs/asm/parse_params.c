/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:13:21 by ythomas           #+#    #+#             */
/*   Updated: 2019/10/28 19:09:14 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		creat_param_tab(t_line *act, char *file_name)
{
	char	*str;
	char	*tmp;
	int		i;

	if ((str = ft_strnew(0)) == NULL)
		return (ft_error(6, file_name));
	i = 0;
	while (act->action_tab[i + act->op_position + 1])
	{
		tmp = str;
		if (!(str = ft_strjoin(str, act->action_tab[i + act->op_position + 1])))
			return (free_tools(&str, ft_error(6, file_name), NULL, NULL));
		ft_strdel(&tmp);
		i++;
	}
	if (!(act->param_tab = ft_strsplit(str, ',')))
		return (free_tools(&str, ft_error(6, file_name), NULL, NULL));
	if (!count_param(act->param_tab, act->nb_params))
		return (free_tools(&str, 1, file_name, act->action_line));
	ft_strdel(&str);
	return (0);
}

static int		get_type_param(t_env *env, t_line *act, char *str, int t)
{
	int		stat;

	act->param_type[t] = UNASIGNED;
	if (str[0] == 'r')
		stat = check_if_reg(env, act, str, t);
	else if (str[0] == '%')
		stat = check_if_dir(env, act, str, t);
	else if (str[0] == ':')
		stat = check_if_lab_exist(env, act, str, t);
	else if ((str[0] >= '1' && str[0] <= '9') || str[0] == '-')
		stat = check_if_ind(env, act, str, t);
	else
		stat = -1;
	return (stat);
}

static int		get_size_type(t_line *act)
{
	if (D4(act->instruction))
		act->size_type = 1;
	else
		act->size_type = 0;
	return (0);
}

static int		creat_param_type(t_env *env, t_line *act)
{
	int		i;

	i = 0;
	if (!(act->param_type = ft_memalloc(sizeof(int) * act->nb_params)))
		return (-1);
	if (!(act->bit_type = ft_memalloc(sizeof(int) * act->nb_params)))
		return (-1);
	get_size_type(act);
	while (act->param_tab[i])
	{
		if (get_type_param(env, act, act->param_tab[i], i) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int				parse_param(t_env *env, t_line *act)
{
	t_op		*op;

	op = g_op_tab;
	act->nb_params = op[act->instruction - 1].argc;
	if (creat_param_tab(act, env->file_name) == -1)
		return (-1);
	if (!(act->param_final = malloc(sizeof(int) * act->nb_params)))
		return (ft_error(6, env->file_name));
	if (!(act->param_code = malloc(sizeof(int) * act->nb_params)))
		return (ft_error(6, env->file_name));
	if (creat_param_type(env, act) == -1)
		return (-1);
	return (0);
}
