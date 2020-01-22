/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:40:21 by mdelory           #+#    #+#             */
/*   Updated: 2019/11/28 16:42:05 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int				ex_lfork(t_process *proc, t_vm *vm)
{
	t_process	*child;

	proc->next_op = 3;
	if (!(child = clone_process(proc)))
		exit_error(NULL);
	child->pc += vm_read(vm, proc->pc + 1, 2, 0);
	child->op = vm_read(vm, child->pc, 1, 0);
	process_set_cycle_lft(child);
	vector_add(&vm->v_process, child);
	return (1);
}
