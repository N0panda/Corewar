/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:40:24 by mdelory           #+#    #+#             */
/*   Updated: 2019/11/28 17:16:32 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int				ex_live(t_process *proc, t_vm *vm)
{
	int32_t		id;

	proc->next_op = 5;
	id = -vm_read(vm, proc->pc + 1, 4, 0);
	proc->last_live = vm->cycles;
	if (id > 0 && id < 5)
	{
		proc->alive = 1;
		vm->last_live[id - 1] = vm->cycles;
		vm->live[proc->pc % MEM_SIZE] = id;
		vm->live_timer[proc->pc % MEM_SIZE] = 40;
		vm->nlive++;
		vm->nb_live[id - 1]++;
	}
	return (1);
}
