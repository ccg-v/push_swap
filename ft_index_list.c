/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 22:06:20 by ccarrace          #+#    #+#             */
/*   Updated: 2023/05/23 19:54:18 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_index_list(t_list **lst)
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
