/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_assignments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 22:00:14 by ccarrace          #+#    #+#             */
/*   Updated: 2023/06/08 00:36:14 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_assign_places(t_list **lst)
{
	t_list *current;
	int	i;

	current = *lst;
	i = 0;
	while (current)
	{
		current->place = i;
		i++;
		current = current->next;
	}
}

void ft_assign_indexes(t_list **lst)
{
    t_list	*current;
	t_list	*min_node;
    int 	i;
	int		min;

 	current = *lst;
	min_node = NULL;
	i = 1;
    while (current && i <= ft_list_size(current))
    {
		min = INT_MAX;
		while (current)
        {
            if (current->value < min && current->index == 0)
            {
                min = current->value;
                min_node = current;
            }
            current = current->next;
        }
        min_node->index = i;
        i++;
        current = *lst;
    }
}

void	ft_assign_gaps(t_list **stack)
{
	t_list  *current;
	int	    stack_size;  
	int		gap_to_top; 

	current = *stack;
	gap_to_top = 0;
    stack_size = ft_list_size(*stack);
	while (current && (current->place <= (stack_size / 2)))
	{
		current->gap_to_top = gap_to_top++;
		current = current->next;
	}
	if (stack_size % 2 == 0)
		gap_to_top--;
	while (current && (current->place > (stack_size / 2)))
	{
		current->gap_to_top = (--gap_to_top) * -1;
		current = current->next;
	}
}

void	ft_assign_closest_upper(t_list **stack_a, t_list **stack_b)
{
	t_list	*a_node;
	t_list	*b_node;
	int		closest_upper;
	t_list	*closest_upper_address;

	closest_upper_address = NULL;
	b_node = *stack_b;
	while (b_node)
	{
		closest_upper = INT_MAX;
		a_node = *stack_a;
		while(a_node)
		{
			if (a_node->index > b_node->index && a_node->index < closest_upper)
			{
				closest_upper = a_node->index;
				closest_upper_address = a_node;
			}
			a_node = a_node->next;
		}
		if (closest_upper == INT_MAX)
		{
//			b_node->closest_upper = ft_find_min_node(stack_a)->index;
			closest_upper = ft_find_min_node(stack_a)->index;
			closest_upper_address = ft_find_min_node(stack_a);
//			a_node->closest_upper = b_node->closest_upper;
		}
		b_node->closest_upper = closest_upper;
		b_node->closest_upper_address = closest_upper_address;
		b_node = b_node->next;	
	}
}

void	ft_set_assignments(t_list **stack_a, t_list **stack_b)
{
	if (stack_a && *stack_a != NULL)
	{
		if ((*stack_a)->index == 0)
			 ft_assign_indexes(stack_a);
		ft_assign_places(stack_a);
		ft_assign_gaps(stack_b);
		if (stack_b && *stack_b != NULL)
		{
			ft_assign_places(stack_b);
			ft_assign_gaps(stack_b);
			ft_assign_closest_upper(stack_a, stack_b);
		}
	}
}
