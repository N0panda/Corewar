/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:11:50 by arlaine           #+#    #+#             */
/*   Updated: 2019/11/15 14:53:15 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "pixel.h"

void		print_status_vm(t_corewar *a)
{
	attron(COLOR_PAIR(INFOS) | A_BOLD);
	if (a->vm->state == VM_PAUSE)
		mvprintw(2, 200, "**PAUSED**");
	if (a->vm->state == VM_RUN)
		mvprintw(2, 200, "**RUNNING**");
	refresh();
	attroff(COLOR_PAIR(INFOS) | A_BOLD);
}

void		key_handle(t_corewar *a)
{
	a->v->ch = getch();
	if (a->v->ch == ' ')
	{
		a->vm->state = (a->vm->state == VM_PAUSE ? VM_RUN : VM_PAUSE);
		print_status_vm(a);
	}
	if (a->v->ch == 27)
	{
		a->vm->state = VM_STOP;
		a->v->vm_stop = 1;
	}
	a->v->ch == 'q' ? (a->vm->speed = ft_max(a->vm->speed - 10, 1)) : 0;
	if (a->v->ch == 'w')
		a->vm->speed = ft_max(a->vm->speed - 1, 1);
	else if (a->v->ch == 'd')
		a->v->debug = !a->v->debug;
	else if (a->v->ch == 'e')
		a->vm->speed = ft_min(a->vm->speed + 1, 2000);
	else if (a->v->ch == 'r')
		a->vm->speed = ft_min(a->vm->speed + 10, 2000);
	else if (a->v->ch == KEY_LEFT && a->v->debug)
		a->v->debug_index--;
	else if (a->v->ch == KEY_RIGHT && a->v->debug)
		a->v->debug_index++;
}
