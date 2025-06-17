# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 19:25:44 by ccarrace          #+#    #+#              #
#    Updated: 2024/10/29 22:29:24 by ccarrace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Variables -------------------------------------------------------------- #

CC				=		gcc
#HEADER_NAME		=		push_swap.h
NAME			=		push_swap
PRINTF_NAME		=		libftprintf.a

# --- Compiler flags --------------------------------------------------------- #

CFLAGS			=		-MMD -Wall -Wextra -Werror

# --- Directories ------------------------------------------------------------ #

INC_DIR			=		inc/
SRC_DIR			=		src/
OBJ_DIR			=		obj/
DEP_DIR			=		$(OBJ_DIR)
PRINTF_DIR		=		ft_printf/

# --- Includes --------------------------------------------------------------- #

INCLUDES		=		-I $(INC_DIR) -I $(PRINTF_DIR)

# --- Paths ------------------------------------------------------------------ #

PRINTF_LIB		=		$(addprefix $(PRINTF_DIR), $(PRINTF_NAME))

# --- Files ------------------------------------------------------------------ #

SRC_FILES =	ft_check_input.c \
			ft_create_and_fill_stack.c \
			ft_set_assignments.c \
			ft_moves_push.c \
			ft_moves_swap.c \
			ft_moves_rotate.c \
			ft_moves_reverse_rotate.c \
			ft_list_utilities.c \
			ft_sort_simple.c \
			ft_sort_complex.c \
			ft_library.c \
			ft_split.c \
			push_swap.c

OBJ_FILES =	$(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))
DEP_FILES =	$(addprefix $(DEP_DIR), $(SRC_FILES:.c=.d))

# --- Building rules ---------------------------------------------------------- #

all: $(OBJ_DIR) $(NAME)

# --- Object building rules --------------------------------------------------- #

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

# Object file building rule
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

# --- Program building rules ------------------------------------------------- #

$(NAME): $(OBJ_FILES) $(PRINTF_LIB) Makefile
	$(CC) $(CFLAGS) $(OBJ_FILES) $(PRINTF_LIB) -o $@

# --- Cleaning rules --------------------------------------------------------- #

clean:
				rm -f $(OBJ_PATH) $(DEP_PATH)
				rm -rf $(OBJ_DIR)
				$(MAKE) -C $(PRINTF_DIR) clean

fclean:			clean
				rm -f $(NAME)
				$(MAKE) -C $(PRINTF_DIR) fclean
				
re:				fclean all

.PHONY:			all clean fclean re

-include		$(DEP_PATH)
