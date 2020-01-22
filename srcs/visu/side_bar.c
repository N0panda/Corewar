/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_bar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:11:28 by arlaine           #+#    #+#             */
/*   Updated: 2019/11/28 20:08:58 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "pixel.h"

static int		sb_draw_players_name(t_corewar *a)
{
	int			id;
	int			y;

	y = 11;
	id = 0;
	while (id < a->nb_players)
	{
		mvprintw(y, 200, "Player %d : ", -id);
		init_colors_players_name(id + 1);
		mvprintw(y, 212, "%s", a->players[id]->header->prog_name);
		off_colors_players_name(id + 1);
		y++;
		mvprintw(y++, 202, "Last live :\t\t\t%6d", a->vm->last_live[id]);
		mvprintw(y, 202, "Lives in current period :\t%6d", a->vm->nb_live[id]);
		y += 2;
		id++;
	}
	return (y);
}

static void		sb_draw_more_info(t_corewar *a, int y)
{
	y += 7;
	mvprintw(y, 216, "    ");
	mvprintw(y, 200, "CYCLE_TO_DIE : %d", a->vm->cycle_to_die);
	y += 2;
	mvprintw(y, 200, "CYCLE_DELTA : %d", CYCLE_DELTA);
	y += 2;
	mvprintw(y, 200, "NBR_LIVE : %d", NBR_LIVE);
	y += 2;
	mvprintw(y, 200, "CHECKS : %d / %d", a->vm->checks, MAX_CHECKS);
}

void			sb_draw_data(t_corewar *a)
{
	int			y;

	attron(COLOR_PAIR(INFOS));
	attron(A_BOLD);
	mvprintw(4, 200, "Cycles/second limit : %4d", a->vm->speed);
	mvprintw(7, 200, "Cycle : %ld", a->vm->cycles);
	mvprintw(9, 200, "Processes : %4d", vector_count(&a->vm->v_process));
	y = sb_draw_players_name(a);
	attroff(COLOR_PAIR(INFOS));
	attroff(A_BOLD);
	clear_debug(y);
	if (a->v->debug)
		sb_draw_debug(a, y);
	else
		sb_draw_more_info(a, y);
}

void			draw_side_bar(t_corewar *a)
{
	int			x;
	int			y;

	x = 196;
	y = 0;
	attron(COLOR_PAIR(WIN_BORDER));
	while (x <= 260)
		mvprintw(y, x++, " ");
	while (y < 67)
		mvprintw(y++, x, " ");
	while (x > 196)
		mvprintw(y, x--, " ");
	attroff(COLOR_PAIR(WIN_BORDER));
	sb_draw_data(a);
}
