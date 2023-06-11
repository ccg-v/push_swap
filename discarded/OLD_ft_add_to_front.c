/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:26:31 by ccarrace          #+#    #+#             */
/*   Updated: 2023/05/03 21:27:08 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_to_front(t_list **lst, int value)
{
	t_list	*new_node;

	if (!*lst)
		*lst = ft_create_node(value);
	else
	{
		new_node = ft_create_node(value);
		new_node->next = *lst;
		*lst = new_node;
	}
}
