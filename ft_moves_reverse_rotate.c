/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_reverse_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:53:47 by ccarrace          #+#    #+#             */
/*   Updated: 2023/05/07 00:29:10 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_list **stack, char *move_name)
{
	t_list	*current;
	t_list	*old_head;
	t_list	*new_head;
	t_list	*new_tail;

	old_head = *stack;
	new_head = NULL;
	new_tail = NULL;
	current = *stack;
	while (current->next)
	{
		new_tail = current;
		current = current->next;
	}
	new_head = current;
	*stack = new_head;
	new_head->next = old_head;
	new_tail->next = NULL;
	if (strncmp(move_name, "rrr", 3))
	{
		write(1, move_name, 3);
		write(1, "\n", 1);
	}
}

void	ft_reverse_rotate_both(t_list **stack_a, t_list **stack_b)
{
	ft_reverse_rotate(stack_a, "rrr");
	ft_reverse_rotate(stack_b, "rrr");
	write(1, "rrr", 3);
	write(1, "\n", 1);
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
	ft_reverse_rotate(&stack_a, "rra");
	ft_print_list(stack_a);
	ft_reverse_rotate(&stack_b, "rrb");
	ft_print_list(stack_b);	
	ft_reverse_rotate_both(&stack_a, &stack_b);
	ft_print_list(stack_a);
	ft_print_list(stack_b);	
	return (0);
}
*/
