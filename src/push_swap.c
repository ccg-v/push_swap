/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:16:01 by ccarrace          #+#    #+#             */
/*   Updated: 2025/06/17 01:38:45 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_simple_sort(t_list **stack_a, t_list **stack_b)
{
	int	a_stack_size;

	a_stack_size = ft_list_size(*stack_a);
	if (a_stack_size <= 3)
		ft_sort_three(stack_a);
	else if (a_stack_size > 3 && a_stack_size <= 5)
		ft_sort_few(stack_a, stack_b);
}

static void	ft_complex_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*b_best_push;

	b_best_push = NULL;
	while (ft_list_size(*stack_a) > 3)
		ft_push(stack_b, stack_a, "pb");
	ft_sort_three(stack_a);
	while (ft_list_size(*stack_b) > 0)
	{				
		ft_set_assignments(stack_a, stack_b);
		b_best_push = ft_find_best_push(stack_b);
		ft_choose_commands(stack_a, stack_b, b_best_push);
	}
	ft_send_minimum_index_to_top(stack_a);
}

static void	ft_free_array_of_strings(char **argv)
{
	int	i;

	i = 0;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

static void	free_stack(t_list **stack)
{
	t_list	*tmp;
	t_list	*current;

	if (!stack || !(*stack))
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		arg_is_quoted;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
		arg_is_quoted = ft_split_if_quoted_args(&argc, &argv);
	if (ft_check_input(argc, argv) == 1)
	{
		ft_create_and_fill_stack(&stack_a, argc, argv);
		ft_set_assignments(&stack_a, &stack_b);
		if (argc <= 5)
			ft_simple_sort(&stack_a, &stack_b);
		else if (!ft_is_sorted(stack_a))
			ft_complex_sort(&stack_a, &stack_b);
		if (arg_is_quoted == 1)
			ft_free_array_of_strings(argv);
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
	return (0);
}
