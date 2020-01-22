/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:57:00 by arlaine           #+#    #+#             */
/*   Updated: 2019/11/15 17:09:24 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "pixel.h"

void	init_visu(t_corewar *a)
{
	initscr();
	noecho();
	curs_set(FALSE);
	start_color();
	noecho();
	cbreak();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	getmaxyx(stdscr, a->v->max_y, a->v->max_x);
	a->v->debug = 0;
	a->v->debug_index = 0;
	a->v->vm_stop = 0;
	a->v->ch = 0;
	define_pairs();
	define_invert_colors();
}

void	init_arena(t_corewar *a)
{
	define_pairs();
	trace_win(a);
	refresh_arena(a, 1);
}
