/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bet.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 14:36:01 by arlaine           #+#    #+#             */
/*   Updated: 2019/11/21 16:17:31 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "pixel.h"

static void		bt_draw_frame(void)
{
	int			x;
	int			y;

	y = 20;
	x = 229;
	attron(COLOR_PAIR(BET_FRAME));
	while (x++ <= 300)
		mvprintw(y, x - 1, " ");
	while (y++ <= 50)
		mvprintw(y - 1, x - 1, " ");
	while (x-- >= 229)
		mvprintw(y - 1, x, " ");
	while (y-- >= 21)
		mvprintw(y, x + 1, " ");
	attroff(COLOR_PAIR(BET_FRAME));
	refresh();
}

static void		bt_draw(t_corewar *a)
{
	int			i;
	int			x;
	int			y;

	i = 0;
	y = 27;
	x = 240;
	bt_draw_frame();
	mvprintw(23, 232, "Please place a bet on one of the listed champions :");
	mvprintw(24, 232, "Use the arrows to change your pick and press enter %s", \
			"when ready to go.");
	while (i < a->nb_players)
	{
		if (a->players[i])
		{
			mvprintw(y, x, ".");
			attron(A_BOLD);
			init_colors_players_name(i + 1);
			mvprintw(y, x + 4, "%s", a->players[i]->header->prog_name);
			attroff(A_BOLD);
			off_colors_players_name(i + 1);
			y += 3;
		}
		i++;
	}
}

static void		bt_end(t_corewar *a)
{
	mvprintw(40, 240, "You placed a bet on ");
	init_colors_players_name(a->v->bet + 1);
	mvprintw(40, 260, "%s", a->players[a->v->bet]->header->prog_name);
	off_colors_players_name(a->v->bet + 1);
	refresh();
	getch();
}

void			bet(t_corewar *a)
{
	int	ch;
	int	bet;

	ch = 0;
	bet = 0;
	bt_draw(a);
	while (ch != '\n')
	{
		if ((ch = getch()) == KEY_DOWN || ch == KEY_UP)
		{
			mvprintw(27 + 3 * bet, 240, ".");
			if (ch == KEY_UP && bet > 0)
				bet--;
			if (ch == KEY_DOWN && bet < a->nb_players - 1)
				bet++;
			attron(COLOR_PAIR(CURSOR));
			mvprintw(27 + 3 * bet, 240, "#");
			attroff(COLOR_PAIR(CURSOR));
			refresh();
		}
	}
	a->v->bet = bet;
	bt_end(a);
}
