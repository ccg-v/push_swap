/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_positions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 22:00:14 by ccarrace          #+#    #+#             */
/*   Updated: 2023/05/03 22:01:16 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_assign_positions(t_list **lst)
{
	t_list *current;
	int	i;

	current = *lst;
	i = 1;
	while (current)
	{
		current->position = i;
		i++;
		current = current->next;
	}
}
