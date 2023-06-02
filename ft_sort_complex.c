/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_complex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:42:08 by ccarrace          #+#    #+#             */
/*   Updated: 2023/06/03 01:00:17 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

void	ft_assign_gaps(t_list **stack)
{
	t_list  *current;
	int	    stack_size;  
	int		gap_to_top; 

	current = *stack;
	gap_to_top = 0;
    stack_size = ft_list_size(*stack);
	while (current && (current->place <= (stack_size / 2)))
	{
		current->gap_to_top = gap_to_top++;
		current = current->next;
	}
	if (stack_size % 2 == 0)
		gap_to_top--;
	while (current && (current->place > (stack_size / 2)))
	{
		current->gap_to_top = (--gap_to_top) * -1;
		current = current->next;
	}
}

void	ft_assign_closest_upper(t_list **stack_a, t_list **stack_b)
{
	t_list	*a_node;
	t_list	*b_node;
	int		closest_upper;
	t_list	*closest_upper_address;

	b_node = *stack_b;
	while (b_node)
	{
		closest_upper = INT_MAX;
		a_node = *stack_a;
		while(a_node)
		{
			if (a_node->index > b_node->index && a_node->index < closest_upper)
			{
				closest_upper = a_node->index;
				closest_upper_address = a_node;
			}
			a_node = a_node->next;
		}
		if (closest_upper == INT_MAX)
		{
			b_node->closest_upper = ft_find_min_node(stack_a)->index;
			closest_upper_address = ft_find_min_node(stack_a);
		}
		b_node->closest_upper = closest_upper;
		b_node->closest_upper_address = closest_upper_address;
		b_node = b_node->next;	
	}
}

t_list	*ft_find_best_push(t_list **stack_b)
{
	t_list *b_node;
	int	lowest_sum_of_gaps;
	int	current_sum_of_gaps;
	t_list	*best_push_address;

	b_node = *stack_b;
	lowest_sum_of_gaps = INT_MAX;
	while (b_node) 
	{
		current_sum_of_gaps = (ft_abs(b_node->gap_to_top) + ft_abs(b_node->closest_upper_address->gap_to_top));
		if (current_sum_of_gaps < lowest_sum_of_gaps)
		{
			lowest_sum_of_gaps = current_sum_of_gaps;
			best_push_address = b_node;
		}
		if (current_sum_of_gaps == 0 || current_sum_of_gaps == ft_abs(1))
			return(best_push_address);
		else
			b_node = b_node->next;
	}
	return(best_push_address);
}

void	ft_choose_single_commands(t_list **stack_a, t_list **stack_b, t_list *b_best_push, int *command_counter)
{
	t_list	*a_best_push;
	int		i;

	i = 0;
	a_best_push = b_best_push->closest_upper_address;
	if (a_best_push->gap_to_top == 0 && b_best_push->gap_to_top == 0)
	{
		ft_push(stack_b, stack_a, "pa", command_counter);
		return ;
	}
	else if (a_best_push->gap_to_top == 0 && b_best_push->gap_to_top > 0)
	{
		printf("----- case 1 -----\n");	
		while (++i <= ft_abs(b_best_push->gap_to_top))
			ft_rotate(stack_b, "rb", command_counter);
	}
	else if (a_best_push->gap_to_top == 0 && b_best_push->gap_to_top < 0)
	{
		printf("----- case 2 -----\n");
		while (++i <= ft_abs(b_best_push->gap_to_top))
			ft_reverse_rotate(stack_b, "rrb", command_counter);
	}
	else if (a_best_push->gap_to_top > 0 && b_best_push->gap_to_top == 0)
	{
		printf("----- case 3 -----\n");
		while (++i <= ft_abs(a_best_push->gap_to_top))
			ft_rotate(stack_a, "ra", command_counter);
	}
	else if (a_best_push->gap_to_top < 0 && b_best_push->gap_to_top == 0)
	{
		printf("----- case 4 -----\n");
		while (++i <= ft_abs(a_best_push->gap_to_top))
			ft_reverse_rotate(stack_a, "rra", command_counter);
	}
	else if (a_best_push->gap_to_top > 0 && b_best_push->gap_to_top < 0)
	{
		printf("----- case 5 -----\n");	
		while (++i <= ft_abs(a_best_push->gap_to_top))
			ft_rotate(stack_a, "ra", command_counter);
		while (++i <= ft_abs(b_best_push->gap_to_top))
			ft_reverse_rotate(stack_b, "rrb", command_counter);	
						
	}
	else if (a_best_push->gap_to_top < 0 && b_best_push->gap_to_top > 0)
	{
		printf("----- case 6 -----\n");	
		while (++i <= ft_abs(b_best_push->gap_to_top))
			ft_rotate(stack_b, "rb", command_counter);
		while (++i <= ft_abs(a_best_push->gap_to_top))
			ft_reverse_rotate(stack_a, "rra", command_counter);
					
	}
	printf("----- final push -----\n");	
	ft_push(stack_b, stack_a, "pa", command_counter);		
}

/*
int	main(int argc, char **argv)
{
	t_list	*stack_a = NULL;
	t_list	*stack_b = NULL;
	int		i ;
	int		command_counter;
	int		stack_size;

	i = 1;
	command_counter = 0;
	if (ft_check_input(argc, argv) == 1)
	{
		while (i < argc)
		{
			ft_add_to_back(&stack_a, atoi(argv[i]));
			i++;
		}
		stack_size = ft_list_size(stack_a);
		ft_index_list(&stack_a);
		ft_assign_places(&stack_a);
		ft_assign_dist_to_right_place(&stack_a);
		ft_assign_gaps(&stack_a);
//get_target_position(&stack_a, &stack_b);
ft_print_list(stack_a, 'a');
ft_print_list(stack_b, 'b');
		ft_split_stack_in_two(&stack_a, &stack_b, &command_counter);

printf("----------------------------------------\n");
//push_all_save_three(&stack_a, &stack_b, &command_counter);
//		while (ft_is_sorted(stack_a) == 0)
//		{
//			ft_move_to_top_farthest(&stack_a, &command_counter);
//			if (!ft_is_sorted(stack_a))
//			{
//				ft_push(&stack_b, &stack_a, "pb", &command_counter);
//				if (!ft_is_sorted(stack_a))
//					ft_swap_both(&stack_b, &stack_a, &command_counter);
//			}
//		}
ft_print_list(stack_a, 'a');
ft_print_list(stack_b, 'b');
printf("----------------------------------------\n");
//		ft_sort_three(&stack_a, &command_counter);
//		ft_sort_three(&stack_b, &command_counter);
//		ft_print_list(stack_a, 'A');
//		ft_print_list(stack_b, 'B');
	}
printf("Number of commands used: %d\n", command_counter);
	return (0);
}*/