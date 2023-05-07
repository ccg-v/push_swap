/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:07:40 by ccarrace          #+#    #+#             */
/*   Updated: 2023/05/07 21:58:33 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>	// strncmp
# include <limits.h>	// INT_MAX
# include <stddef.h>	// size_t
# include <unistd.h>	// write

 typedef struct	s_list
 {
		int				value;
		int				position;
		int				index;
		struct s_list	*next;
 }						t_list;

//			Lists 
 t_list		*ft_create_node(int num);
 void		ft_add_to_front(t_list **lst, int value);
 void		ft_add_to_back(t_list **lst, int value);

//			List utilities
 int		ft_list_size(t_list *lst);

//			Movements
 void		ft_push(t_list **dst, t_list **src, char *stack_name);
 void		ft_swap(t_list **stack, char *move_name);
 void		ft_swap_both(t_list **a, t_list **b);
 void		ft_rotate(t_list **stack, char *move_name);
 void		ft_rotate_both(t_list **a, t_list **b);
 void		ft_reverse_rotate(t_list **stack, char *move_name);
 void		ft_reverse_rotate_both(t_list **a, t_list **b);

//			Sort utilities
 void		ft_assign_places(t_list **lst);
 void		ft_index_list(t_list **lst);
 int		ft_is_sorted(t_list *lst);
 void		ft_sort_three(t_list **stack);

#endif
