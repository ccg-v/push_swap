/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_complex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:42:08 by ccarrace          #+#    #+#             */
/*   Updated: 2023/05/30 00:25:56 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

t_list	*ft_find_farthest_node(t_list **lst)
{
	t_list	*current;
	t_list	*farthest;
	int		stack_size;
	int		i;

	stack_size = ft_list_size(*lst);
	current = *lst;
	farthest = current;
	i = 0;
	while (i < stack_size)
	{
		if (ft_abs(current->dist_to_right_place) > ft_abs(farthest->dist_to_right_place))
			farthest = current;
		else if (ft_abs(current->dist_to_right_place) == ft_abs(farthest->dist_to_right_place) && current->dist_to_right_place < 0)
		{
			if (current->dist_to_right_place > farthest->dist_to_right_place)
				farthest = current;
		}
		current = current->next;
		i++;
	}
	return(farthest);
}

void	ft_move_to_top_farthest(t_list **stack, int *command_counter)
{
	t_list	*farthest;
	int		stack_size;
	
	stack_size = ft_list_size(*stack);
	farthest = ft_find_farthest_node(stack);
	while (farthest->place != 1)
	{
		if (farthest->place > stack_size / 2)
			ft_reverse_rotate(stack, "rra", command_counter);
		else if (farthest->place <= (stack_size / 2))
			ft_rotate(stack, "ra", command_counter);
	}
}

void	ft_split_stack_in_two(t_list **stack_a, t_list **stack_b, int *command_counter)
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
	ft_assign_gaps(stack_a);
	ft_assign_gaps(stack_b);
}



/*
static int	get_target(t_list **a, int b_idx,int target_idx, int target_pos)
{
	t_list	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->place;
		}
		tmp_a = tmp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->place;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

void	get_target_position(t_list **a, t_list **b)
{
	t_list	*tmp_b;
	int		target_pos;

	tmp_b = *b;
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = get_target(a, tmp_b->index, INT_MAX, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}
*/

/*
static void	push_all_save_three(t_list **stack_a, t_list **stack_b, int *command_counter)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = ft_list_size(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			ft_push(stack_b, stack_a, "pb", command_counter);
//printf("----------------------------------------\n");
ft_print_list(*stack_a, 'a');
ft_print_list(*stack_b, 'b');
printf("----------------------------------------\n");
			pushed++;
		}
		else
		{
			ft_rotate(stack_a, "ra", command_counter);
//printf("----------------------------------------\n");
ft_print_list(*stack_a, 'a');
ft_print_list(*stack_b, 'b');
printf("----------------------------------------\n");
		}
		i++;
	}
	while (stack_size - pushed > 3)
	{
		ft_push(stack_b, stack_a, "pb", command_counter);
//printf("----------------------------------------\n");
ft_print_list(*stack_a, 'a');
ft_print_list(*stack_b, 'b');
printf("----------------------------------------\n");
		pushed++;
	}
}
*/
/*
int	main(int argc, char **argv)
{
	t_list	*stack_a = NULL;
	t_list	*stack_b = NULL;
	int		i ;
	int		command_counter;
	int		stack_size;

	i = 1;
	command_counter = 0;
	if (ft_check_input(argc, argv) == 1)
	{
		while (i < argc)
		{
			ft_add_to_back(&stack_a, atoi(argv[i]));
			i++;
		}
		stack_size = ft_list_size(stack_a);
		ft_index_list(&stack_a);
		ft_assign_places(&stack_a);
		ft_assign_dist_to_right_place(&stack_a);
		ft_assign_gaps(&stack_a);
//get_target_position(&stack_a, &stack_b);
ft_print_list(stack_a, 'a');
ft_print_list(stack_b, 'b');
		ft_split_stack_in_two(&stack_a, &stack_b, &command_counter);

printf("----------------------------------------\n");
//push_all_save_three(&stack_a, &stack_b, &command_counter);
//		while (ft_is_sorted(stack_a) == 0)
//		{
//			ft_move_to_top_farthest(&stack_a, &command_counter);
//			if (!ft_is_sorted(stack_a))
//			{
//				ft_push(&stack_b, &stack_a, "pb", &command_counter);
//				if (!ft_is_sorted(stack_a))
//					ft_swap_both(&stack_b, &stack_a, &command_counter);
//			}
//		}
ft_print_list(stack_a, 'a');
ft_print_list(stack_b, 'b');
printf("----------------------------------------\n");
//		ft_sort_three(&stack_a, &command_counter);
//		ft_sort_three(&stack_b, &command_counter);
//		ft_print_list(stack_a, 'A');
//		ft_print_list(stack_b, 'B');
	}
printf("Number of commands used: %d\n", command_counter);
	return (0);
}*/