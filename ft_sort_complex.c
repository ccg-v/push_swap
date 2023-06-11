/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_complex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:42:08 by ccarrace          #+#    #+#             */
/*   Updated: 2023/06/12 00:38:38 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_find_best_push(t_list **stack_b)
{
	t_list	*b_node;
	t_list	*best_push_address;
	int		lowest_sum_of_gaps;
	int		current_sum_of_gaps;

	b_node = *stack_b;
	lowest_sum_of_gaps = INT_MAX;
	while (b_node)
	{
		current_sum_of_gaps = (ft_abs(b_node->gap_to_top) + \
							ft_abs(b_node->closest_upper_address->gap_to_top));
		if (current_sum_of_gaps < lowest_sum_of_gaps)
		{
			lowest_sum_of_gaps = current_sum_of_gaps;
			best_push_address = b_node;
		}
// START OF FIRST IMPROVEMENT
// cuando dos pares de nodos suman igual numero de comandos, no quedarse con el
// primero y elegir aquel en el que ambos tienen el gap_to_top de igual signo,
// porque podemos moverlos a la vez con los comandos dobles y ahorrar instrucciones
		if (current_sum_of_gaps == lowest_sum_of_gaps)
		{
			if ((ft_list_size(*stack_b) % 2 == 0) && b_node->gap_to_top == (ft_list_size(*stack_b) / 2))// && b_node->closest_upper_address->gap_to_top > 0)
				best_push_address = b_node;
			else if ((b_node->gap_to_top > 0 && b_node->closest_upper_address->gap_to_top > 0) \
			|| (b_node->gap_to_top < 0 && b_node->closest_upper_address->gap_to_top < 0))
				best_push_address = b_node;
		}
// END OF FIRST IMPROVEMENT
		b_node = b_node->next;
	}
	return (best_push_address);
}

void	ft_choose_single_commands(t_list **stack_a, t_list **stack_b, \
							t_list *b_best_push, int *command_counter)
{
	t_list	*a_best_push;
	int		a_gap;
	int		b_gap;

	a_best_push = b_best_push->closest_upper_address; // change to a_best_push = ft_find_best_push(stack_b) y lo elimino del main?????
	a_gap = a_best_push->gap_to_top;
	b_gap = b_best_push->gap_to_top;
	if (a_gap > 0 && b_gap > 0)
	{
		while (a_gap > 0 && b_gap > 0)
		{
			a_gap--;
			b_gap--;
			ft_rotate_both(stack_a, stack_b, command_counter);
		}
	}
	else if (a_gap < 0 && b_gap < 0)
	{
		while (a_gap < 0 && b_gap < 0)
		{
			a_gap++;
			b_gap++;
			ft_reverse_rotate_both(stack_a, stack_b, command_counter);
		}
	}
	while (a_best_push->gap_to_top)
	{
		if (a_gap > 0)
		{
			ft_rotate(stack_a, "ra", command_counter);
			a_gap--;
		}
		else if (a_gap < 0)
		{
			ft_reverse_rotate(stack_a, "rra", command_counter);
			a_gap++;
		}
	}
	while (b_gap)
	{
		if (b_gap > 0)
		{
			ft_rotate(stack_b, "rb", command_counter);
			b_gap--;
		}
		else if (b_gap < 0)
		{
			ft_reverse_rotate(stack_b, "rrb", command_counter);
			b_gap++;
		}
	}
	ft_push(stack_a, stack_b, "pa", command_counter);
}
