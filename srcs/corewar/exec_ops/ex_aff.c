/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:34:24 by mdelory           #+#    #+#             */
/*   Updated: 2019/11/29 21:42:50 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int				ex_aff(t_process *proc, t_vm *vm)
{
	proc->next_op = 3;
	if (vm_read(vm, proc->pc + 1, 1, 0) == 0x40)
	{
		ft_printf("%c", proc->reg[vm_read(vm, proc->pc + 2, 1, REG)] % 256);
		return (1);
	}
	return (-1);
}
