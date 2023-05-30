/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:31:22 by ccarrace          #+#    #+#             */
/*   Updated: 2023/05/30 20:04:41 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_list(t_list *lst, char stack_name)
{
	printf("\n%c:\tVALUE\tPlace\tIndex\tUpper\tGapTop\tGapBot\n", stack_name);
	while (lst)
	{
		printf("\t%d\t%d\t%d\t%d\t%d\t%d\n", lst->value, lst->place, lst->index, lst->closest_upper, lst->gap_to_top, lst->gap_to_bottom);
		lst = lst->next;
	}
	printf("\n");
}

t_list	*ft_find_max_node(t_list **lst)
{
	t_list	*max_node;
	t_list	*current_node;

	max_node = *lst;
	current_node = (*lst)->next;
	while (current_node)
	{
		if (current_node->value > max_node->value)
			max_node = current_node;
		current_node = current_node->next;
	}
	return (max_node);
}

t_list	*ft_find_min_node(t_list **lst)
{
	t_list	*min_node;
	t_list	*current_node;

	min_node = *lst;
	current_node = (*lst)->next;
	while (current_node)
	{
		if (current_node->value < min_node->value)
			min_node = current_node;
		current_node = current_node->next;
	}
	return (min_node);
}