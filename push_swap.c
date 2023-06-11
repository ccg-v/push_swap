/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:16:01 by ccarrace          #+#    #+#             */
/*   Updated: 2023/06/11 22:09:22 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*b_best_push;
	int		command_counter;

	stack_a = NULL;
	stack_b = NULL;
	b_best_push = NULL;
	command_counter = 0;
		
	if (ft_check_input(argc, argv) == 1)
	{
		ft_create_and_fill_stack(&stack_a, argc, argv);
		ft_set_assignments(&stack_a, &stack_b);
		if (argc <= 4)
			ft_sort_three(&stack_a, &command_counter);
		else if (argc > 4 && argc <= 6)
			ft_sort_few(&stack_a, &stack_b, &command_counter);
		else
		{
			if(!ft_is_sorted(stack_a))
			{
				while (ft_list_size(stack_a) > 3)
					ft_push(&stack_b, &stack_a, "pb", &command_counter);
				ft_sort_three(&stack_a, &command_counter);
				ft_set_assignments(&stack_a, &stack_b);
				while(stack_b)
				{				
					ft_set_assignments(&stack_a, &stack_b);
					b_best_push = ft_find_best_push(&stack_b);
					ft_choose_single_commands(&stack_a, &stack_b, b_best_push, &command_counter);			
				}
				ft_send_minimum_index_to_top(&stack_a, &command_counter);
			}
		}
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
	return (0);
}

/*
		Main to use for debugging. 
		Displays the commands, the resulting stacks with all their variable values,
		and the total number of commands used.
*/
/*
int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*b_best_push;
	int		command_counter;

	stack_a = NULL;
	stack_b = NULL;
	b_best_push = NULL;
	command_counter = 0;
		
	if (ft_check_input(argc, argv) == 1)
	{
		ft_create_and_fill_stack(&stack_a, argc, argv);
		ft_set_assignments(&stack_a, &stack_b);
		if (argc <= 4)
			ft_sort_three(&stack_a, &command_counter);
		else if (argc > 4 && argc <= 6)
			ft_sort_few(&stack_a, &stack_b, &command_counter);
		else
		{
			while (ft_list_size(stack_a) > 3)
				ft_push(&stack_b, &stack_a, "pb", &command_counter);
			ft_sort_three(&stack_a, &command_counter);
			ft_set_assignments(&stack_a, &stack_b);
			while(stack_b)
			{				
				ft_set_assignments(&stack_a, &stack_b);
				b_best_push = ft_find_best_push(&stack_b);
				printf("--------------------------------------------------------------\n");
				printf("Best push in B is %d\n", b_best_push->index);
				printf("Closest upper in A is %d\n", b_best_push->closest_upper_address->index);
				ft_print_list(stack_a, 'A');
				ft_print_list(stack_b, 'B');
				ft_choose_single_commands(&stack_a, &stack_b, b_best_push, &command_counter);			
			}
			ft_send_minimum_index_to_top(&stack_a, &command_counter);
		}
	}
	ft_print_list(stack_a, 'A');
	printf("Number of commands used: %d\n", command_counter);
	return (0);
	*/