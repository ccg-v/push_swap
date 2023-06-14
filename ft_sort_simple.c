/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:14:33 by ccarrace          #+#    #+#             */
/*   Updated: 2023/06/15 00:15:15 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <string.h>

void	ft_sort_three(t_list **stack)
{
	t_list	*max_node;

	if (!ft_is_sorted(*stack))
	{
		max_node = ft_find_max_node(stack);
		if ((*stack)->index == max_node->index)
			ft_rotate(stack, "ra");
		else if ((*stack)->next->index == max_node->index)
			ft_reverse_rotate(stack, "rra");
		if (!ft_is_sorted(*stack))
			ft_swap(stack, "sa");
	}
}

void	ft_send_minimum_index_to_top(t_list **stack)
{
	t_list	*min_node;
	int		stack_len;
	int		distance_to_top;
	int		distance_to_bottom;

	min_node = ft_find_min_node(stack);
	stack_len = ft_list_size(*stack);
	distance_to_top = min_node->place;
	distance_to_bottom = stack_len - min_node->place;
	if (distance_to_top <= distance_to_bottom)
	{
		while (distance_to_top > 0)
		{
			ft_rotate(stack, "ra");
			distance_to_top--;
		}
	}
	else if (distance_to_bottom < distance_to_top)
	{
		while (distance_to_bottom > 0)
		{
			ft_reverse_rotate(stack, "rra");
			distance_to_bottom--;
		}
	}
}

void	ft_sort_few(t_list **stack_a, t_list **stack_b)
{
	if (!ft_is_sorted(*stack_a))
	{
		while (ft_list_size(*stack_a) > 3)
		{
			ft_send_minimum_index_to_top(stack_a);
			ft_push(stack_b, stack_a, "pb");
		}
		ft_sort_three(stack_a);
		while (ft_list_size(*stack_b) > 0)
			ft_push(stack_a, stack_b, "pa");
	}
}
