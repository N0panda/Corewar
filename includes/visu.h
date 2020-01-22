/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:24:37 by arlaine           #+#    #+#             */
/*   Updated: 2019/11/20 15:17:46 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include <ncurses.h>
# include <fcntl.h>
# include <sys/types.h>
# include "op.h"
# include "corewar.h"
# include "time.h"
# include "vm.h"

typedef	struct s_corewar	t_corewar;

typedef	struct s_process	t_process;

typedef	struct				s_visu
{
	int		x;
	int		y;
	int		max_y;
	int		max_x;
	int		bet;
	int		refresh_arena;
	int		debug;
	int		debug_index;
	int		vm_stop;
	int		ch;
}							t_visu;

char						*g_fs_msg[4];

/*
** --- Fonctions generiques visu ---------------------
*/

void						init_arena(t_corewar *a);
void						init_visu(t_corewar *a);

/*
** ------------- Fonctions debug ---------------------
*/

int							print_data_debug(t_process *proc, int id, int y);
void						print_debug(t_corewar *a, int y);
int							print_data_debug(t_process *proc, int id, int y);
void						clear_debug(int y);

/*
** --- Ecran d'acceuil -------------------------------
*/

void						first_screen(t_corewar *a);
void						fs_draw_frame(void);

void						bet(t_corewar *a);

void						draw(int y, int x);

/*
** --- Couleurs & defines ----------------------------
*/

short						set_colors(t_corewar *a, int i);
short						set_colors_refresh(t_corewar *a, int i);
void						define_pairs(void);
void						init_colors_players_name(int i_color);
void						off_colors_players_name(int i_color);
void						define_invert_colors(void);

/*
** --- Fonctions pour l'arene ------------------------
*/

int							key_pause_first(t_corewar *a, int ch);
void						key_handle(t_corewar *a);
void						key_pause(t_corewar *a, int ch);
void						print_status_vm(t_corewar *a);
void						trace_win(t_corewar *a);
void						print_base_adress(t_corewar *a, int tmp);
void						print_adress_refresh(t_corewar *a);
void						refresh_arena(t_corewar *a, int appel);

/*
** --- Fonctions exit de la session graphique --------
*/

void						end_win(t_corewar *a);
void						free_core(t_corewar *a);

/*
** --- Fonctions side bar ----------------------------
*/

void						draw_side_bar(t_corewar *a);
void						sb_draw_data(t_corewar *a);
void						sb_draw_debug(t_corewar *a, int y);

#endif
