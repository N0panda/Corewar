/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:35:27 by mdelory           #+#    #+#             */
/*   Updated: 2019/11/28 20:35:31 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int				ex_add(t_process *proc, t_vm *vm)
{
	int		add;

	add = 0;
	if (!(proc->ocp == 0x54))
		return (-1);
	add = proc->reg[vm_read(vm, proc->pc + 2, 1, REG)]
				+ proc->reg[vm_read(vm, proc->pc + 3, 1, REG)];
	proc->next_op = 5;
	proc->reg[vm_read(vm, proc->pc + 4, 1, REG)] = add;
	proc->carry = !add;
	return (1);
}
