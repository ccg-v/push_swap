/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:53:47 by ccarrace          #+#    #+#             */
/*   Updated: 2023/05/23 00:00:08 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack, char *move_name, int *command_counter)
{
	t_list	*tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	if (strncmp(move_name, "ss", 3) != 0)
	{
		write(1, move_name, 3);
		write(1, "\n", 1);
		(*command_counter)++;
	}
	ft_assign_places(stack);
	ft_assign_dist_to_right_place(stack);
}

void	ft_swap_both(t_list **a, t_list **b, int *command_counter)
{
	ft_swap(a, "ss", command_counter);
	ft_swap(b, "ss", command_counter);
	write(1, "ss", 3);
	write(1, "\n", 1);
	(*command_counter)++;
}

/*
void	ft_print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d ", lst->value);
		lst = lst->next;
	}
	printf("\n");
}

int	main(void)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		a_first;
	int		a_second;
	int		a_third;
	int		a_last;
	int		b_first;
	int		b_second;
	int		b_third;
	int		b_last;

	a_first = 1;
	a_second = 2;
	a_third = 3;
	a_last = 4;
	b_first = 5;
	b_second = 6;
	b_third = 7;
	b_last = 8;
	stack_a = ft_create_node(a_first);
	stack_a->next = ft_create_node(a_second);
	stack_a->next->next = ft_create_node(a_third);
	stack_a->next->next->next = ft_create_node(a_last);
	ft_print_list(stack_a);
	ft_add_to_back(&stack_b, b_first);
	ft_add_to_back(&stack_b, b_second);
	ft_add_to_back(&stack_b, b_third);
	ft_add_to_back(&stack_b, b_last);
	ft_print_list(stack_b);
	ft_swap(&stack_a, "sa");
	ft_print_list(stack_a);
	ft_swap(&stack_b, "sb");
	ft_print_list(stack_b);	
	ft_swap_both(&stack_a, &stack_b);
	ft_print_list(stack_a);
	ft_print_list(stack_b);	
	return (0);
}
*/
