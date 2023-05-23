/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_gaps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:04:17 by ccarrace          #+#    #+#             */
/*   Updated: 2023/05/23 21:19:41 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_assign_gaps(t_list **stack)
{
	t_list  *current;
	int	    stack_size;   

	current = *stack;
    stack_size = ft_list_size(*stack);
	while (current)
	{
		current->gap_to_top = current->place - 1;
        current->gap_to_bottom = stack_size - current->place;
		current = current->next;
	}
}
