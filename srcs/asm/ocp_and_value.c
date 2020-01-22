/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocp_and_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:57:51 by ythomas           #+#    #+#             */
/*   Updated: 2019/10/28 19:12:07 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

unsigned char			get_ocp_integer_value(t_line *act)
{
	unsigned char	result;
	int				i;
	int				j;

	i = 0;
	j = 3;
	result = 0b00000000;
	while (i < act->nb_params)
	{
		result |= (act->param_code[i] << (2 * j));
		i++;
		j--;
	}
	return (result);
}

int						set_ocp_and_value(t_env *env, t_line *act)
{
	int				pos;

	(void)env;
	pos = 0;
	if (act->op_position == 1)
		pos = 1;
	if (g_op_tab[act->instruction - 1].carry == 1)
	{
		act->ocp = 1;
		act->value_ocp = get_ocp_integer_value(act);
	}
	return (0);
}
