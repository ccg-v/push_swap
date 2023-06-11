/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:53:47 by ccarrace          #+#    #+#             */
/*   Updated: 2023/06/11 20:45:48 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	ft_swap(t_list **stack, char *move_name, int *command_counter)
{
	t_list	*tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	if (ft_strncmp(move_name, "ss", 3) != 0)
	{
//		write(1, move_name, 3);
		ft_printf("%s\n", move_name);
		(*command_counter)++;
	}
}

void	ft_swap_both(t_list **a, t_list **b, int *command_counter)
{
	ft_swap(a, "ss\n", command_counter);
	ft_swap(b, "ss\n", command_counter);
//	write(1, "ss", 3);
	ft_printf("ss\n");
	(*command_counter)++;
}
