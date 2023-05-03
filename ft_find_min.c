/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:04:03 by ccarrace          #+#    #+#             */
/*   Updated: 2023/05/03 21:07:07 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_find_min(t_list **lst)
{
	t_list	*min_node;
	t_list	*current_node;

	min_node = *lst;
	current_node = (*lst)->next;
	while (current_node)
	{
		if (*(current_node->value) < *(min_node->value))
			min_node = current_node;
		current_node = current_node->next;
	}
	return (min_node);
}

/*
 	The syntax (*lst)->value[0] is used to dereference the value pointer
	inside the t_list struct, and access the first element of the int 
	array that it points to.
	In this particular case, we're assuming that value points to an array 
	of size 1, so we only need to access the first element. That's why we 
	use [0].
*/
