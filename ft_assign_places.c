/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_places.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 22:00:14 by ccarrace          #+#    #+#             */
/*   Updated: 2023/05/12 20:00:32 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_assign_places(t_list **lst)
{
	t_list *current;
	int	i;

	current = *lst;
	i = 1;
	while (current)
	{
		current->place = i;
		i++;
		current = current->next;
	}
}
