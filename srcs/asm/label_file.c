/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:31:03 by ythomas           #+#    #+#             */
/*   Updated: 2019/10/23 17:57:46 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					set_label_value(t_env *env, char *str, int value)
{
	t_label *tmp;

	tmp = env->lab_list;
	str[ft_strlen(str) - 1] = '\0';
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->label, str) == 0)
			tmp->position = value;
		tmp = tmp->next;
	}
	return (0);
}

int					set_distance_label_from_start(t_env *env)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	while (env->actions[i])
	{
		if (env->actions[i]->type == ZZ_LAB
			|| env->actions[i]->op_position == 1)
			set_label_value(env, env->actions[i]->action_tab[0], count);
		count = count + env->actions[i]->octet;
		i++;
	}
	return (0);
}

static char			*copy_label(char *str)
{
	int		len;
	char	*result;
	int		i;

	len = ft_strlen(str);
	if (!(result = malloc(sizeof(char) * len)))
		return (NULL);
	i = 0;
	while (str[i + 1])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static t_label		*create_maillon(char *str)
{
	t_label		*new;

	if (!(new = ft_memalloc(sizeof(t_label))))
		return (NULL);
	new->next = NULL;
	new->position = 0;
	if ((new->label = copy_label(str)) == NULL)
		return (NULL);
	return (new);
}

int					create_label(t_env *env, char *str)
{
	t_label *tmp;

	if (str[ft_strlen(str) - 1] != ':')
		return (parse_error(3, env->file_name, str));
	if (env->lab_list == NULL)
	{
		if ((env->lab_list = create_maillon(str)) == NULL)
			return (ft_error(6, env->file_name));
		else
			return (0);
	}
	tmp = env->lab_list;
	while (tmp->next != NULL)
	{
		if (ft_strcmp(str, tmp->label) == 0)
			return (parse_error(4, env->file_name, tmp->label));
		tmp = tmp->next;
	}
	if ((tmp->next = create_maillon(str)) == NULL)
		return (ft_error(6, env->file_name));
	return (0);
}
