/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:39:20 by mdelory           #+#    #+#             */
/*   Updated: 2019/11/28 16:38:16 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void		ld_dir(t_process *proc, t_vm *vm)
{
	int		load;

	proc->next_op = 7;
	load = vm_read(vm, proc->pc + 2, 4, 0);
	proc->reg[vm_read(vm, proc->pc + 6, 1, REG)] = load;
	proc->carry = !load;
}

static void		ld_id(t_process *proc, t_vm *vm)
{
	int		load;

	proc->next_op = 5;
	load = vm_read(vm,
			proc->pc + (vm_read(vm, proc->pc + 2, 2, 0) % IDX_MOD), 4, 0);
	proc->reg[vm_read(vm, proc->pc + 4, 1, REG)] = load;
	proc->carry = !load;
}

int				ex_ld(t_process *proc, t_vm *vm)
{
	if (!(proc->ocp == 0x90 || proc->ocp == 0xd0))
		return (-1);
	if (proc->ocp == 0x90)
		ld_dir(proc, vm);
	else
		ld_id(proc, vm);
	return (1);
}
