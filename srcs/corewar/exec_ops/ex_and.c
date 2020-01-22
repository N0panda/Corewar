/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:34:24 by mdelory           #+#    #+#             */
/*   Updated: 2019/11/28 17:16:11 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void		and_id(t_process *proc, t_vm *vm)
{
	int		ret;

	ret = 0;
	if (proc->ocp == 0xd4 && (proc->next_op = 6))
	{
		ret = vm_read(vm, proc->pc + (vm_read(vm, proc->pc + 2, 2, 0)
		% IDX_MOD), 4, 0) & proc->reg[vm_read(vm, proc->pc + 4, 1, REG)];
		proc->reg[vm_read(vm, proc->pc + 5, 1, REG)] = ret;
	}
	if (proc->ocp == 0xe4 && (proc->next_op = 9))
	{
		ret = vm_read(vm, proc->pc + (vm_read(vm, proc->pc + 2, 2, 0)
		% IDX_MOD), 4, 0) & vm_read(vm, proc->pc + 4, 4, 0);
		proc->reg[vm_read(vm, proc->pc + 8, 1, REG)] = ret;
	}
	if (proc->ocp == 0xf4 && (proc->next_op = 7))
	{
		ret = vm_read(vm, proc->pc + (vm_read(vm, proc->pc + 2, 2, 0)
			% IDX_MOD), 4, 0) & vm_read(vm, proc->pc
			+ (vm_read(vm, proc->pc + 4, 2, 0) % IDX_MOD), 4, 0);
		proc->reg[vm_read(vm, proc->pc + 6, 1, REG)] = ret;
	}
	proc->carry = !ret;
}

static void		and_dir(t_process *proc, t_vm *vm)
{
	int		ret;

	ret = 0;
	if (proc->ocp == 0x94 && (proc->next_op = 8))
	{
		ret = vm_read(vm, proc->pc + 2, 4, 0)
		& proc->reg[vm_read(vm, proc->pc + 6, 1, REG)];
		proc->reg[vm_read(vm, proc->pc + 7, 1, REG)] = ret;
	}
	if (proc->ocp == 0xa4 && (proc->next_op = 11))
	{
		ret = vm_read(vm, proc->pc + 2, 4, 0) & vm_read(vm, proc->pc + 6, 4, 0);
		proc->reg[vm_read(vm, proc->pc + 10, 1, REG)] = ret;
	}
	if (proc->ocp == 0xb4 && (proc->next_op = 9))
	{
		ret = vm_read(vm, proc->pc + 2, 4, 0) & vm_read(vm, proc->pc
		+ (vm_read(vm, proc->pc + 6, 2, 0) % IDX_MOD), 4, 0);
		proc->reg[vm_read(vm, proc->pc + 8, 1, REG)] = ret;
	}
	proc->carry = !ret;
}

static void		and_reg(t_process *proc, t_vm *vm)
{
	int		ret;

	ret = 0;
	if (proc->ocp == 0x64 && (proc->next_op = 8))
	{
		ret = proc->reg[vm_read(vm, proc->pc + 2, 1, REG)]
			& vm_read(vm, proc->pc + 3, 4, 0);
		proc->reg[vm_read(vm, proc->pc + 7, 1, REG)] = ret;
	}
	if (proc->ocp == 0x74 && (proc->next_op = 6))
	{
		ret = proc->reg[vm_read(vm, proc->pc + 2, 1, REG)]
			& vm_read(vm, proc->pc + (vm_read(vm, proc->pc + 3, 2, 0)
						% IDX_MOD), 4, 0);
		proc->reg[vm_read(vm, proc->pc + 5, 1, REG)] = ret;
	}
	proc->carry = !ret;
}

int				ex_and(t_process *proc, t_vm *vm)
{
	int		ret;

	ret = 0;
	if (!(proc->ocp == 0x54 || proc->ocp == 0x64 || proc->ocp == 0x74 || \
			proc->ocp == 0x94 || proc->ocp == 0xa4 || proc->ocp == 0xb4 || \
			proc->ocp == 0xd4 || proc->ocp == 0xe4 || proc->ocp == 0xf4))
		return (-1);
	if (proc->ocp == 0x54 && (proc->next_op = 5))
	{
		ret = proc->reg[vm_read(vm, proc->pc + 2, 1, REG)]
				& proc->reg[vm_read(vm, proc->pc + 3, 1, REG)];
		proc->reg[vm_read(vm, proc->pc + 4, 1, REG)] = ret;
		proc->carry = !ret;
	}
	else if (proc->ocp == 0x64 || proc->ocp == 0x74)
		and_reg(proc, vm);
	else if (proc->ocp == 0x94 || proc->ocp == 0xa4 || proc->ocp == 0xb4)
		and_dir(proc, vm);
	else if (proc->ocp == 0xd4 || proc->ocp == 0xe4 || proc->ocp == 0xf4)
		and_id(proc, vm);
	return (1);
}
