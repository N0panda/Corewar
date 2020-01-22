/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:40:27 by mdelory           #+#    #+#             */
/*   Updated: 2019/11/28 16:43:13 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void		lld_dir(t_process *proc, t_vm *vm)
{
	int		load;

	proc->next_op = 7;
	load = vm_read(vm, proc->pc + 2, 4, 0);
	proc->reg[vm_read(vm, proc->pc + 6, 1, REG)] = load;
	proc->carry = !load;
}

static void		lld_id(t_process *proc, t_vm *vm)
{
	int		load;

	proc->next_op = 5;
	load = vm_read(vm, proc->pc + vm_read(vm, proc->pc + 2, 2, 0), 4, 0);
	proc->reg[vm_read(vm, proc->pc + 4, 1, REG)] = load;
	proc->carry = !load;
}

int				ex_lld(t_process *proc, t_vm *vm)
{
	if (!(proc->ocp == 0x90 || proc->ocp == 0xd0))
		return (-1);
	if (proc->ocp == 0x90)
		lld_dir(proc, vm);
	else
		lld_id(proc, vm);
	return (1);
}
