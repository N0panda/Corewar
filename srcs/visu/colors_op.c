/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:45:54 by arlaine           #+#    #+#             */
/*   Updated: 2019/11/14 13:32:40 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "pixel.h"

short	set_colors(t_corewar *a, int i)
{
	short	color;

	color = a->vm->owner[i];
	if (a->vm->proc[i])
		color = 22 + a->vm->proc[i];
	if (a->vm->live[i])
		color = 26 + a->vm->live[i];
	attron(COLOR_PAIR(color));
	return (color);
}

short	set_colors_refresh(t_corewar *a, int i)
{
	short	color;

	color = a->vm->owner[i];
	if (a->vm->update_timer[i] && (!a->v->refresh_arena
				|| --a->vm->update_timer[i]))
		attron(A_BOLD);
	if (a->vm->live_timer[i] && (!a->v->refresh_arena
				|| --a->vm->live_timer[i]))
		color = 26 + a->vm->live[i];
	if (a->vm->proc[i])
		color = 22 + a->vm->proc[i];
	if (a->v->debug && a->vm->highlight == i)
		color = F_HIGHLIGHT;
	attron(COLOR_PAIR(color));
	return (color);
}

void	define_invert_colors(void)
{
	init_pair(L_CHAMP1, COLOR_BLACK, COLOR_GREEN);
	init_pair(L_CHAMP2, COLOR_BLACK, COLOR_BLUE);
	init_pair(L_CHAMP3, COLOR_BLACK, COLOR_RED);
	init_pair(L_CHAMP4, COLOR_BLACK, COLOR_CYAN);
	init_pair(F_CHAMP1, 15, COLOR_GREEN);
	init_pair(F_CHAMP2, 15, COLOR_BLUE);
	init_pair(F_CHAMP3, 15, COLOR_RED);
	init_pair(F_CHAMP4, 15, COLOR_CYAN);
	init_pair(F_HIGHLIGHT, COLOR_BLACK, COLOR_YELLOW);
}
