/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:40:30 by mdelory           #+#    #+#             */
/*   Updated: 2019/11/28 16:47:04 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void		lldi_dir(t_process *proc, t_vm *vm)
{
	int		ld;

	ld = 0;
	if (proc->ocp == 0x94 && (proc->next_op = 6))
	{
		ld = vm_read(vm, proc->pc + 2, 2, 0)
			+ proc->reg[vm_read(vm, proc->pc + 4, 1, REG)];
		proc->reg[vm_read(vm, proc->pc + 5,
					1, REG)] = vm_read(vm, proc->pc + ld, 4, 0);
	}
	else if (proc->ocp == 0xa4 && (proc->next_op = 7))
	{
		ld = vm_read(vm, proc->pc + 2, 2, 0) + vm_read(vm, proc->pc + 4, 2, 0);
		proc->reg[vm_read(vm, proc->pc + 6,
					1, REG)] = vm_read(vm, proc->pc + ld, 4, 0);
	}
	proc->carry = !ld;
}

static void		lldi_id(t_process *proc, t_vm *vm)
{
	int		ld;

	ld = 0;
	if (proc->ocp == 0xd4 && (proc->next_op = 6))
	{
		ld = vm_read(vm, proc->pc + vm_read(vm, proc->pc + 2, 2, 0), 4, 0)
			+ proc->reg[vm_read(vm, proc->pc + 4, 1, REG)];
		proc->reg[vm_read(vm, proc->pc + 5,
					1, REG)] = vm_read(vm, proc->pc + ld, 4, 0);
	}
	else if (proc->ocp == 0xe4 && (proc->next_op = 7))
	{
		ld = vm_read(vm, proc->pc + vm_read(vm, proc->pc + 2, 2, 0), 4, 0)
			+ vm_read(vm, proc->pc + 4, 2, 0);
		proc->reg[vm_read(vm, proc->pc + 6,
					1, REG)] = vm_read(vm, proc->pc + ld, 4, 0);
	}
	proc->carry = !ld;
}

static void		lldi_reg(t_process *proc, t_vm *vm)
{
	int		ld;

	ld = 0;
	if (proc->ocp == 0x54 && (proc->next_op = 5))
	{
		ld = proc->reg[vm_read(vm, proc->pc + 2, 1, REG)]
			+ proc->reg[vm_read(vm, proc->pc + 3, 1, REG)];
		proc->reg[vm_read(vm, proc->pc + 4,
					1, REG)] = vm_read(vm, proc->pc + ld, 4, 0);
	}
	else if (proc->ocp == 0x64 && (proc->next_op = 6))
	{
		ld = proc->reg[vm_read(vm, proc->pc + 2, 1, REG)]
			+ vm_read(vm, proc->pc + 3, 2, 0);
		proc->reg[vm_read(vm, proc->pc + 5,
					1, REG)] = vm_read(vm, proc->pc + ld, 4, 0);
	}
	proc->carry = !ld;
}

int				ex_lldi(t_process *proc, t_vm *vm)
{
	if (!(proc->ocp == 0x54 || proc->ocp == 0x64 || proc->ocp == 0x94 || \
			proc->ocp == 0xa4 || proc->ocp == 0xd4 || proc->ocp == 0xe4))
		return (-1);
	if (proc->ocp == 0x54 || proc->ocp == 0x64)
		lldi_reg(proc, vm);
	else if (proc->ocp == 0x94 || proc->ocp == 0xa4)
		lldi_dir(proc, vm);
	else if (proc->ocp == 0xd4 || proc->ocp == 0xe4)
		(lldi_id(proc, vm));
	return (1);
}
