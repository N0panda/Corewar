/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:40:42 by mdelory           #+#    #+#             */
/*   Updated: 2019/11/29 22:09:48 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int				ex_sub(t_process *proc, t_vm *vm)
{
	int		sub;

	sub = 0;
	if (!(proc->ocp == 0x54))
		return (-1);
	proc->next_op = 5;
	sub = proc->reg[vm_read(vm, proc->pc + 2, 1, REG)]
			- proc->reg[vm_read(vm, proc->pc + 3, 1, REG)];
	proc->reg[vm_read(vm, proc->pc + 4, 1, REG)] = sub;
	proc->carry = !sub;
	return (1);
}
