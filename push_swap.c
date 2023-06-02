/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:16:01 by ccarrace          #+#    #+#             */
/*   Updated: 2023/06/03 01:06:02 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*b_best_to_push;
	int		command_counter;

	stack_a = NULL;
	stack_b = NULL;
	b_best_to_push = NULL;
	command_counter = 0;
		
	if (ft_check_input(argc, argv) == 1)
	{
		ft_fill_stack(&stack_a, argc, argv);
ft_print_list(stack_a, 'A');
		if (argc <= 6)
		{
			ft_sort_few(stack_a, stack_b, &command_counter);
		}
		else
		{
			while (ft_list_size(stack_a) > 3)
				ft_push(&stack_b, &stack_a, "pb", &command_counter);
			ft_sort_three(&stack_a, &command_counter);
			ft_assign_closest_upper(&stack_a, &stack_b);
			ft_assign_gaps(&stack_a);
			ft_assign_gaps(&stack_b);
/*			ft_push(&stack_a, &stack_b, "pb", &command_counter);
			ft_assign_closest_upper(&stack_a, &stack_b);
			ft_assign_gaps(&stack_a);
			ft_assign_gaps(&stack_b);
			ft_push(&stack_a, &stack_b, "pb", &command_counter);
			ft_assign_closest_upper(&stack_a, &stack_b);
			ft_assign_gaps(&stack_a);
			ft_assign_gaps(&stack_b);	*/	
		}
ft_print_list(stack_a, 'A');
ft_print_list(stack_b, 'B');
	b_best_to_push = ft_find_best_push(&stack_b);
	ft_choose_single_commands(&stack_b, &stack_a, b_best_to_push, &command_counter);
	
	ft_assign_closest_upper(&stack_b, &stack_a);
	b_best_to_push = ft_find_best_push(&stack_b);
ft_print_list(stack_a, 'A');
ft_print_list(stack_b, 'B');
printf("Best push in b is %d\n", b_best_to_push->index);
printf("Best push in a is %d\n", b_best_to_push->closest_upper_address->index);
	ft_choose_single_commands(&stack_b, &stack_a, b_best_to_push, &command_counter);
	ft_assign_closest_upper(&stack_b, &stack_a);
	b_best_to_push = ft_find_best_push(&stack_b);
ft_print_list(stack_a, 'A');
ft_print_list(stack_b, 'B');
printf("Best push in b is %d\n", b_best_to_push->index);
printf("Best push in a is %d\n", b_best_to_push->closest_upper_address->index);
	ft_choose_single_commands(&stack_b, &stack_a, b_best_to_push, &command_counter);
	ft_assign_closest_upper(&stack_b, &stack_a);
	b_best_to_push = ft_find_best_push(&stack_b);
ft_print_list(stack_a, 'A');
ft_print_list(stack_b, 'B');
printf("Best push in b is %d\n", b_best_to_push->index);
printf("Best push in a is %d\n", b_best_to_push->closest_upper_address->index);
	ft_choose_single_commands(&stack_b, &stack_a, b_best_to_push, &command_counter);
	ft_assign_closest_upper(&stack_b, &stack_a);
	b_best_to_push = ft_find_best_push(&stack_b);
ft_print_list(stack_a, 'A');
ft_print_list(stack_b, 'B');
printf("Best push in b is %d\n", b_best_to_push->index);
printf("Best push in a is %d\n", b_best_to_push->closest_upper_address->index);
	ft_choose_single_commands(&stack_b, &stack_a, b_best_to_push, &command_counter);
	ft_assign_closest_upper(&stack_b, &stack_a);
	b_best_to_push = ft_find_best_push(&stack_b);
ft_print_list(stack_a, 'A');
ft_print_list(stack_b, 'B');
printf("Best push in b is %d\n", b_best_to_push->index);
printf("Best push in a is %d\n", b_best_to_push->closest_upper_address->index);
	}
printf("Number of commands used: %d\n", command_counter);
	return (0);
}