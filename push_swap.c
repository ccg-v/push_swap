/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:16:01 by ccarrace          #+#    #+#             */
/*   Updated: 2023/06/07 00:48:09 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/**/
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
		ft_create_and_fill_stack(&stack_a, argc, argv);
//ft_print_list(stack_a, 'A');
		if (argc <= 4)
			ft_sort_three(&stack_a, &command_counter);
		else if (argc > 4 && argc <= 6)
		{
			ft_sort_few(&stack_a, &stack_b, &command_counter);
//			ft_assign_gaps(&stack_a);
//			ft_assign_gaps(&stack_b);
		}
		else
		{
			while (ft_list_size(stack_a) > 3)
				ft_push(&stack_b, &stack_a, "pb", &command_counter);
			ft_sort_three(&stack_a, &command_counter);
			while(stack_b)
			{				
				ft_set_assignments(&stack_a, &stack_b);
				ft_find_best_pushes(&stack_b, &stack_b);
			}
		}
ft_print_list(stack_a, 'A');
//ft_print_list(stack_b, 'B');
	}
printf("Number of commands used: %d\n", command_counter);
	return (0);
}