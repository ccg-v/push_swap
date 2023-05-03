/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:28:36 by ccarrace          #+#    #+#             */
/*   Updated: 2023/05/03 22:12:26 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_list_size(t_list *lst)
{
	size_t	i;

	i = 0;
	while(lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

