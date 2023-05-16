/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_complex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:42:08 by ccarrace          #+#    #+#             */
/*   Updated: 2023/05/17 00:06:30 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
t_list	*ft_find_max(t_list **lst)
{
	t_list	*max_node;
	t_list	*current_node;

	max_node = *lst;
	current_node = (*lst)->next;
	while (current_node)
	{
		if (current_node->value > max_node->value)
			max_node = current_node;
		current_node = current_node->next;
	}
	return (max_node);
}

t_list	*ft_find_min(t_list **lst)
{
	t_list	*min_node;
	t_list	*current_node;

	min_node = *lst;
	current_node = (*lst)->next;
	while (current_node)
	{
		if (current_node->value < min_node->value)
			min_node = current_node;
		current_node = current_node->next;
	}
	return (min_node);
}

void	ft_send_minimum_index_to_top(t_list **stack, int *command_counter)
{
	t_list	*min_node;
	int		stack_len;
	int		distance_to_top;
	int		distance_to_bottom;

	min_node = ft_find_min(stack);
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
*/
static void	ft_print_list(t_list *lst, char stack_name)
{
	printf("\n%c:\tValue\tPlace\tIndex\n", stack_name);
	while (lst)
	{
		printf("\t%d\t%d\t%d\n", lst->value, lst->place, lst->index);
		lst = lst->next;
	}
	printf("\n");
}

void	ft_sort_complex(t_list **stack_a, t_list **stack_b, int *command_counter)
{
	t_list	*current_node;
	int		mid_value;

	current_node = *stack_a;
	mid_value = ft_list_size(*stack_a) / 2;
printf("mid_value = %d\n", mid_value);
	while(current_node)
	{
		if(current_node->index >= mid_value)
			ft_push(stack_b, stack_a, "pb", command_counter);
		else
			ft_rotate(stack_a, "ra", command_counter);
		current_node = current_node->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a = NULL;
	t_list	*stack_b = NULL;
	int		i ;
	int		command_counter;

	i = 1;
	command_counter = 0;
	if (ft_check_input(argc, argv) == 1)
	{
		while (i < argc)
		{
			ft_add_to_back(&stack_a, atoi(argv[i]));
			i++;
		}
		ft_assign_places(&stack_a);
		ft_index_list(&stack_a);
		ft_sort_complex(&stack_a, &stack_b, &command_counter);
/*		while(ft_list_size(stack_a) > 3)
		{
			ft_send_minimum_index_to_top(&stack_a, &command_counter);
			ft_push(&stack_b, &stack_a, "pb", &command_counter);
		}	
		ft_sort_three(&stack_a, &command_counter);
		while(ft_list_size(stack_b) > 0)
			ft_push(&stack_a, &stack_b, "pa", &command_counter);*/
		ft_print_list(stack_a, 'A');
		ft_print_list(stack_b, 'B');
	}
printf("Number of commands used: %d\n", command_counter);
	return (0);
}