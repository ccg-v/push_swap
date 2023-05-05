/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:07:40 by ccarrace          #+#    #+#             */
/*   Updated: 2023/05/05 21:21:44 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
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

 size_t		ft_list_size(t_list *lst);
 t_list		*ft_create_node(int num);
 void		ft_add_to_front(t_list **lst, int value);
 void		ft_add_to_back(t_list **lst, int value);

 void		ft_assign_positions(t_list **lst);
 void		ft_index_list(t_list **lst);

#endif
