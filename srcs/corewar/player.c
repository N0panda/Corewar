/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:38:12 by mdelory           #+#    #+#             */
/*   Updated: 2019/11/28 19:34:16 by ythomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>

static uint32_t		tole(uint32_t num)
{
	return (((num >> 24) & 0xff) \
			| ((num << 8) & 0xff0000) \
			| ((num >> 8) & 0xff00) \
			| ((num << 24) & 0xff000000));
}

static int			get_next_slot(t_corewar *cw)
{
	int			i;

	i = 0;
	while (cw->players[i])
		i++;
	return (i);
}

void				add_player(t_corewar *cw, t_player *p, int id)
{
	t_player	*swap;

	swap = NULL;
	if (id != -1)
	{
		if (cw->players[id - 1])
			swap = cw->players[id - 1];
		cw->fixed_id[id - 1] = 1;
		cw->players[id - 1] = p;
	}
	else
		swap = p;
	if (swap)
		cw->players[get_next_slot(cw)] = swap;
	cw->nb_players++;
}

t_player			*new_player(char *in)
{
	int					fd;
	t_player			*p;
	t_header			*h;

	if (!in || (fd = open(in, O_RDONLY)) < 0)
		return (NULL);
	if (!(h = ft_memalloc(sizeof(t_header))))
		return (NULL);
	if ((p = (t_player *)malloc(sizeof(t_player))))
	{
		p->header = h;
		ft_bzero(p->data, CHAMP_MAX_SIZE);
		if (read(fd, p->header, sizeof(t_header)) < (int)sizeof(t_header) || \
				p->header->magic != (uint32_t)tole(COREWAR_EXEC_MAGIC))
			exit_error("Invalid file format (%s)", in);
		p->header->prog_size = ft_min(tole(p->header->prog_size), \
									CHAMP_MAX_SIZE);
		if (read(fd, p->data, p->header->prog_size) < p->header->prog_size)
			exit_error("Invalid file size (%s)", in);
	}
	else
		free(h);
	close(fd);
	return (p);
}
