/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:53:47 by ccarrace          #+#    #+#             */
/*   Updated: 2023/05/06 23:12:41 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **stack, char *move_name)
{
	t_list	*head;
	t_list	*tail;
	t_list	*tmp;

	tail = NULL;
	head = *stack;
	tmp = head;
	*stack = head->next;
	while (tmp->next)
		tmp = tmp->next;
	tail = tmp;
	tail->next = head;
	head->next = NULL;
	if (strncmp(move_name, "rr", 3))
	{
		write(1, move_name, 3);
		write(1, "\n", 1);
	}
}

void	ft_rotate_all(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(*stack_a, "rr");
	ft_rotate(*stack_b, "rr");
	write(1, "rr", 3);
	write(1, "\n", 1);
}


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
	stack_b = ft_create_node(b_first);
	stack_b->next = ft_create_node(b_second);
	stack_b->next->next = ft_create_node(b_third);
	stack_b->next->next->next = ft_create_node(b_last);
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