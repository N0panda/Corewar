/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:17:23 by mdelory           #+#    #+#             */
/*   Updated: 2019/11/18 12:15:24 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"

# include "op.h"
# include "vm.h"
# include "visu.h"

# include <fcntl.h>
# include <errno.h>
# include <sys/time.h>

typedef struct s_vm		t_vm;
typedef struct s_header	t_header;

typedef struct		s_player
{
	char			id;
	long			last_live;
	t_header		*header;
	unsigned char	data[CHAMP_MAX_SIZE];
}					t_player;

typedef	struct s_visu	t_visu;

typedef struct		s_corewar
{
	int				nb_players;
	int				fixed_id[4];
	t_player		*players[4];
	t_visu			*v;
	t_vm			*vm;
}					t_corewar;

t_player			*new_player(char *in);
void				add_player(t_corewar *cw, t_player *p, int id);

int					parse_args(t_corewar *cw, char **av);

int					exit_error(char *fmt, ...);
void				usage(void);
#endif
