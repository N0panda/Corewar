/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:58:56 by arlaine           #+#    #+#             */
/*   Updated: 2019/11/21 17:24:24 by arlaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "pixel.h"

void			clear_debug(int y)
{
	y += 7;
	while (y < 66)
	{
		mvprintw(y, 199, "                                              ");
		y++;
	}
}

void			print_register_debug(t_process *proc, int y)
{
	int			i;

	i = 0;
	y += 3;
	mvprintw(y, 220, "Registers");
	y++;
	while (++i <= REG_NUMBER)
		mvprintw(++y, 202, "[%2d] = %10d (%#x)", i, proc->reg[i], proc->reg[i]);
}

int				print_data_debug(t_process *proc, int id, int y)
{
	y += 7;
	mvprintw(y, 220, "Process #%d", id + 1);
	++y;
	if (proc->op && proc->op < 17)
		mvprintw((++y), 202, "op        %15s (%#.2x)",
				g_op_tab[proc->op - 1].name, proc->op);
	else
		mvprintw((++y), 202, "op        %15d", proc->op);
	mvprintw((++y), 202, "owner_id      %15d", proc->id);
	mvprintw((++y), 202, "pc            %15d", proc->pc);
	mvprintw((++y), 202, "last_live     %15d", proc->last_live);
	mvprintw((++y), 202, "carry         %15d", proc->carry);
	mvprintw((++y), 202, "ocp           %15d", proc->ocp);
	mvprintw((++y), 202, "cycle_lft     %15d", proc->op_cycle_lft);
	mvprintw((++y), 202, "next_op       %15d", proc->next_op);
	return (y);
}

void			sb_draw_debug(t_corewar *a, int y)
{
	t_process	*p;

	if (a->v->debug_index < 0)
		a->v->debug_index = 0;
	if (a->v->debug_index >= vector_count(&a->vm->v_process))
		a->v->debug_index = vector_count(&a->vm->v_process) - 1;
	p = vector_at(&a->vm->v_process, a->v->debug_index);
	if (p == NULL)
		return ;
	a->vm->highlight = p->pc % MEM_SIZE;
	attron(COLOR_PAIR(INFOS));
	y = print_data_debug(p, a->v->debug_index, y);
	print_register_debug(p, y);
	attroff(COLOR_PAIR(INFOS));
}
