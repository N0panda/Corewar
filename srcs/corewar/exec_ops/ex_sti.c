/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:40:39 by mdelory           #+#    #+#             */
/*   Updated: 2019/11/29 20:01:55 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void		sti_reg(t_process *proc, t_vm *vm)
{
	int		st;

	if (proc->ocp == 0x54 && (proc->next_op = 5))
	{
		st = proc->reg[vm_read(vm, proc->pc + 3, 1, REG)]
			+ proc->reg[vm_read(vm, proc->pc + 4, 1, REG)];
		vm_write(vm, proc->reg[vm_read(vm, proc->pc + 2, 1, REG)], proc->pc
			+ (st % IDX_MOD), 4);
	}
	if (proc->ocp == 0x58 && (proc->next_op = 6))
	{
		st = proc->reg[vm_read(vm, proc->pc + 3, 1, REG)]
			+ vm_read(vm, proc->pc + 4, 2, 0);
		vm_write(vm, proc->reg[vm_read(vm, proc->pc + 2, 1, REG)], proc->pc
			+ (st % IDX_MOD), 4);
	}
}

static void		sti_dir(t_process *proc, t_vm *vm)
{
	int		st;

	if (proc->ocp == 0x64 && (proc->next_op = 6))
	{
		st = vm_read(vm, proc->pc + 3, 2, 0)
			+ proc->reg[vm_read(vm, proc->pc + 5, 1, REG)];
		vm_write(vm, proc->reg[vm_read(vm, proc->pc + 2, 1, REG)], proc->pc
			+ (st % IDX_MOD), 4);
	}
	if (proc->ocp == 0x68 && (proc->next_op = 7))
	{
		st = vm_read(vm, proc->pc + 3, 2, 0) + vm_read(vm, proc->pc + 5, 2, 0);
		vm_write(vm, proc->reg[vm_read(vm, proc->pc + 2, 1, REG)], proc->pc
			+ (st % IDX_MOD), 4);
	}
}

static void		sti_id(t_process *proc, t_vm *vm)
{
	int		st;

	if (proc->ocp == 0x74 && (proc->next_op = 6))
	{
		st = vm_read(vm, proc->pc + vm_read(vm, proc->pc + 3, 2, 0), 2, 0)
			+ proc->reg[vm_read(vm, proc->pc + 5, 1, REG)];
		vm_write(vm, proc->reg[vm_read(vm, proc->pc + 2, 1, REG)], proc->pc
			+ (st % IDX_MOD), 4);
	}
	if (proc->ocp == 0x78 && (proc->next_op = 7))
	{
		st = vm_read(vm, proc->pc + vm_read(vm, proc->pc + 3, 2, 0), 2, 0)
			+ vm_read(vm, proc->pc + 5, 2, 0);
		vm_write(vm, proc->reg[vm_read(vm, proc->pc + 2, 1, REG)],
			proc->pc + (st % IDX_MOD), 4);
	}
}

int				ex_sti(t_process *proc, t_vm *vm)
{
	if (!(proc->ocp == 0x54 || proc->ocp == 0x58 || proc->ocp == 0x64 || \
			proc->ocp == 0x68 || proc->ocp == 0x74 || proc->ocp == 0x78))
		return (-1);
	if (proc->ocp == 0x54 || proc->ocp == 0x58)
		sti_reg(proc, vm);
	if (proc->ocp == 0x64 || proc->ocp == 0x68)
		sti_dir(proc, vm);
	if (proc->ocp == 0x74 || proc->ocp == 0x78)
		sti_id(proc, vm);
	return (1);
}
