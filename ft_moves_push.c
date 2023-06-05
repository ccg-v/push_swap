/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:53:47 by ccarrace          #+#    #+#             */
/*   Updated: 2023/06/06 01:36:58 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list **dst, t_list **src, char *move_name, int *command_counter)
{
	t_list	*tmp;

	if (*src)
	{
		tmp = *src;
		*src = (*src)->next;
		tmp->next = *dst;
		*dst = tmp;
tmp->closest_upper = 0;
	}
	ft_assign_places(src);
	ft_assign_places(dst);
	ft_assign_gaps(dst);
	ft_assign_gaps(src);
//	ft_assign_closest_upper(src, dst); --> causes SEGFAULT
//	ft_putstr_fd(move_name, 1);
	printf("%s\n", move_name);
	(*command_counter)++; 
}
/*
static void	ft_print_lst(t_list *lst)
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
	int 	command_counter = 0;

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
	ft_print_lst(stack_a);
	ft_add_to_back(&stack_b, b_first);
	ft_add_to_back(&stack_b, b_second);
	ft_add_to_back(&stack_b, b_third);
	ft_add_to_back(&stack_b, b_last);
	stack_b->next = ft_create_node(b_second);
	stack_b->next->next = ft_create_node(b_third);
	stack_b->next->next->next = ft_create_node(b_last);
	ft_print_lst(stack_b);
	ft_push(&stack_a, &stack_b, "pa", &command_counter);
	ft_print_lst(stack_a);
	ft_print_lst(stack_b);
	ft_push(&stack_b, &stack_a, "pb", &command_counter);
	ft_print_lst(stack_a);
	ft_print_lst(stack_b);
	return (0);
}
*/

