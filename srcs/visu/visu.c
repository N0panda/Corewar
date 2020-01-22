/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:11:38 by arlaine           #+#    #+#             */
/*   Updated: 2019/11/15 17:04:05 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "pixel.h"

void	trace_win(t_corewar *a)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	attron(COLOR_PAIR(WIN_BORDER));
	while (x <= 196)
		mvprintw(y, x++, " ");
	while (y <= 67)
		mvprintw(y++, x, " ");
	x = 0;
	y = 0;
	while (y < 67)
		mvprintw(y++, x, " ");
	while (x <= 196)
		mvprintw(y, x++, " ");
	attroff(COLOR_PAIR(WIN_BORDER));
	print_base_adress(a, 0);
	draw_side_bar(a);
	refresh();
}

void	refresh_arena(t_corewar *a, int appel)
{
	if (appel == 0)
		print_base_adress(a, 0);
	else if (appel == 1)
		print_adress_refresh(a);
	attroff(COLOR_PAIR(WIN_BORDER));
	sb_draw_data(a);
	a->v->refresh_arena = 0;
	refresh();
}

void	print_base_adress(t_corewar *a, int tmp)
{
	short	color;
	int		i;
	int		x;
	int		y;

	i = 0;
	y = 2;
	while (y <= 65)
	{
		tmp = 0;
		x = 3;
		while (tmp <= 192)
		{
			if ((color = set_colors(a, i)))
			{
				mvprintw(y, x, "%2.2x", a->vm->arena[i]);
				attroff(COLOR_PAIR(color));
			}
			x += 3;
			tmp = x;
			i++;
		}
		y++;
	}
	refresh();
}

void	print_adress_refresh(t_corewar *a)
{
	short	color;
	int		tmp;
	int		i;
	int		x;
	int		y;

	i = 0;
	y = 2;
	while (y <= 65)
	{
		tmp = 0;
		x = 3;
		while (tmp <= 192)
		{
			if ((color = set_colors_refresh(a, i)))
			{
				mvprintw(y, x, "%2.2x", a->vm->arena[i]);
				attroff(COLOR_PAIR(color) | A_BOLD);
			}
			x += 3;
			tmp = x;
			i++;
		}
		y++;
	}
}
