/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 16:05:26 by arlaine           #+#    #+#             */
/*   Updated: 2019/11/20 15:17:39 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "pixel.h"

char *g_fs_msg[4] = {"First player is :", \
	"Second player is :", \
	"Third player is :", \
	"Fourth player is :"};

static void		fs_draw_win(void)
{
	int			x;
	int			y;

	x = 97;
	y = 20;
	attron(COLOR_PAIR(COM_C4B));
	while (x++ <= 200)
		mvprintw(y, x, " ");
	while (y++ <= 60)
		mvprintw(y, x - 1, " ");
	while (x-- >= 99)
		mvprintw(y - 1, x, " ");
	while (y-- > 20)
		mvprintw(y, x, " ");
	attroff(COLOR_PAIR(COM_C4B));
}

static void		fs_draw_players(t_corewar *a)
{
	int			i;
	int			y;

	i = -1;
	y = 24;
	attron(A_BOLD);
	while (++i < 4)
		if (a->players[i])
		{
			mvprintw(y, 100, "%s", g_fs_msg[i]);
			init_colors_players_name(i + 1);
			mvprintw(y, 101 + ft_strlen(g_fs_msg[i]), \
					"%s", a->players[i]->header->prog_name);
			off_colors_players_name(i + 1);
			mvprintw(++y, 100, "%s", a->players[i]->header->comment);
			y += 3;
			refresh();
			usleep(DELAY * 40);
		}
	attroff(A_BOLD);
}

void			first_screen(t_corewar *a)
{
	attron(COLOR_PAIR(WIN_BORDER));
	fs_draw_win();
	fs_draw_frame();
	attron(COLOR_PAIR(INFOS));
	fs_draw_players(a);
	bet(a);
	usleep(3000);
	clear();
}
