/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:53:47 by ccarrace          #+#    #+#             */
/*   Updated: 2023/06/11 20:26:56 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	ft_rotate(t_list **stack, char *move_name, int *command_counter)
{
	t_list	*head;
	t_list	*tail;
	t_list	*tmp;

	tail = NULL;
	head = *stack;
	tmp = head;
	*stack = head->next;
	while (tmp->next)
		tmp = tmp->next;
	tail = tmp;
	tail->next = head;
	head->next = NULL;
	ft_assign_places(stack);
	ft_assign_gaps(stack);
	if (ft_strncmp(move_name, "rr", 3) != 0)
	{
//		write(1, move_name, 3);
		ft_printf("%s\n", move_name);
		(*command_counter)++;
	}
}

void	ft_rotate_both(t_list **a, t_list **b, int *command_counter)
{
	ft_rotate(a, "rr", command_counter);
	ft_rotate(b, "rr", command_counter);
//	write(1, "rr\n", 3);
	ft_printf("rr\n");
	(*command_counter)++;
}
