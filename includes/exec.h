/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:22:48 by mdelory           #+#    #+#             */
/*   Updated: 2019/11/27 19:22:14 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "vm.h"

int				ex_add(t_process *proc, t_vm *vm);
int				ex_aff(t_process *proc, t_vm *vm);
int				ex_and(t_process *proc, t_vm *vm);
int				ex_fork(t_process *proc, t_vm *vm);
int				ex_ld(t_process *proc, t_vm *vm);
int				ex_ldi(t_process *proc, t_vm *vm);
int				ex_lfork(t_process *proc, t_vm *vm);
int				ex_live(t_process *proc, t_vm *vm);
int				ex_lld(t_process *proc, t_vm *vm);
int				ex_lldi(t_process *proc, t_vm *vm);
int				ex_or(t_process *proc, t_vm *vm);
int				ex_st(t_process *proc, t_vm *vm);
int				ex_sti(t_process *proc, t_vm *vm);
int				ex_sub(t_process *proc, t_vm *vm);
int				ex_xor(t_process *proc, t_vm *vm);
int				ex_zjmp(t_process *proc, t_vm *vm);

#endif
