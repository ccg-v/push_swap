/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:07:40 by ccarrace          #+#    #+#             */
/*   Updated: 2023/05/14 11:29:58 by ccarrace         ###   ########.fr       */
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
		struct s_list	*next;
 }						t_list;

//			libft
 long		ft_atol(const char *str);

//			Lists 
 t_list		*ft_create_node(int num);
 void		ft_add_to_front(t_list **lst, int value);
 void		ft_add_to_back(t_list **lst, int value);

//			List utilities
 int		ft_list_size(t_list *lst);

//			Movements
 int		ft_push(t_list **dst, t_list **src, char *stack_name, int movements);
 int		ft_swap(t_list **stack, char *move_name, int movements);
 void		ft_swap_both(t_list **a, t_list **b, int movements);
 int		ft_rotate(t_list **stack, char *move_name, int movements);
 void		ft_rotate_both(t_list **a, t_list **b, int movements);
 int		ft_reverse_rotate(t_list **stack, char *move_name, int movements);
 void		ft_reverse_rotate_both(t_list **a, t_list **b, int movements);

//			Sort utilities
 void		ft_assign_places(t_list **lst);
 void		ft_index_list(t_list **lst);
 int		ft_is_sorted(t_list *lst);
 int		ft_sort_three(t_list **stack, int movements);

#endif
