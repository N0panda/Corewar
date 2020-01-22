/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param_detail.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:20:09 by ythomas           #+#    #+#             */
/*   Updated: 2019/10/28 19:10:05 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	int		check_dir_ind_validity(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (-1);
		i++;
	}
	return (0);
}

int				check_if_lab_exist(t_env *env, t_line *act, char *str, int t)
{
	t_label *tmp;

	if (act->param_type[t] == UNASIGNED)
	{
		if ((T_IND & g_op_tab[act->instruction - 1].args_type[t]) == 0)
			return (parse_error(7, env->file_name, str));
		act->param_type[t] = T_IND_LABEL;
		act->bit_type[t] = TWO_SIZE;
		act->param_code[t] = IND_CODE;
	}
	tmp = env->lab_list;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->label, str + 1) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (parse_error(9, env->file_name, str));
}

int				check_if_ind(t_env *env, t_line *act, char *str, int t)
{
	long	nb;

	if ((T_IND & g_op_tab[act->instruction - 1].args_type[t]) == 0)
		return (parse_error(7, env->file_name, str));
	act->param_type[t] = T_IND;
	act->bit_type[t] = TWO_SIZE;
	act->param_code[t] = IND_CODE;
	if (check_dir_ind_validity(str + 1) == -1)
		return (parse_error(6, env->file_name, str + 1));
	if ((nb = atoi_ind_dir(str)) > 32767 || nb < -32768)
		return (parse_error(6, env->file_name, str + 1));
	act->param_final[t] = (int)nb;
	return (0);
}

int				check_if_dir(t_env *env, t_line *act, char *str, int t)
{
	long	nb;

	if ((T_DIR & g_op_tab[act->instruction - 1].args_type[t]) == 0)
		return (parse_error(7, env->file_name, str));
	act->param_type[t] = T_DIR;
	act->param_code[t] = DIR_CODE;
	act->bit_type[t] = (act->size_type ? FOUR_SIZE : TWO_SIZE);
	if (str[1] == ':')
	{
		if (check_if_lab_exist(env, act, str + 1, t) == -1)
			return (-1);
		act->param_type[t] = T_DIR_LABEL;
		return (0);
	}
	if (check_dir_ind_validity(str + 1) == -1)
		return (parse_error(6, env->file_name, str + 1));
	if ((((nb = atoi_ind_dir(str + 1)) > SHRT_MAX
		|| nb < SHRT_MIN) && (act->size_type == 0))
		|| ((act->size_type == 1) && (nb > INT_MAX || nb < INT_MIN)))
		return (parse_error(6, env->file_name, str + 1));
	act->param_final[t] = (int)nb;
	return (0);
}

int				check_if_reg(t_env *env, t_line *act, char *str, int t)
{
	long		nb;

	if ((T_REG & g_op_tab[act->instruction - 1].args_type[t]) == 0)
		return (parse_error(8, env->file_name, str));
	if (str[1] == '\0' || str[1] == '0')
		return (parse_error(7, env->file_name, str));
	nb = atoi_reg(str + 1);
	if (nb > 16 || nb < 1)
		return (parse_error(7, env->file_name, str));
	act->param_type[t] = T_REG;
	act->param_code[t] = REG_CODE;
	act->bit_type[t] = REG_CODE;
	act->param_final[t] = (int)nb;
	return (0);
}
