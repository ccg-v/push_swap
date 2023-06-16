/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:07:40 by ccarrace          #+#    #+#             */
/*   Updated: 2023/06/16 19:20:46 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <string.h>	// strncmp (en ft_moves_....!!!!)
# include <limits.h>	// INT_MAX
# include <stddef.h>	// size_t
# include <unistd.h>	// write
# include <stdio.h>		// printf (when debugging only)

typedef struct s_list
{
	int				value;
	int				place;
	int				index;
	int				gap_to_top;
	int				closest_upper;
	struct s_list	*closest_upper_address;
	struct s_list	*next;
}						t_list;

//			Library functions
long		ft_atol(const char *str);
int			ft_atoi(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_abs(int num);
char		**ft_split(char const *s, char c);
int			ft_strlen(char *str);
int			ft_word_counter(const char *str, char c);

//			List creation 
t_list		*ft_create_node(int num);
void		ft_add_to_front(t_list **lst, int value);
void		ft_add_to_back(t_list **lst, int value);

//			List utilities
int			ft_list_size(t_list *lst);
t_list		*ft_find_max_node(t_list **lst);
t_list		*ft_find_min_node(t_list **lst);
int			ft_is_sorted(t_list *lst);

//			Movements
void		ft_push(t_list **dst, t_list **src, char *stack_name);
void		ft_swap(t_list **stack, char *move_name);
void		ft_swap_both(t_list **a, t_list **b);
void		ft_rotate(t_list **stack, char *move_name);
void		ft_rotate_both(t_list **a, t_list **b);
void		ft_reverse_rotate(t_list **stack, char *move_name);
void		ft_reverse_rotate_both(t_list **a, t_list **b);

//			Creating and filling stack / assigning values to struct variables
void		ft_create_and_fill_stack(t_list **stack_a, int argc, char **argv);
void		ft_assign_places(t_list **lst);
void		ft_assign_indexes(t_list **lst);
void		ft_assign_gaps(t_list **lst);
void		ft_assign_closest_upper(t_list *stack_a, t_list *stack_b);
void		ft_set_assignments(t_list **stack_a, t_list **stack_b);

//			Sorting process
int			ft_split_if_quoted_args(int *argc, char ***argv);
int			ft_check_input(int argc, char **argv);
void		ft_sort_three(t_list **stack);
void		ft_sort_few(t_list **stack_a, t_list **stack_b);
void		ft_sort_complex(t_list **stack_a, t_list **stack_b);

//			Sorting complementary functions
t_list		*ft_find_best_push(t_list **stack_b);
void		ft_send_minimum_index_to_top(t_list **stack);
void		ft_choose_commands(t_list **stack_a, t_list **stack_b, \
			t_list *b_best_push);
void		ft_print_list(t_list *lst, char stack_name);

#endif
