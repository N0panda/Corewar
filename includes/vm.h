/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 20:22:12 by mdelory           #+#    #+#             */
/*   Updated: 2019/11/28 16:31:10 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# define VM_RUN		1
# define VM_PAUSE	2
# define VM_STOP	3

# define REG 1

# include "libft.h"

# include "corewar.h"

typedef struct s_corewar	t_corewar;

typedef struct		s_vm
{
	int				state;
	unsigned long	cycles;
	unsigned long	dump;
	unsigned long	cycle_to_die;
	long			nlive;
	int				checks;
	int				write_id;
	unsigned char	arena[MEM_SIZE];
	t_vector		v_process;

	long long		l_time;
	unsigned int	speed;

	int				debug_state;
	int				highlight;
	long			nb_live[4];
	long			last_live[4];
	char			owner[MEM_SIZE];
	char			proc[MEM_SIZE];
	char			live[MEM_SIZE];
	int				live_timer[MEM_SIZE];
	char			update[MEM_SIZE];
	int				update_timer[MEM_SIZE];
}					t_vm;

typedef struct		s_process
{
	int				id;
	unsigned short	pc;
	int				alive;
	long			last_live;
	int				carry;
	unsigned char	op;
	unsigned char	ocp;
	size_t			op_cycle_lft;
	int				reg[REG_NUMBER + 1];
	unsigned short	next_op;
}					t_process;

int					vm_init(t_corewar *cw);
int					vm_load(t_corewar *cw);
int					vm_run(t_corewar *cw);
int					vm_step(t_vm *vm);
int					vm_read(t_vm *vm, size_t index, size_t size, int protect);
void				vm_kill_process(t_vm *vm);
void				vm_write(t_vm *vm, uint32_t data, \
							size_t index, size_t size);

void				vm_dump(t_vm *vm);

t_process			*new_process(int player_id, size_t index);
t_process			*clone_process(t_process *p);
int					check_dump(t_vm *vm);
int					check_time(t_vm *vm);
int					check_cycle(t_vm *vm, int loop);
int					process_step(t_process *proc, t_vm *vm);
int					process_set_cycle_lft(t_process *proc);

#endif
