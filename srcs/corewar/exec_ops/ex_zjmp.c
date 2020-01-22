/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:40:48 by mdelory           #+#    #+#             */
/*   Updated: 2019/11/28 17:14:10 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int				ex_zjmp(t_process *proc, t_vm *vm)
{
	proc->next_op = 3;
	if (proc->carry)
		proc->next_op = vm_read(vm, proc->pc + 1, 2, 0);
	return (1);
}
