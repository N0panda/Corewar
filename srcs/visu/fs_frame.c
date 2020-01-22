/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_frame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 20:50:54 by arlaine           #+#    #+#             */
/*   Updated: 2019/11/18 12:37:55 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "pixel.h"

static void		draw_corners(void)
{
	int	x;
	int	y;

	y = 20;
	x = 96;
	attron(COLOR_PAIR(BET_FRAME));
	while (y++ < 58)
	{
		mvprintw(y, x, "/");
		mvprintw(++y, x - 1, "/");
		mvprintw(++y, x - 1, "\\");
		mvprintw(++y, x, "\\");
	}
	x = 202;
	y = 20;
	while (y++ < 58)
	{
		mvprintw(y, x, "\\");
		mvprintw(++y, x + 1, "\\");
		mvprintw(++y, x + 1, "/");
		mvprintw(++y, x, "/");
	}
	attroff(COLOR_PAIR(BET_FRAME));
}

void			fs_draw_frame(void)
{
	int	x;
	int	y;

	y = 17;
	x = 122;
	attron(COLOR_PAIR(COM_C1));
	mvprintw(y, x, "%s", C1);
	mvprintw(58, x + 8, "%s", F1);
	attron(COLOR_PAIR(COM_C2));
	mvprintw(y + 1, x, "%s", C2);
	mvprintw(59, x + 8, "%s", F2);
	attron(COLOR_PAIR(COM_C3));
	mvprintw(y + 2, x, "%s%s", C31, C32);
	mvprintw(60, x + 8, "%s", F3);
	attron(COLOR_PAIR(COM_C4));
	mvprintw(y + 3, x, "%s", C4);
	mvprintw(61, x + 8, "%s", F4);
	attron(COLOR_PAIR(COM_C5));
	mvprintw(y + 4, x, "%s", C5);
	mvprintw(62, x + 8, "%s", F5);
	attron(COLOR_PAIR(COM_C6));
	mvprintw(y + 5, x, "%s", C6);
	mvprintw(63, x + 8, "%s", F6);
	attroff(COLOR_PAIR(COM_C6));
	draw_corners();
}
