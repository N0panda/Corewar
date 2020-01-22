/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:55:09 by mdelory           #+#    #+#             */
/*   Updated: 2019/11/29 19:31:48 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		parse_player_cor(char *str)
{
	char		*ptr;

	if ((ptr = ft_strrchr(str, '.')) && ft_strcmp(ptr, ".cor") == 0)
		return (0);
	return (-1);
}

static void		parse_dump(t_corewar *cw, char *av)
{
	if (cw->vm->dump != 0)
		exit_error("Dump value already set to %ld", cw->vm->dump);
	if (av && ft_strnum(av) > 0)
		cw->vm->dump = ft_atoi(av);
	else if (!av)
		exit_error("Missing dump value");
	else
		exit_error("Invalid dump value: %s", av);
}

static int		parse_player_id(t_corewar *cw, char *av)
{
	int			id;

	id = 0;
	if (!ft_strnum(av))
		exit_error("Invalid player number: %s", av);
	if ((id = ft_atoi(av)) < 1 || id > 4)
		exit_error("Invalid player number: %s", av);
	if (cw->fixed_id[id - 1])
		exit_error("Player number already used: %s", av);
	return (id);
}

static void		parse_player(t_corewar *cw, char *av, int id)
{
	t_player	*p;

	if (av)
	{
		if (cw->nb_players >= 4)
			exit_error("Max players reached");
		if (!(p = new_player(av)))
			exit_error(NULL);
		add_player(cw, p, id);
	}
}

int				parse_args(t_corewar *cw, char **av)
{
	int			id;

	id = -1;
	while (*(++av))
	{
		if (ft_strcmp(*av, "-h") == 0)
			usage();
		else if (ft_strcmp(*av, "-d") == 0)
			parse_dump(cw, *(++av));
		else if (ft_strcmp(*av, "-n") == 0)
			id = parse_player_id(cw, *(++av));
		else if (parse_player_cor(*av) == 0)
		{
			parse_player(cw, *av, id);
			id = -1;
		}
		else
			exit_error("Bad file format : [%s]", *av);
	}
	return (cw->nb_players != 0);
}
