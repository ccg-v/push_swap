/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_dist_to_right_place.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:49:14 by ccarrace          #+#    #+#             */
/*   Updated: 2023/05/21 17:52:38 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	-- Function to fill part the STACK DATA --
	This function loops to calculat the distance of each node to its correct
	place and store it in the 'dist_to_right_place' variable of the struct
*/

void ft_assign_dist_to_right_place(t_list **lst)
{
	t_list	*current;
	
	current = *lst;
	while (current)
	{
		current->dist_to_right_place = current->index - current->place;
		current = current->next;
	}
}