/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:46:12 by ythomas           #+#    #+#             */
/*   Updated: 2019/10/28 18:48:23 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				free_tools(char **str, int er, char *name, char *line)
{
	ft_strdel(str);
	if (er == 1)
		parse_error(10, name, line);
	return (-1);
}

static int		check_bad_spacing(t_env *env, t_line *act, int index)
{
	int		i;

	if (act->action_tab[index][0] == ',')
		return (parse_error(12, env->file_name, act->action_line));
	while (act->action_tab[index])
	{
		i = ft_strlen(act->action_tab[index]) - 1;
		if (act->action_tab[index][i] == ',')
		{
			if (!act->action_tab[index + 1])
				return (parse_error(12, env->file_name, act->action_line));
		}
		else
		{
			if (act->action_tab[index + 1]
				&& act->action_tab[index + 1][0] != ',')
				return (parse_error(12, env->file_name, act->action_line));
		}
		index++;
	}
	return (0);
}

int				bad_spacing(t_env *env)
{
	int		i;

	i = 0;
	while (env->actions[i])
	{
		if (env->actions[i]->type == ZZ_OP)
		{
			if (check_bad_spacing(env, env->actions[i],
					env->actions[i]->op_position + 1) == -1)
				return (-1);
		}
		i++;
	}
	return (0);
}

static int		get_len(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i] && str[i] != '#' && str[i] != ';')
	{
		while ((str[i] == ' ' || str[i] == '\t')
			&& (str[i + 1] == ' ' || str[i + 1] == '\t'))
			i++;
		i++;
		count++;
	}
	if (i > 0 && (str[i - 1] == ' ' || str[i - 1] == '\t'))
		count--;
	return (count);
}

char			*epur_str(char *str)
{
	char	*new;
	int		len;
	int		i;
	int		j;

	len = get_len(str);
	i = 0;
	j = 0;
	if (!(new = ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i] && j < len)
	{
		while ((str[i] == ' ' || str[i] == '\t')
			&& (str[i + 1] == ' ' || str[i + 1] == '\t'))
			i++;
		new[j] = (str[i] == '\t' ? ' ' : str[i]);
		i++;
		j++;
	}
	return (new);
}
