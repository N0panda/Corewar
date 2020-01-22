/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:31:36 by arlaine           #+#    #+#             */
/*   Updated: 2019/11/21 16:08:54 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "pixel.h"

void	init_colors_players_name(int i_color)
{
	if (i_color == 1)
		attron(COLOR_PAIR(CHAMP1));
	else if (i_color == 2)
		attron(COLOR_PAIR(CHAMP2));
	else if (i_color == 3)
		attron(COLOR_PAIR(CHAMP3));
	else if (i_color == 4)
		attron(COLOR_PAIR(CHAMP4));
}

void	off_colors_players_name(int i_color)
{
	int		i;

	i = 0;
	if (i_color == 1)
		attroff(COLOR_PAIR(CHAMP1));
	else if (i_color == 2)
		attroff(COLOR_PAIR(CHAMP2));
	else if (i_color == 3)
		attroff(COLOR_PAIR(CHAMP3));
	else if (i_color == 4)
		attroff(COLOR_PAIR(CHAMP4));
	else
	{
		while (i++ <= 30)
			attroff(COLOR_PAIR(i));
	}
}

void	define_pairs(void)
{
	init_pair(WIN_BORDER, 244, 244);
	init_pair(CHAMP1, COLOR_GREEN, COLOR_BLACK);
	init_pair(CHAMP2, COLOR_BLUE, COLOR_BLACK);
	init_pair(CHAMP3, COLOR_RED, COLOR_BLACK);
	init_pair(CHAMP4, COLOR_CYAN, COLOR_BLACK);
	init_pair(DEFAULT, 8, COLOR_BLACK);
	init_pair(COM_C1, 213, COLOR_BLACK);
	init_pair(COM_C2, 177, COLOR_BLACK);
	init_pair(COM_C3, 141, COLOR_BLACK);
	init_pair(COM_C4, 105, COLOR_BLACK);
	init_pair(COM_C4B, 105, 105);
	init_pair(COM_C5, 69, COLOR_BLACK);
	init_pair(COM_C6, 33, COLOR_BLACK);
	init_pair(INFOS, COLOR_WHITE, COLOR_BLACK);
	init_pair(GREY, 241, COLOR_BLACK);
	init_pair(BET_FRAME, 105, 105);
	init_pair(CURSOR, 219, COLOR_BLACK);
	init_pair(FL1, 0, 0);
	init_pair(FL2, 1, 0);
	init_pair(FL3, 3, 0);
	init_pair(FL4, 4, 0);
	init_pair(BALL, 118, COLOR_BLACK);
	init_pair(NONE, COLOR_BLACK, COLOR_BLACK);
}
