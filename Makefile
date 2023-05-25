# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 19:25:44 by ccarrace          #+#    #+#              #
#    Updated: 2023/05/25 21:09:16 by ccarrace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Constants -------------------------------------------------------------- #

CC				=		gcc
CFLAGS			=		-MMD -Wall -Wextra -Werror -g
HEADER_NAME		=		push_swap.h
NAME			=		push_swap

# --- Files ------------------------------------------------------------------ #

SRC_FILES =	ft_create_node.c \
			ft_add_to_back.c \
			ft_list_size.c \
			ft_index_list.c \
			ft_assign_places.c \
			ft_assign_dist_to_right_place.c \
			ft_assign_gaps.c \
			ft_is_sorted.c \
			ft_moves_push.c \
			ft_moves_swap.c \
			ft_moves_rotate.c \
			ft_moves_reverse_rotate.c \
			ft_check_input.c \
			ft_sort_three.c \
			ft_sort_complex.c \
			ft_atol.c \
			ft_list_utilities.c \
			ft_putstr_fd.c

# --- Macros / variables ----------------------------------------------------- #

OBJ_FILES =	$(SRC_FILES:.c=.o)
DEP_FILES =	$(SRC_FILES:.c=.d)

# --- Compilation rules ------------------------------------------------------ #

all: $(NAME)

$(NAME): $(HEADER_NAME) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $@

%.o: %.c $(HEADER_NAME)
	$(CC) -c $(CFLAGS) $< -o $@

# --- Cleaning rules --------------------------------------------------------- #

clean:
				rm -f $(OBJ_FILES) $(DEP_FILES)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re

-include		$(DEP_FILES)
