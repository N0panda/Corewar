/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2019/11/15 19:12:45 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				(4*1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10

# include <stdint.h>
# include "vm.h"

typedef char	t_arg_type;

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef struct s_vm				t_vm;
typedef struct s_process		t_process;

typedef struct					s_header
{
	uint32_t					magic;
	char						prog_name[PROG_NAME_LENGTH];
	char						pad1[4];
	uint32_t					prog_size;
	char						comment[COMMENT_LENGTH];
	char						pad2[4];
}								t_header;

typedef struct					s_op
{
	char						*name;
	int							argc;
	t_arg_type					args_type[3];
	char						code;
	int							cycle;
	char						*descr;
	int							ocp;
	int							unknown;
}								t_op;

t_op							g_op_tab[17];
int								(*g_op_func[17])(t_process *, t_vm *);

#endif
