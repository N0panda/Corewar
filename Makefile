# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 20:47:09 by mdelory           #+#    #+#              #
#    Updated: 2019/11/30 18:49:56 by juepee-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CW := 		corewar
NAME_ASM := 	asm

SRC_DIR :=		./srcs

INC_DIR :=		./includes \
				./libft/includes

OBJ_DIR :=		./objs

SRC_CW :=		op.c \
				corewar/corewar.c \
				corewar/dump.c \
				corewar/error.c \
				corewar/parsing.c \
				corewar/player.c \
				corewar/process.c \
				corewar/vm2.c \
				corewar/vm.c \
				corewar/vm_rw.c \
				corewar/exec_ops/ex_add.c \
				corewar/exec_ops/ex_aff.c \
				corewar/exec_ops/ex_and.c \
				corewar/exec_ops/ex_fork.c \
				corewar/exec_ops/ex_ld.c \
				corewar/exec_ops/ex_ldi.c \
				corewar/exec_ops/ex_lfork.c \
				corewar/exec_ops/ex_live.c \
				corewar/exec_ops/ex_lld.c \
				corewar/exec_ops/ex_lldi.c \
				corewar/exec_ops/ex_or.c \
				corewar/exec_ops/ex_st.c \
				corewar/exec_ops/ex_sti.c \
				corewar/exec_ops/ex_sub.c \
				corewar/exec_ops/ex_xor.c \
				corewar/exec_ops/ex_zjmp.c \
				visu/visu.c \
				visu/init.c \
				visu/first_screen.c \
				visu/fs_frame.c \
				visu/bet.c \
				visu/colors.c \
				visu/colors_op.c \
				visu/debug.c \
				visu/end.c \
				visu/key_handle.c \
				visu/side_bar.c

SRC_ASM :=		asm/op_asm.c \
				asm/main.c \
				asm/pre_parsing.c \
				asm/cleaning_tools.c \
				asm/init_actions.c \
				asm/tools.c \
				asm/print_file.c \
				asm/error.c \
				asm/check_line.c \
				asm/parsing_action.c \
				asm/parse_name_comment.c \
				asm/parse_params.c \
				asm/check_param_detail.c \
				asm/ocp_and_value.c \
				asm/label_tools.c \
				asm/label_file.c \
				asm/header_print.c \
				asm/big_endian.c

OBJ_CW :=		$(SRC_CW:%.c=$(OBJ_DIR)/%.o)

OBJ_ASM :=		$(SRC_ASM:%.c=$(OBJ_DIR)/%.o)

INC_FLAGS :=	$(addprefix -I, $(INC_DIR))
LIB_FLAGS :=	-Llibft -lft

CFLAGS +=		-Werror -Wall -Wextra

RM :=			rm -rf
MKDIR :=		mkdir -p

################################################################################
################################################################################

all: 			$(NAME_CW) $(NAME_ASM)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	@$(MKDIR) $(dir $@)
	@$(CC) $(CFLAGS) $(INC_FLAGS) -c -o $@ $^

$(NAME_CW):		libft/libft.a $(OBJ_CW)
	$(CC) $(OBJ_CW) -o $(NAME_CW) -lncurses $(LIB_FLAGS)
	@echo "> $(NAME_CW)"

$(NAME_ASM):	libft/libft.a $(OBJ_ASM)
	$(CC) $(OBJ_ASM) -o $(NAME_ASM) $(LIB_FLAGS)
	@echo "> $(NAME_ASM)"

libft/libft.a:
	@$(MAKE) -s -C libft

.phony:	clean
clean:
	@$(MAKE) clean -s -C libft
	@$(RM) $(OBJ_DIR)

.phony: fclean
fclean:		clean
	@$(MAKE) fclean -s -C libft
	@$(RM) $(NAME_CW)
	@$(RM) $(NAME_ASM)

.phony: re
re:		fclean all
