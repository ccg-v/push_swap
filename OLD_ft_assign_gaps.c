/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_gaps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:04:17 by ccarrace          #+#    #+#             */
/*   Updated: 2023/05/31 22:57:16 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_assign_gaps(t_list **stack)
{
	t_list  *current;
	int	    stack_size;  
	int		gap_to_top; 

	current = *stack;
	gap_to_top = 0;
    stack_size = ft_list_size(*stack);
/*	while (current)
	{
		if (current->place <= (stack_size / 2))
			current->gap_to_top = gap_to_top++;
		else if (current->place > (stack_size / 2))
			current->gap_to_top = gap_to_top--;
		current = current->next;
	}
*/
	while (current && (current->place <= (stack_size / 2)))
	{
		current->gap_to_top = gap_to_top++;
		current = current->next;
	}
//	gap_to_top++;
	while (current && (current->place > (stack_size / 2)))
	{
		current->gap_to_top = (--gap_to_top) * -1;
		current = current->next;
	}
}
