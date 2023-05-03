/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:14:33 by ccarrace          #+#    #+#             */
/*   Updated: 2023/05/03 22:49:45 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <string.h>

void	ft_sort_three(t_list **a)
{
	if ((*a)->index == 1 && (*a)->next->index == 3)
	{
		write(1, "swap\n", 5);
		write(1, "rotate\n", 7);
	}
	if ((*a)->index == 2)
	{
		if ((*a)->next->index == 1)
			write(1, "swap\n", 5);
		else
			write(1, "reverse rotate\n", 15);
	}
	if ((*a)->index == 3)
	{
		write(1, "rotate\n", 7);
		if ((*a)->next->index == 2)
			write(1, "swap\n", 5);
	}
}

void	ft_print_list(t_list *lst)
{
	printf("Value\tPosit\tIndex\n");
	while (lst)
	{
		printf("%d\t%d\t%d\n", lst->value, lst->position, lst->index);
		lst = lst->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a = NULL;
	int		i = 1;

	while (i < argc)
	{
		ft_add_to_back(&stack_a, atoi(argv[i]));
		i++;
	}
	ft_assign_positions(&stack_a);
	ft_index_list(&stack_a);
	ft_print_list(stack_a);
	ft_sort_three(&stack_a);
	return (0);
}
