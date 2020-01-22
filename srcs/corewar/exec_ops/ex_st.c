/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:40:36 by mdelory           #+#    #+#             */
/*   Updated: 2019/11/29 19:58:46 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int		st_reg(t_process *proc, t_vm *vm)
{
	int		st;

	proc->next_op = 4;
	st = proc->reg[vm_read(vm, proc->pc + 2, 1, REG)];
	proc->reg[vm_read(vm, proc->pc + 3, 1, REG)] = st;
	return (1);
}

static int		st_id(t_process *proc, t_vm *vm)
{
	int		st;

	proc->next_op = 5;
	st = proc->reg[vm_read(vm, proc->pc + 2, 1, REG)];
	vm_write(vm, st, proc->pc + (vm_read(vm, proc->pc + 3, 2, 0)
				% IDX_MOD), 4);
	return (1);
}

int				ex_st(t_process *proc, t_vm *vm)
{
	if (!(proc->ocp == 0x50 || proc->ocp == 0x70))
		return (-1);
	if (proc->ocp == 0x50)
		st_reg(proc, vm);
	else
		st_id(proc, vm);
	return (1);
}
