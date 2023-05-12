/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:14:33 by ccarrace          #+#    #+#             */
/*   Updated: 2023/05/13 01:28:43 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <string.h>

void	ft_sort_three(t_list **stack)
{
	int	maximum_index;

	maximum_index = ft_list_size(*stack);
	if ((*stack)->index == maximum_index)
		ft_rotate(stack, "ra");
	else if	((*stack)->next->index == maximum_index)
		ft_reverse_rotate(stack, "rra");
	if (!ft_is_sorted(*stack))
		ft_swap(stack, "sa");
}
/*
void	ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;
	int		maximum_index;
	
	*stack_b = NULL;
	current = *stack_a;
	maximum_index = ft_list_size(*stack_a);
	while(current->index != maximum_index)
		current = current->next;
	if(current->place == 2)
		ft_rotate(stack_a, "ra");
	else if(current->place == 3)
	{
		ft_rotate(stack_a, "ra");
		ft_rotate(stack_a, "ra");
	}
	else if(current->place == 4)
	{
		ft_reverse_rotate(stack_a, "rra");
		ft_reverse_rotate(stack_a, "rra");
	}
	else if(current->place == 5)
		ft_reverse_rotate(stack_a, "rra");
	ft_push(stack_b, stack_a, "pb");
	ft_sort_three(stack_a);
	ft_push(stack_a, stack_b, "pa");
	ft_push(stack_a, stack_b, "pa");
}
*/

void	ft_send_minimum_index_to_top(t_list **stack)
{
	t_list	*current;
	
	current = *stack;
	while(current->index != 1)
		current = current->next;
	printf("Minimum value: %d\n", current->value);
	printf("Minimum place: %d\n", current->place);
	printf("Minimum index: %d\n", current->index);
	if(current->place == 2)
		ft_rotate(stack, "ra");
	else if(current->place == 3)
	{
		ft_rotate(stack, "ra");
		ft_rotate(stack, "ra");
	}
	else if(current->place == 4)
	{
		ft_reverse_rotate(stack, "rra");
		ft_reverse_rotate(stack, "rra");
	}
	else if(current->place == 5)
		ft_reverse_rotate(stack, "rra");	
}

void	ft_print_list(t_list *lst)
{
	printf("\nValue\tPlace\tIndex\n");
	while (lst)
	{
		printf("%d\t%d\t%d\n", lst->value, lst->place, lst->index);
		lst = lst->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_list	*stack_a = NULL;
	t_list	*stack_b = NULL;

	int		i = 1;

	while (i < argc)
	{
		ft_add_to_back(&stack_a, atoi(argv[i]));
		i++;
	}
	ft_assign_places(&stack_a);
	ft_index_list(&stack_a);
	ft_print_list(stack_a);
//	ft_sort_three(&stack_a);
//	ft_sort_five(&stack_a, &stack_b);
	if (argc == 6)
	{
		ft_send_minimum_index_to_top(&stack_a);
		ft_push(&stack_b, &stack_a, "pb");
		ft_send_minimum_index_to_top(&stack_a);
		ft_push(&stack_b, &stack_a, "pb");
	}
	ft_print_list(stack_a);
	return (0);
}
