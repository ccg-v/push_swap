# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 19:25:44 by ccarrace          #+#    #+#              #
#    Updated: 2023/06/15 00:16:43 by ccarrace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Constants -------------------------------------------------------------- #

CC				=		gcc
CFLAGS			=		-MMD -Wall -Wextra -Werror -g
HEADER_NAME		=		push_swap.h
NAME			=		push_swap

# --- Folders ---------------------------------------------------------------- #

PRINTF_DIR		=		ft_printf/
PRINTF_INCLUDE	=		-I $(PRINTF_DIR)

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

# --- Macros / variables ----------------------------------------------------- #

OBJ_FILES =	$(SRC_FILES:.c=.o)
DEP_FILES =	$(SRC_FILES:.c=.d)

# --- Compilation rules ------------------------------------------------------ #

all: 	$(NAME)

$(NAME): $(HEADER_NAME) $(OBJ_FILES)
	$(MAKE) -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(PRINTF_DIR)/libftprintf.a -o $@

%.o: %.c $(HEADER_NAME)
	$(CC) -c $(CFLAGS) $(PRINTF_INCLUDE) $< -o $@

# --- Cleaning rules --------------------------------------------------------- #

clean:
				rm -f $(OBJ_FILES) $(DEP_FILES)
				$(MAKE) -C $(PRINTF_DIR) clean

fclean:			clean
				rm -f $(NAME)
				$(MAKE) -C $(PRINTF_DIR) fclean
				
re:				fclean all

.PHONY:			all clean fclean re

-include		$(DEP_FILES)
