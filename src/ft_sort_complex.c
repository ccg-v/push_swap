/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_complex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:42:08 by ccarrace          #+#    #+#             */
/*   Updated: 2023/06/15 00:28:08 by ccarrace         ###   ########.fr       */
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
		b_node = b_node->next;
	}
	return (best_push_address);
}

void	ft_choose_double_command(t_list **stack_a, t_list **stack_b, \
	int *a_gap, int *b_gap)
{
	if (*a_gap > 0 && *b_gap > 0)
	{
		while (*a_gap > 0 && *b_gap > 0)
		{
			(*a_gap)--;
			(*b_gap)--;
			ft_rotate_both(stack_a, stack_b);
		}
	}
	else if (*a_gap < 0 && *b_gap < 0)
	{
		while (*a_gap < 0 && *b_gap < 0)
		{
			(*a_gap)++;
			(*b_gap)++;
			ft_reverse_rotate_both(stack_a, stack_b);
		}
	}
}

void	ft_choose_rotation_in_a(t_list **stack_a, int *a_gap)
{
	if (*a_gap > 0)
	{
		ft_rotate(stack_a, "ra");
		(*a_gap)--;
	}
	else if (*a_gap < 0)
	{
		ft_reverse_rotate(stack_a, "rra");
		(*a_gap)++;
	}
}

void	ft_choose_rotation_in_b(t_list **stack_b, int *b_gap)
{
	if (*b_gap > 0)
	{
		ft_rotate(stack_b, "rb");
		(*b_gap)--;
	}
	else if (*b_gap < 0)
	{
		ft_reverse_rotate(stack_b, "rrb");
		(*b_gap)++;
	}
}

void	ft_choose_commands(t_list **stack_a, t_list **stack_b, \
	t_list *b_best_push)
{
	t_list	*a_best_push;
	int		a_gap;
	int		b_gap;

	a_best_push = b_best_push->closest_upper_address;
	a_gap = a_best_push->gap_to_top;
	b_gap = b_best_push->gap_to_top;
	if ((a_gap > 0 && b_gap > 0) || (a_gap < 0 && b_gap < 0))
		ft_choose_double_command(stack_a, stack_b, &a_gap, &b_gap);
	while (a_best_push->gap_to_top)
		ft_choose_rotation_in_a(stack_a, &a_gap);
	while (b_gap)
		ft_choose_rotation_in_b(stack_b, &b_gap);
	ft_push(stack_a, stack_b, "pa");
}
