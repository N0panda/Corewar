/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 14:18:48 by ythomas           #+#    #+#             */
/*   Updated: 2019/10/28 18:28:06 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			count_param(char **tab, int params)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i == params);
}

int			set_total_distance(t_env *env)
{
	int i;
	int	nb;

	i = 0;
	nb = 0;
	while (env->actions[i])
	{
		if (env->actions[i]->type == ZZ_OP)
		{
			env->actions[i]->dist = nb;
			nb = nb + env->actions[i]->octet;
		}
		i++;
	}
	env->champion_size = nb;
	return (0);
}

long		atoi_ind_dir(char *str)
{
	long	nb;
	int		i;
	int		neg;

	i = 0;
	nb = 0;
	neg = 1;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * neg);
}

long		atoi_reg(char *str)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	if (str[i] == '0')
		return (-1);
	while (str[i] <= '9' && str[i] >= '0')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (str[i])
		return (-1);
	return (nb);
}

int			check_empty_line(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == '#' || str[i] == ';')
		return (0);
	i = -1;
	while (str[++i])
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
			return (1);
	return (0);
}
