/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_complex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:42:08 by ccarrace          #+#    #+#             */
/*   Updated: 2023/06/01 23:26:44 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

t_list	*ft_find_farthest_node(t_list **lst)
{
	t_list	*current;
	t_list	*farthest;
	int		stack_size;
	int		i;

	stack_size = ft_list_size(*lst);
	current = *lst;
	farthest = current;
	i = 0;
	while (i < stack_size)
	{
		if (ft_abs(current->dist_to_right_place) > ft_abs(farthest->dist_to_right_place))
			farthest = current;
		else if (ft_abs(current->dist_to_right_place) == ft_abs(farthest->dist_to_right_place) && current->dist_to_right_place < 0)
		{
			if (current->dist_to_right_place > farthest->dist_to_right_place)
				farthest = current;
		}
		current = current->next;
		i++;
	}
	return(farthest);
}

void	ft_move_to_top_farthest(t_list **stack, int *command_counter)
{
	t_list	*farthest;
	int		stack_size;
	
	stack_size = ft_list_size(*stack);
	farthest = ft_find_farthest_node(stack);
	while (farthest->place != 1)
	{
		if (farthest->place > stack_size / 2)
			ft_reverse_rotate(stack, "rra", command_counter);
		else if (farthest->place <= (stack_size / 2))
			ft_rotate(stack, "ra", command_counter);
	}
}

void	ft_split_stack_in_two(t_list **stack_a, t_list **stack_b, int *command_counter)
{
	t_list	**current_node;
	int		stack_size;
	int		i;

	current_node = stack_a;
	stack_size = ft_list_size(*stack_a);
	i = 0;
	while(i < stack_size)
	{
		if((*current_node)->index <= (stack_size / 2))
			ft_push(stack_b, stack_a, "pb", command_counter);
		else
			ft_rotate(stack_a, "ra", command_counter);
		i++;
	}
	ft_assign_gaps(stack_a);
	ft_assign_gaps(stack_b);
}

void	ft_assign_closest_upper(t_list **stack_a, t_list **stack_b)
{
	t_list	*a_node;
	t_list	*b_node;
	int		closest_upper;
	t_list	*address;

	b_node = *stack_b;
	while (b_node)
	{
		closest_upper = INT_MAX;
		a_node = *stack_a;
//address = b_node;
//printf("node %d address is %p\n", address->value, address);
		while(a_node)
		{
			if (a_node->index > b_node->index && a_node->index < closest_upper)
			{
				closest_upper = a_node->index;
				address = a_node;
			}
			a_node = a_node->next;
		}
		if (closest_upper == INT_MAX)
		{
			b_node->closest_upper = ft_find_min_node(stack_a)->index;
			address = ft_find_min_node(stack_a);
		}
		b_node->closest_upper = closest_upper;
		b_node->address = address;
		b_node = b_node->next;	
	}
}

/*
void	ft_assign_closest_upper(t_list **stack_a, t_list **stack_b)
{
	t_list	*a_node;
	t_list	*b_node;
	int	closest_upper;

	b_node = *stack_b;
	while (b_node)
	{
		closest_upper = INT_MAX;
		a_node = *stack_a;
		while(a_node)
		{
			if (a_node->index > b_node->index && a_node->index < closest_upper)
				closest_upper = a_node->index;
			a_node = a_node->next;
		}
		if (closest_upper == INT_MAX)
			closest_upper = (ft_find_min_node(stack_a))->index;
		b_node->closest_upper = closest_upper;
		b_node = b_node->next;	
	}
}

void	ft_choose_best_push(t_list **stack_a, t_list **stack_b)
{

}
*/

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