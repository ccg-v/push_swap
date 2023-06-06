/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_stack_variables.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 22:00:14 by ccarrace          #+#    #+#             */
/*   Updated: 2023/06/07 00:45:18 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_assign_places(t_list **lst)
{
	t_list *current;
	int	i;
	if(*lst != NULL)
	{
		current = *lst;
		i = 0;
		while (current)
		{
			current->place = i;
			i++;
			current = current->next;
		}
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

/*	
 	Initializing the 'min' variable with the maximum possible integer value
	is a common technique used in finding the minimum value in a list. When
   	you initialize the 'min' variable with INT_MAX, any other value in the
	list will be less or equal to 'min'. This means that the first value you
	compare to 'min' will always become the new minimum.
	We could also create an extra function to search for the maximum value
	in the list, and use it to initialize the 'min' variable. But obviously,
	the first solution is pretty much smart.
*/
void ft_assign_gaps(t_list **stack_a, t_list **stack_b)
{
	t_list	*a_current;
	t_list *b_current;
	int		a_size;
	int		b_size;
	
	a_current = *stack_a;
	b_current = *stack_b;
	a_size = ft_list_size(a_current);
	b_size = ft_list_size(b_current);
	while (b_current)
	{
		b_current->b_gap_to_top = b_current->place;
		if (b_current->place > b_size) 
				b_current->b_gap_to_top = (b_size - b_current->place) * -1;
		b_current->a_gap_to_top = b_current->closest_upper;
		if (b_current->closest_upper > (a_size > 2))
			b_current->a_gap_to_top = (a_size - b_current->closest_upper) * -1;
		b_current = b_current->next;
	}
}

/*
	Here we assign the closest upper that every value in stack_b has in stack_a
	and store it in the 'closest_upper' variable inside stack_b.
	We also store the gap to top of stack_a of the closest upper in the 'a_gap_to_top'
	variable inside stack_b. 
	Hence, we can easily find the best value to push in both stacks just looking
	inside stack_b:
		- the best_push will be the value whose sum of 'a_gap_to_top' and 'b_gap_to_top'
			is the smallest
		- the number of commands to push to the top the best push in a ('a_best_push')
			will be 'a_gap_to_top';
		- the number of commands to push to the top the best push in b ('b_best_push')
			will be 'b_gap_to_top';
*/

void	ft_assign_closest_upper(t_list **stack_a, t_list **stack_b)
{
	t_list	*a_node;
	t_list	*b_node;
	int		closest_upper;
//	int		a_gap_to_top;
//	int		b_gap_to_top;

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
				b_node->a_gap_to_top = a_node->a_gap_to_top;
			}
			a_node = a_node->next;
		}
		if (closest_upper == INT_MAX)
		{
			closest_upper = ft_find_min_node(stack_a)->index;
			b_node->a_gap_to_top = ft_find_min_node(stack_a)->a_gap_to_top;
		}
		b_node->closest_upper = closest_upper;
		b_node = b_node->next;	
	}
}

void	ft_set_assignments(t_list **stack_a, t_list **stack_b)
{
	if (stack_a && *stack_a != NULL)
	{
		ft_assign_places(stack_a);
		if (stack_b && *stack_b != NULL)
		{
			ft_assign_places(stack_b);
			ft_assign_gaps(stack_a, stack_b);
			ft_assign_closest_upper(stack_a, stack_b);
		}
	}
}