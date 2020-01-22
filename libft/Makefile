# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdelory <mdelory@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 20:47:09 by mdelory           #+#    #+#              #
#    Updated: 2019/11/21 16:14:24 by arlaine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 			libft.a

SRC_LK =		lk_list/lk_lst_new.c\
				lk_list/lk_lst_push_f.c\
				lk_list/lk_lst_push_b.c\
				lk_list/lk_lst_next.c\
				lk_list/lk_lst_prev.c\
				lk_list/lk_lst_init.c\
				lk_list/lk_lst_iter.c

SRC_PF =		ft_printf/ft_asprintf.c\
				ft_printf/ft_dprintf.c\
				ft_printf/ft_printf.c\
				ft_printf/ft_snprintf.c\
				ft_printf/ft_sprintf.c\
				ft_printf/ft_vasprintf.c\
				ft_printf/ft_vdprintf.c\
				ft_printf/ft_vprintf.c\
				ft_printf/ft_vsnprintf.c\
				ft_printf/ft_vsprintf.c\
				ft_printf/pf_buffer.c\
				ft_printf/pf_conv.c\
				ft_printf/pf_dbg.c\
				ft_printf/pf_numeric_conv.c\
				ft_printf/pf_numeric_varg.c\
				ft_printf/pf_parsing.c\
				ft_printf/pf_string_conv.c\
				ft_printf/pf_wstring_conv.c

SRC_VECTOR = 	vector/vector_init.c \
				vector/vector_count.c \
				vector/vector_add.c \
				vector/vector_set.c \
				vector/vector_at.c \
				vector/vector_in.c \
				vector/vector_delete.c \
				vector/vector_free.c \
				vector/vector_print.c \
				vector/vector_for_each.c \
				vector/vector_sort.c \
				vector/vector_free_all.c \
				vector/vector_destroy.c \
				vector/vector_clear.c \
				vector/vector_copy.c

SRC_FT =		ft/ft_putchar.c \
				ft/ft_putchar_fd.c \
				ft/ft_putstr.c \
				ft/ft_putstr_fd.c \
				ft/ft_putendl.c \
				ft/ft_putendl_fd.c \
				ft/ft_putnbr.c \
				ft/ft_putnbr_fd.c \
				ft/ft_strcpy.c \
				ft/ft_strncpy.c \
				ft/ft_strcat.c \
				ft/ft_strncat.c \
				ft/ft_strlcat.c \
				ft/ft_strchr.c \
				ft/ft_strrchr.c \
				ft/ft_strstr.c \
				ft/ft_strnstr.c \
				ft/ft_strcmp.c \
				ft/ft_strdup.c \
				ft/ft_strncmp.c \
				ft/ft_atoi.c \
				ft/ft_itoa.c \
				ft/ft_itoa_base.c \
				ft/ft_strlen.c \
				ft/ft_isalpha.c \
				ft/ft_isdigit.c \
				ft/ft_strnum.c \
				ft/ft_isalnum.c \
				ft/ft_isascii.c \
				ft/ft_isprint.c \
				ft/ft_tolower.c \
				ft/ft_toupper.c \
				ft/ft_memset.c \
				ft/ft_bzero.c \
				ft/ft_memalloc.c \
				ft/ft_memcpy.c \
				ft/ft_memccpy.c \
				ft/ft_memmove.c \
				ft/ft_memchr.c \
				ft/ft_memcmp.c \
				ft/ft_strnew.c \
				ft/ft_memdel.c \
				ft/ft_strdel.c \
				ft/ft_strclr.c \
				ft/ft_striter.c \
				ft/ft_striteri.c \
				ft/ft_strmap.c \
				ft/ft_strmapi.c \
				ft/ft_strequ.c \
				ft/ft_strnequ.c \
				ft/ft_strsub.c \
				ft/ft_strjoin.c \
				ft/ft_strtrim.c \
				ft/ft_strdtrim.c \
				ft/ft_strsplit.c \
				ft/ft_lstnew.c \
				ft/ft_lstdelone.c \
				ft/ft_lstdel.c \
				ft/ft_lstadd.c \
				ft/ft_lstiter.c \
				ft/ft_lstmap.c \
				ft/ft_lstrev.c \
				ft/ft_lstaddnew.c \
				ft/ft_numlen.c \
				ft/ft_strext.c \
				ft/ft_strpbrk.c \
				ft/ft_numlen_base.c \
				ft/get_next_line.c \
				ft/ft_strtok.c \
				ft/ft_strspn.c \
				ft/ft_strcspn.c \
				ft/ft_matrix.c \
				ft/ft_print_matrix.c \
				ft/ft_freetab.c \
				ft/ft_min.c \
				ft/ft_max.c

SRC =			$(SRC_LK) $(SRC_PF) $(SRC_VECTOR) $(SRC_FT)

OBJ = 			$(SRC:.c=.o)

INC =			-Iincludes
CFLAGS +=		-g -Werror -Wall -Wextra

CC =			gcc
AR =			ar rc
RM =			rm -f

################################################################################
################################################################################

all: 			$(NAME)

%.o:			%.c
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $^

$(NAME):		$(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo -e "\r\033[K- $(NAME) \033[92m\xE2\x9C\x94\033[0m"

.phony: clean
clean:
	@$(RM) $(OBJ)

.phony: fclean
fclean:			 clean
	@$(RM) $(NAME)

.phony: re
re: fclean all
