/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 12:27:40 by ccarrace          #+#    #+#             */
/*   Updated: 2023/05/07 18:30:31 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp->next)
	{
		if ((tmp->next->index) - tmp->index != 1)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

/*
int	main(int argc, char **argv)
{
	t_list	*stack_a = NULL;

	int		i = 1;
	while (i < argc)
	{
		ft_add_to_back(&stack_a, atoi(argv[i]));
		i++;
	}
	ft_index_list(&stack_a);
	if (ft_is_sorted(stack_a) == 0)
		write(1, "Not sorted!\n", 12);
	else
		write(1, "Sorted!\n", 8);
	return (0);
}
*/
