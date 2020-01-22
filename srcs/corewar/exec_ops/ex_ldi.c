/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:40:18 by mdelory           #+#    #+#             */
/*   Updated: 2019/11/29 21:44:46 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void		ldi_dir(t_process *proc, t_vm *vm)
{
	int		ld;

	ld = 0;
	if (proc->ocp == 0x94 && (proc->next_op = 6))
	{
		ld = vm_read(vm, proc->pc + 2, 2, 0)
			+ proc->reg[vm_read(vm, proc->pc + 4, 1, REG)];
		proc->reg[vm_read(vm, proc->pc + 5,
					1, REG)] = vm_read(vm, proc->pc + (ld % IDX_MOD), 4, 0);
	}
	if (proc->ocp == 0xa4 && (proc->next_op = 7))
	{
		ld = vm_read(vm, proc->pc + 2, 2, 0)
			+ vm_read(vm, proc->pc + 4, 2, 0);
		proc->reg[vm_read(vm, proc->pc + 6,
					1, REG)] = vm_read(vm, proc->pc + (ld % IDX_MOD), 4, 0);
	}
}

static void		ldi_id(t_process *proc, t_vm *vm)
{
	int		ld;

	ld = 0;
	if (proc->ocp == 0xd4 && (proc->next_op = 6))
	{
		ld = vm_read(vm, proc->pc + vm_read(vm, proc->pc + 2, 2, 0), 4, 0)
			+ proc->reg[vm_read(vm, proc->pc + 4, 1, REG)];
		proc->reg[vm_read(vm, proc->pc + 5,
					1, REG)] = vm_read(vm, proc->pc + (ld % IDX_MOD), 4, 0);
	}
	if (proc->ocp == 0xe4 && (proc->next_op = 7))
	{
		ld = vm_read(vm, proc->pc + vm_read(vm, proc->pc + 2, 2, 0), 4, 0)
			+ vm_read(vm, proc->pc + 4, 2, 0);
		proc->reg[vm_read(vm, proc->pc + 6,
					1, REG)] = vm_read(vm, proc->pc + (ld % IDX_MOD), 4, 0);
	}
}

static void		ldi_reg(t_process *proc, t_vm *vm)
{
	int		ld;

	ld = 0;
	if (proc->ocp == 0x54 && (proc->next_op = 5))
	{
		ld = proc->reg[vm_read(vm, proc->pc + 2, 1, REG)]
			+ proc->reg[vm_read(vm, proc->pc + 3, 1, REG)];
		proc->reg[vm_read(vm, proc->pc + 4,
					1, REG)] = vm_read(vm, proc->pc + (ld % IDX_MOD), 4, 0);
	}
	if (proc->ocp == 0x64 && (proc->next_op = 6))
	{
		ld = proc->reg[vm_read(vm, proc->pc + 2, 1, REG)]
			+ vm_read(vm, proc->pc + 3, 2, REG);
		proc->reg[vm_read(vm, proc->pc + 5,
					1, REG)] = vm_read(vm, proc->pc + (ld % IDX_MOD), 4, 0);
	}
}

int				ex_ldi(t_process *proc, t_vm *vm)
{
	if (!(proc->ocp == 0x54 || proc->ocp == 0x64 || proc->ocp == 0x94 || \
			proc->ocp == 0xa4 || proc->ocp == 0xd4 || proc->ocp == 0xe4))
		return (-1);
	if (proc->ocp == 0x54 || proc->ocp == 0x64)
		ldi_reg(proc, vm);
	else if (proc->ocp == 0x94 || proc->ocp == 0xa4)
		ldi_dir(proc, vm);
	else if (proc->ocp == 0xd4 || proc->ocp == 0xe4)
		ldi_id(proc, vm);
	return (1);
}
