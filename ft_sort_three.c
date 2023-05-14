/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:14:33 by ccarrace          #+#    #+#             */
/*   Updated: 2023/05/14 11:41:19 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <string.h>

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

int	ft_sort_three(t_list **stack, int movements)
{
	t_list	*max_node;

	if (!ft_is_sorted(*stack))
	{
		max_node = ft_find_max(stack);
		if ((*stack)->index == max_node->index)
			ft_rotate(stack, "ra", movements);
		else if	((*stack)->next->index == max_node->index)
			ft_reverse_rotate(stack, "rra", movements);
		if (!ft_is_sorted(*stack))
			ft_swap(stack, "sa", movements);
	}
	return (movements);
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
/*
void	ft_send_minimum_index_to_top(t_list **stack)
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
			ft_rotate(stack, "ra");
			distance_to_top--;
		}
	}
	else if(distance_to_bottom < distance_to_top)
	{
		while(distance_to_bottom > 0)
		{
			ft_reverse_rotate(stack, "rra");
			distance_to_bottom--;
		}
	}
}
*/
int	ft_send_minimum_index_to_top(t_list **stack, int movements)
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
			ft_rotate(stack, "ra", movements);
			distance_to_top--;
		}
	}
	else if(distance_to_bottom < distance_to_top)
	{
		while(distance_to_bottom > 0)
		{
			ft_reverse_rotate(stack, "rra", movements);
			distance_to_bottom--;
		}
	}
	return (movements);
}
void	ft_print_list(t_list *lst, char stack_name)
{
	printf("\n%c:\tValue\tPlace\tIndex\n", stack_name);
	while (lst)
	{
		printf("\t%d\t%d\t%d\n", lst->value, lst->place, lst->index);
		lst = lst->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_list	*stack_a = NULL;
	t_list	*stack_b = NULL;
	int		i ;
	int		movements;
	
	i = 1;
	movements = 0;
	while (i < argc)
	{
		ft_add_to_back(&stack_a, atoi(argv[i]));
		i++;
	}
	ft_assign_places(&stack_a);
	ft_index_list(&stack_a);
	while(ft_list_size(stack_a) > 3)
	{
		ft_send_minimum_index_to_top(&stack_a, movements);
		ft_push(&stack_b, &stack_a, "pb", movements);
	}	
	ft_sort_three(&stack_a, movements);	
	while(ft_list_size(stack_b) > 0)
		ft_push(&stack_a, &stack_b, "pa", movements);
	ft_print_list(stack_a, 'A');
printf("Number of movements = %d\n", movements);
	return (0);
}