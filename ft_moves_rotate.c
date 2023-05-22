/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:53:47 by ccarrace          #+#    #+#             */
/*   Updated: 2023/05/23 00:06:44 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	OJO!!! TENGO QUE SUSTITUIR strncmp POR MI PROPIA FUNCION DE LIBFT!!!!!!!!!!

void	ft_rotate(t_list **stack, char *move_name, int *command_counter)
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
	ft_assign_places(stack);
	ft_assign_dist_to_right_place(stack);
	if (strncmp(move_name, "rr", 3) != 0)
	{
		write(1, move_name, 3);
		write(1, "\n", 1);
		(*command_counter)++;
	}
}

void	ft_rotate_both(t_list **a, t_list **b, int *command_counter)
{
	ft_rotate(a, "rr", command_counter);
	ft_rotate(b, "rr", command_counter);
	write(1, "rr\n", 3);
	(*command_counter)++;
}
/*
void	ft_print_both(t_list *lst_a, t_list *lst_b)
{
	printf("\nA\tB\n");
	printf("---------\n");
	while (lst_a || lst_b)
	{
		printf("%d\t%d\n", lst_a->value, lst_b->value);
		lst_a = lst_a->next;
		lst_b = lst_b->next;
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
	int		command_counter = 0;

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
	ft_add_to_back(&stack_b, b_first);
	ft_add_to_back(&stack_b, b_second);
	ft_add_to_back(&stack_b, b_third);
	ft_add_to_back(&stack_b, b_last);
	ft_print_both(stack_a, stack_b);
	ft_rotate(&stack_a, "ra", &command_counter);
	ft_print_both(stack_a, stack_b);
	ft_rotate(&stack_b, "rb", &command_counter);
	ft_print_both(stack_a, stack_b);	
	ft_rotate_both(&stack_a, &stack_b, &command_counter);
	ft_print_both(stack_a, stack_b);
	return (0);
}*/
