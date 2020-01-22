/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:24:03 by mdelory           #+#    #+#             */
/*   Updated: 2019/11/28 17:17:41 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "corewar.h"
#include "pixel.h"

int		vm_init(t_corewar *cw)
{
	if (!(cw->vm = ft_memalloc(sizeof(t_vm))))
		return (0);
	ft_memset(cw->vm->update, 1, MEM_SIZE);
	ft_memset(cw->vm->owner, 5, MEM_SIZE);
	ft_memset(cw->vm->live, 0, MEM_SIZE);
	cw->vm->cycle_to_die = CYCLE_TO_DIE;
	cw->vm->speed = 50;
	return (vector_init(&cw->vm->v_process));
}

int		vm_load(t_corewar *cw)
{
	t_player	*p;
	t_process	*proc;
	int			pad;
	int			i;
	int			j;

	i = 1;
	j = -1;
	pad = (MEM_SIZE / cw->nb_players);
	while (++j < 4)
	{
		if ((p = cw->players[j]))
		{
			if (!(proc = new_process(i, (i - 1) * pad)))
				return (0);
			vector_add(&cw->vm->v_process, proc);
			ft_memcpy(cw->vm->arena + proc->pc, p->data, p->header->prog_size);
			p->id = j + 1;
			ft_memset(cw->vm->owner + proc->pc, p->id, p->header->prog_size);
			proc->op = vm_read(cw->vm, proc->pc, 1, 0);
			process_set_cycle_lft(proc);
			i++;
		}
	}
	return (1);
}

int		vm_step(t_vm *vm)
{
	t_process	*proc;
	int			n_proc;

	if ((n_proc = vector_count(&vm->v_process)) == 0)
		return (0);
	while (--n_proc >= 0)
	{
		proc = vector_at(&vm->v_process, n_proc);
		vm->write_id = proc->id;
		process_step(proc, vm);
		vm->proc[proc->pc % MEM_SIZE] = proc->id;
	}
	return (1);
}

void	vm_kill_process(t_vm *vm)
{
	int			max;
	int			i;
	t_process	*player;

	i = 0;
	max = vector_count(&vm->v_process);
	while (i < max)
	{
		if ((player = vector_at(&vm->v_process, i)) && (player->alive
			|| (vm->cycles - player->last_live) <= vm->cycle_to_die))
		{
			player->alive = 0;
			i++;
		}
		else
		{
			vector_delete(&vm->v_process, i);
			max--;
		}
	}
}
