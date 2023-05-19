/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_complex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:42:08 by ccarrace          #+#    #+#             */
/*   Updated: 2023/05/20 00:41:02 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_list(t_list *lst, char stack_name)
{
	printf("\n%c:\tValue\tPlace\tIndex\n", stack_name);
	while (lst)
	{
		printf("\t%d\t%d\t%d\n", lst->value, lst->place, lst->index);
		lst = lst->next;
	}
	printf("\n");
}

void	ft_sort_complex(t_list **stack_a, t_list **stack_b, int *command_counter)
{
	t_list	**current_node;
	int		stack_size;
	int		i;

	current_node = stack_a;
	stack_size = ft_list_size(*stack_a);
	i = 0;
	while(i < stack_size)
	{
		if((*current_node)->index <= (stack_size / 2))
			ft_push(stack_b, stack_a, "pb", command_counter);
		else
			ft_rotate(stack_a, "ra", command_counter);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a = NULL;
	t_list	*stack_b = NULL;
	int		i ;
	int		command_counter;

	i = 1;
	command_counter = 0;
	if (ft_check_input(argc, argv) == 1)
	{
		while (i < argc)
		{
			ft_add_to_back(&stack_a, atoi(argv[i]));
			i++;
		}
		ft_assign_places(&stack_a);
		ft_index_list(&stack_a);
		ft_sort_complex(&stack_a, &stack_b, &command_counter);
		ft_print_list(stack_a, 'a');
		ft_print_list(stack_a, 'b');
		ft_sort_three(&stack_a, &command_counter);
		ft_sort_three(&stack_b, &command_counter);
		ft_print_list(stack_a, 'A');
		ft_print_list(stack_b, 'B');
	}
printf("Number of commands used: %d\n", command_counter);
	return (0);
}