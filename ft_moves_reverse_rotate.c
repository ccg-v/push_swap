/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_reverse_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:53:47 by ccarrace          #+#    #+#             */
/*   Updated: 2023/06/15 00:07:19 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	ft_reverse_rotate(t_list **stack, char *move_name)
{
	t_list	*current;
	t_list	*old_head;
	t_list	*new_head;
	t_list	*new_tail;

	old_head = *stack;
	new_head = NULL;
	new_tail = NULL;
	current = *stack;
	while (current->next)
	{
		new_tail = current;
		current = current->next;
	}
	new_head = current;
	*stack = new_head;
	new_head->next = old_head;
	new_tail->next = NULL;
	ft_assign_places(stack);
	ft_assign_gaps(stack);
	if (ft_strncmp(move_name, "rrr", 3) != 0)
		ft_printf("%s\n", move_name);
}

void	ft_reverse_rotate_both(t_list **stack_a, t_list **stack_b)
{
	ft_reverse_rotate(stack_a, "rrr");
	ft_reverse_rotate(stack_b, "rrr");
	ft_printf("rrr\n");
}
