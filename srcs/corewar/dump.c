/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:27:52 by mdelory           #+#    #+#             */
/*   Updated: 2019/11/13 13:44:21 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				vm_dump(t_vm *vm)
{
	unsigned int	i;

	i = 0;
	ft_dprintf(2, "0x0000 : ");
	while (i < MEM_SIZE)
	{
		ft_dprintf(2, "%02x ", vm->arena[i]);
		i++;
		if (i && i != MEM_SIZE && i % 64 == 0)
			ft_dprintf(2, "\n%#0.4x : ", i);
	}
	write(2, "\n", 1);
}
