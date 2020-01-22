/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_rw.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 18:49:07 by mdelory           #+#    #+#             */
/*   Updated: 2019/11/28 16:27:07 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		set_update(t_vm *vm, size_t index)
{
	vm->update[index] = 1;
	vm->update_timer[index] = 20;
	vm->owner[index] = vm->write_id;
}

int				vm_read(t_vm *vm, size_t index, size_t size, int protect)
{
	int			val;

	val = 0;
	if (size == 1)
	{
		val = vm->arena[index % MEM_SIZE];
		if (protect == REG && (val < 1 || val > REG_NUMBER))
			val = 0;
		return ((signed char)val);
	}
	else if (size == 2)
	{
		val = (vm->arena[index % MEM_SIZE] << 8) \
			| vm->arena[(index + 1) % MEM_SIZE];
		return ((signed short)val);
	}
	else if (size == 4)
	{
		val = ((vm->arena[index % MEM_SIZE] << 24) \
			| (vm->arena[(index + 1) % MEM_SIZE] << 16) \
			| (vm->arena[(index + 2) % MEM_SIZE] << 8) \
			| (vm->arena[(index + 3) % MEM_SIZE]));
		return ((signed int)val);
	}
	return (0);
}

void			vm_write(t_vm *vm, uint32_t data, size_t index, size_t size)
{
	if (size == 1)
	{
		vm->arena[index % MEM_SIZE] = (unsigned char)data;
		set_update(vm, index % MEM_SIZE);
	}
	else if (size == 2)
	{
		vm->arena[index % MEM_SIZE] = (data & 0x0000FF00) >> 8;
		set_update(vm, index % MEM_SIZE);
		vm->arena[(index + 1) % MEM_SIZE] = data & 0x000000FF;
		set_update(vm, (index + 1) % MEM_SIZE);
	}
	else if (size == 4)
	{
		vm->arena[index % MEM_SIZE] = (data & 0xFF000000) >> 24;
		set_update(vm, index % MEM_SIZE);
		vm->arena[(index + 1) % MEM_SIZE] = (data & 0x00FF0000) >> 16;
		set_update(vm, (index + 1) % MEM_SIZE);
		vm->arena[(index + 2) % MEM_SIZE] = (data & 0x0000FF00) >> 8;
		set_update(vm, (index + 2) % MEM_SIZE);
		vm->arena[(index + 3) % MEM_SIZE] = (data & 0x000000FF);
		set_update(vm, (index + 3) % MEM_SIZE);
	}
}
