/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_and_fill_stack.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:25:40 by ccarrace          #+#    #+#             */
/*   Updated: 2023/06/15 00:24:11 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_create_node(int num)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = num;
	node->place = 0;
	node->index = 0;
	node->gap_to_top = 0;
	node->closest_upper = 0;
	node->closest_upper_address = NULL;
	node->next = NULL;
	return (node);
}

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

void	ft_create_and_fill_stack(t_list **stack_a, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		ft_add_to_back(stack_a, ft_atoi(argv[i]));
		i++;
	}
}
