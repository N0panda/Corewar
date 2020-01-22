/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:26:44 by mdelory           #+#    #+#             */
/*   Updated: 2019/11/28 19:55:21 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "vm.h"

static void		clean(t_corewar *cw)
{
	int			i;

	vector_destroy(&cw->vm->v_process);
	free(cw->vm);
	free(cw->v);
	i = -1;
	while (++i < 4)
	{
		if (cw->players[i])
		{
			free(cw->players[i]->header);
			free(cw->players[i]);
		}
	}
}

static int		init(t_corewar *corewar)
{
	if (!(corewar->v = ft_memalloc(sizeof(t_visu))))
		return (0);
	ft_bzero(corewar->fixed_id, sizeof(int) * 4);
	ft_bzero(corewar->players, sizeof(t_player *) * 4);
	corewar->nb_players = 0;
	return (vm_init(corewar));
}

static void		end(t_corewar *cw)
{
	long	h;
	int		i;
	int		p;

	i = 0;
	h = 0;
	p = 0;
	if (cw->v->vm_stop == 0)
	{
		while (i < 4)
		{
			if (cw->players[i])
			{
				if (cw->vm->last_live[i] >= h)
				{
					h = cw->vm->last_live[i];
					p = i;
				}
			}
			i++;
		}
		ft_printf("Le joueur %d(%s) a gagne\n", p + 1, \
				cw->players[p]->header->prog_name);
	}
}

int				main(int ac, char **av)
{
	t_corewar	cw;
	int			ret;

	if (ac == 1)
		usage();
	if (init(&cw) && parse_args(&cw, av))
	{
		vm_load(&cw);
		init_visu(&cw);
		first_screen(&cw);
		init_arena(&cw);
		ret = vm_run(&cw);
		end_win(&cw);
		if (ret == 0)
			end(&cw);
		if (cw.vm->dump)
			vm_dump(cw.vm);
	}
	clean(&cw);
	return (0);
}
