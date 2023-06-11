/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:27:21 by ccarrace          #+#    #+#             */
/*   Updated: 2023/05/03 21:27:55 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_to_back(t_list **lst, int value)
{
	t_list	*old_tail;
	t_list	*new_tail;
	t_list	*current;

	if (!*lst)
		*lst = ft_create_node(value);
	else
	{
		current = *lst;
		new_tail = ft_create_node(value);
		while (current->next)
			current = current->next;
		old_tail = current;
		old_tail->next = new_tail;
	}
}
