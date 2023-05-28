/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:14:33 by ccarrace          #+#    #+#             */
/*   Updated: 2023/05/26 22:15:21 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <string.h>

void	ft_sort_three(t_list **stack, int *command_counter)
{
	t_list	*max_node;

	if (!ft_is_sorted(*stack))
	{
		max_node = ft_find_max_node(stack);
		if ((*stack)->index == max_node->index)
			ft_rotate(stack, "ra", command_counter);
		else if	((*stack)->next->index == max_node->index)
			ft_reverse_rotate(stack, "rra", command_counter);
		if (!ft_is_sorted(*stack))
			ft_swap(stack, "sa", command_counter);
	}
}

void	ft_send_minimum_index_to_top(t_list **stack, int *command_counter)
{
	t_list	*min_node;
	int		stack_len;
	int		distance_to_top;
	int		distance_to_bottom;

	min_node = ft_find_min_node(stack);
	stack_len = ft_list_size(*stack) + 1;
	distance_to_top = min_node->place - 1;
	distance_to_bottom = stack_len - min_node->place;
	if(distance_to_top <= distance_to_bottom)
	{
		while(distance_to_top > 0)
		{
			ft_rotate(stack, "ra", command_counter);
			distance_to_top--;
		}
	}
	else if(distance_to_bottom < distance_to_top)
	{
		while(distance_to_bottom > 0)
		{
			ft_reverse_rotate(stack, "rra", command_counter);
			distance_to_bottom--;
		}
	}
}

void	ft_sort_few(t_list *stack_a, t_list *stack_b, int *command_counter)
{
	while(ft_list_size(stack_a) > 3)
	{
		ft_send_minimum_index_to_top(&stack_a, command_counter);
		ft_push(&stack_b, &stack_a, "pb", command_counter);
	}
	ft_sort_three(&stack_a, command_counter);
	while(ft_list_size(stack_b)>0)
		ft_push(&stack_a, &stack_b, "pa", command_counter);
}

void	ft_initialize_stack(t_list **stack_a, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
		{
			ft_add_to_back(stack_a, atoi(argv[i]));
			i++;
		}
		ft_assign_places(stack_a);
		ft_index_list(stack_a);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		command_counter;

	stack_a = NULL;
	stack_b = NULL;
	command_counter = 0;
	if (ft_check_input(argc, argv) == 1)
	{
		ft_initialize_stack(&stack_a, argc, argv);
		if (argc < 100)
		{
			ft_sort_few(stack_a, stack_b, &command_counter);
		}
	}
//	if (ft_check_input(argc, argv) == 1)
//	{
//		while (i < argc)
//		{
//			ft_add_to_back(&stack_a, atoi(argv[i]));
//			i++;
//		}
//		ft_assign_places(&stack_a);
//		ft_index_list(&stack_a);
//		ft_print_list(stack_a, 'A');
//		while(ft_list_size(stack_a) > 3)
//		{
//			ft_send_minimum_index_to_top(&stack_a, &command_counter);
//			ft_push(&stack_b, &stack_a, "pb", &command_counter);
//		}	
//		ft_sort_three(&stack_a, &command_counter);
//		while(ft_list_size(stack_b) > 0)
//			ft_push(&stack_a, &stack_b, "pa", &command_counter);
//		ft_print_list(stack_a, 'A');
printf("Number of commands used: %d\n", command_counter);
	return (0);
}