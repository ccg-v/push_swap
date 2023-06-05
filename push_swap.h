/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:07:40 by ccarrace          #+#    #+#             */
/*   Updated: 2023/06/06 01:10:37 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>		// write
# include <stdlib.h>
# include <string.h>	// strncmp (en ft_moves_....!!!!)
# include <limits.h>	// INT_MAX
# include <stddef.h>	// size_t
# include <unistd.h>	// write

 typedef struct	s_list
 {
		int				value;
		int				place;
		int				index;
		int				gap_to_top;
		int				gap_to_bottom;
//		int				dist_to_right_place;
		int				closest_upper;
		struct s_list	*closest_upper_address;
		struct s_list	*next;
 }						t_list;

//			Library functions
long		ft_atol(const char *str);
void		ft_putstr_fd(char *s, int fd);

//			List creation 
 t_list		*ft_create_node(int num);
 void		ft_add_to_front(t_list **lst, int value);
 void		ft_add_to_back(t_list **lst, int value);

//			List utilities
 int		ft_list_size(t_list *lst);
 t_list		*ft_find_max_node(t_list **lst);
 t_list		*ft_find_min_node(t_list **lst);

//			Movements
 void		ft_push(t_list **dst, t_list **src, char *stack_name, int *command_counter);
 void		ft_swap(t_list **stack, char *move_name, int *command_counter);
 void		ft_swap_both(t_list **a, t_list **b, int *command_counter);
 void		ft_rotate(t_list **stack, char *move_name, int *command_counter);
 void		ft_rotate_both(t_list **a, t_list **b, int *command_counter);
 void		ft_reverse_rotate(t_list **stack, char *move_name, int *command_counter);
 void		ft_reverse_rotate_both(t_list **a, t_list **b, int *command_counter);

//			Filling struct with data
 void		ft_fill_stack(t_list **stack_a, int argc, char **argv);
 void		ft_assign_places(t_list **lst);
// void 		ft_assign_dist_to_right_place(t_list **lst);
 void		ft_assign_gaps(t_list **lst);

//			Sorting process
 int		ft_check_input(int argc, char **argv);
 void		ft_sort_three(t_list **stack, int *command_counter);
 void		ft_sort_few(t_list **stack_a, t_list **stack_b, int *command_counter);
 void		ft_sort_complex(t_list **stack_a, t_list **stack_b, int *command_counter);

//			Sort utilities
 void		ft_index_list(t_list **lst);
 int		ft_is_sorted(t_list *lst);
 void		ft_assign_closest_upper(t_list **stack_a, t_list **stack_b);
 t_list		*ft_find_best_push(t_list **stack_b);
 void		ft_send_minimum_index_to_top(t_list **stack, int *command_counter);
 void		ft_choose_single_commands(t_list **stack_a, t_list **stack_b, t_list *b_best_push, int *command_counter);

 void		ft_print_list(t_list *lst, char stack_name);

#endif
