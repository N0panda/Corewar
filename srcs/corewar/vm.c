/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 20:21:34 by mdelory           #+#    #+#             */
/*   Updated: 2019/11/20 17:04:52 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "vm.h"
#include "pixel.h"

int		check_cycles(t_vm *vm, unsigned long loop)
{
	int				rm;

	rm = -1;
	if (loop == vm->cycle_to_die)
	{
		while (++rm < 4)
			vm->nb_live[rm] = 0;
		vm->checks++;
		vm_kill_process(vm);
		if (vm->nlive > NBR_LIVE || vm->checks > MAX_CHECKS)
		{
			if (((long)(vm->cycle_to_die -= CYCLE_DELTA)) < 0)
				vm->cycle_to_die = 0;
			vm->checks = 0;
		}
		return (0);
	}
	return (loop + 1);
}

int		check_dump(t_vm *vm)
{
	return (vm->dump && vm->cycles == vm->dump);
}

int		check_time(t_vm *vm)
{
	long long		c_time;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	c_time = (((long long)tv.tv_sec) * 1000) + (tv.tv_usec / 1000);
	if (vm->l_time == 0 || c_time - vm->l_time > 1000 / vm->speed)
	{
		vm->l_time = c_time;
		return (1);
	}
	return (0);
}

int		vm_run(t_corewar *cw)
{
	int				ret;
	unsigned long	loop;

	loop = 0;
	ret = 0;
	cw->vm->state = (cw->vm->dump ? VM_RUN : VM_PAUSE);
	print_status_vm(cw);
	while (cw->vm->state != VM_STOP && !(ret = check_dump(cw->vm)))
	{
		key_handle(cw);
		if (cw->vm->state == VM_RUN && check_time(cw->vm))
		{
			ft_bzero(cw->vm->proc, MEM_SIZE);
			cw->vm->cycles++;
			if (!vm_step(cw->vm))
				cw->vm->state = VM_STOP;
			else
				loop = check_cycles(cw->vm, loop);
			cw->v->refresh_arena = 1;
		}
		refresh_arena(cw, 1);
	}
	return (ret);
}
