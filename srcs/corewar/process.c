/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:16:02 by mdelory           #+#    #+#             */
/*   Updated: 2019/11/29 23:13:41 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				process_set_cycle_lft(t_process *proc)
{
	if (proc->op < 1 || proc->op > 16)
		proc->op_cycle_lft = 1;
	else
		proc->op_cycle_lft = g_op_tab[proc->op - 1].cycle;
	return (1);
}

int				process_exec(t_process *proc, t_vm *vm)
{
	int				(*opf)(t_process *, t_vm *);

	proc->next_op = 1;
	if (proc->op < 1 || proc->op > 16)
		return (0);
	if (g_op_tab[proc->op - 1].ocp)
		proc->ocp = vm_read(vm, proc->pc + 1, 1, 0);
	else
		proc->ocp = 0;
	opf = g_op_func[proc->op - 1];
	return ((*opf)(proc, vm));
}

int				process_step(t_process *proc, t_vm *vm)
{
	int			ret;

	ret = 1;
	if (!(--proc->op_cycle_lft))
	{
		proc->op = vm_read(vm, proc->pc, 1, 0);
		ret = process_exec(proc, vm);
		proc->pc += proc->next_op;
		proc->op = vm_read(vm, proc->pc, 1, 0);
		process_set_cycle_lft(proc);
	}
	return (ret);
}

t_process		*new_process(int player_id, size_t pc)
{
	t_process	*p;
	int			i;

	i = -1;
	if ((p = ft_memalloc(sizeof(t_process))))
	{
		p->id = player_id;
		p->pc = pc % MEM_SIZE;
		while (++i <= (REG_NUMBER + 1))
			p->reg[i] = 0;
		p->reg[1] = -player_id;
	}
	return (p);
}

t_process		*clone_process(t_process *p)
{
	t_process	*child;

	if ((child = ft_memalloc(sizeof(t_process))))
	{
		child->id = p->id;
		child->pc = p->pc;
		child->alive = p->alive;
		child->last_live = p->last_live;
		child->carry = p->carry;
		ft_memcpy(child->reg, p->reg, sizeof(p->reg));
	}
	return (child);
}
