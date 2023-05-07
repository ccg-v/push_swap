/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:14:33 by ccarrace          #+#    #+#             */
/*   Updated: 2023/05/07 21:58:08 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <string.h>

void	ft_sort_three(t_list **stack)
{
	int	maximum_index;

	maximum_index = ft_list_size(*stack);
	if ((*stack)->index == maximum_index)
		ft_rotate(stack, "ra");
	else if	((*stack)->next->index == maximum_index)
		ft_reverse_rotate(stack, "rra");
	if (!ft_is_sorted(*stack))
		ft_swap(stack, "sa");
}

void	ft_print_list(t_list *lst)
{
	printf("\nValue\tPosit\tIndex\n");
	while (lst)
	{
		printf("%d\t%d\t%d\n", lst->value, lst->position, lst->index);
		lst = lst->next;
	}
	printf("\n");
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
	ft_assign_places(&stack_a);
	ft_index_list(&stack_a);
	ft_print_list(stack_a);
	ft_sort_three(&stack_a);
	ft_print_list(stack_a);
	return (0);
}
