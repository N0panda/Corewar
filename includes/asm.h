/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ythomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:08:43 by ythomas           #+#    #+#             */
/*   Updated: 2019/11/27 17:54:37 by mdelory          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op_asm.h"
# include "fcntl.h"

# define ZZ_OP		0
# define ZZ_LAB		2
# define ZZ_NAME	1

# define ERF		"\033[48;5;54m"
# define ERP		"\033[38;5;124m"
# define OKF		"\033[48;5;50m\033[38;5;232m"
# define ERD		"\033[0m"

# define ONE_SIZE	1
# define TWO_SIZE	2
# define FOUR_SIZE	4
# define HEAD_SIZE	4385

# define D4(a) (a == 1 || a == 2 || a == 6 || a == 7 || a == 8 || a == 13)

# define BASE		16

typedef struct		s_label
{
	char			*label;
	int				position;
	void			*next;
}					t_label;

typedef	struct		s_line
{
	char			**action_tab;
	char			**param_tab;
	int				*param_type;
	int				*param_final;
	int				*param_code;
	char			*action_line;
	int				*bit_type;
	int				id_line;
	unsigned char	instruction;
	int				op_position;
	int				nb_params;
	int				type;
	int				ocp;
	int				octet;
	int				dist;
	int				size_type;
	unsigned char	value_ocp;
}					t_line;

typedef	struct		s_env
{
	int				fd;
	char			*name;
	char			*comment;
	int				champion_size;
	char			*file_name;
	int				nb_actions;
	char			**file;
	t_line			**actions;
	t_label			*lab_list;
}					t_env;

int					get_and_copy_file(t_env *env, char *file_name);

int					free_env(t_env *env);
int					ft_error(int err, char *file);
int					parse_error(int err, char *file, char *line);
int					build_actions(t_env *env, char *file_name);

int					create_label(t_env *env, char *str);
int					fill_label_param_value(t_env *env);

int					free_tools(char **str, int er, char *name, char *line);

int					parse_op_and_name(t_env *env, t_line *act, char *line);
int					parse_name_comm(t_env *env, t_line *act, char *line);
int					parse_param(t_env *env, t_line *act);
int					bad_spacing(t_env *env);

char				*epur_str(char *s);
long				atoi_reg(char *str);
long				atoi_ind_dir(char *str);
int					set_total_distance(t_env *env);
int					count_param(char **tab, int params);

int					set_ocp_and_value(t_env *env, t_line *act);
int					set_distance_label_from_start(t_env *env);

int					check_empty_line(char *str);
int					check_if_reg(t_env *env, t_line *act, char *str, int t);
int					check_if_dir(t_env *env, t_line *act, char *str, int t);
int					check_if_lab_exist(t_env *env,
					t_line *act, char *str, int t);
int					check_if_ind(t_env *env, t_line *act, char *str, int t);

int					create_binary_file(t_env *env);
int					header_add_magic_number(int fd);
void				hex_ascii_to_buffer(char *buffer, int *index, char nb);
int					header_add_name(char *str, int fd);
int					header_add_comment(char *str, int fd);
int					fill_champion_buffer(t_env *env, int fd);
char				*get_name_cor(t_env *env);
void				reverse_writing(int fd, int value, int octet);

void				print_ocp(t_env *env);
void				print_all_actions(t_env *env);
void				print_whole_file(char **file);
void				print_label_tab(t_env *env);
void				print_action_tab(t_env *env);
void				print_param_tab(t_env *env);
void				print_type(t_env *env);
void				print_param_hexa(t_env *env);

#endif
