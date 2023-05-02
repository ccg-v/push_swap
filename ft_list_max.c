/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:04:03 by ccarrace          #+#    #+#             */
/*   Updated: 2023/04/25 22:23:43 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_list_max(t_list **lst)
{
	t_list	*max_node;
	t_list	*current_node;

	max_node = *lst;
	current_node = (*lst)->next;
	while (current_node)
	{
//		if (current_node->value[0] > max_node->value[0])
		if (*(current_node->value) > *(max_node->value))
			max_node = current_node;
		current_node = current_node->next;
	}
	return (max_node);
}

/*
 	The syntax (*lst)->value[0] is used to dereference the value pointer
	inside the t_list struct, and access the first element of the int 
	array that it points to.
	In this particular case, we're assuming that value points to an array 
	of size 1, so we only need to access the first element. That's why we 
	use [0].
*/
