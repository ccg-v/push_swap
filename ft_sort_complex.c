/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_complex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:42:08 by ccarrace          #+#    #+#             */
/*   Updated: 2023/06/08 20:49:23 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}



// No hay simetria, empieza en 0 y termina en -1 porque el ultimo
// elemento necesita una rotacion inversa para colocarse arriba y 
// poder moverlo a B.
/*
void	ft_assign_gaps_b(t_list **stack)
{
	t_list  *current;
	int	    stack_size;  
	int		gap_to_top; 

	current = *stack;
	gap_to_top = 0;
    stack_size = ft_list_size(*stack);
	while (current && (current->place < (stack_size / 2)))
	{
		current->gap_to_top = gap_to_top++;
		current = current->next;
	}
	gap_to_top = (stack_size / 2);
	if (stack_size % 2 != 0)
		gap_to_top++;
	while (current && (current->place >= (stack_size / 2)))
	{
		current->gap_to_top = gap_to_top * -1;
		gap_to_top--;
		current = current->next;
	}
}

*/
// Hay simetria porque en este stack el closest_upper no necesita ser colocado
// en la cabeza porque no vamos a cambiarlo de stack. Dejandolo en la cola nos
// ahorramos ese movimiento y cuando hagamos push del top de B ambos estaran en 
// el orden correcto, el mayor en la cola y el menor en la cabeza.
/*
void	ft_assign_gaps_a(t_list **stack)
{
	t_list  *current;
	int	    stack_size;  
	int		gap_to_top; 

	current = *stack;
	gap_to_top = 0;
    stack_size = ft_list_size(*stack);
	while (current && (current->place < (stack_size / 2)))
	{
		current->gap_to_top = gap_to_top++;
		current = current->next;
	}
	gap_to_top = (stack_size / 2);
	if (stack_size % 2 == 0)
		gap_to_top--;
	while (current && (current->place >= (stack_size / 2)))
	{
		current->gap_to_top = gap_to_top * -1;
		gap_to_top--;
		current = current->next;
	}
}
*/

t_list	*ft_find_best_push(t_list **stack_b)
{
	t_list *b_node;
	int	lowest_sum_of_gaps;
	int	current_sum_of_gaps;
	t_list	*best_push_address;

	b_node = *stack_b;
	lowest_sum_of_gaps = INT_MAX;
	while (b_node) 
	{
		current_sum_of_gaps = (ft_abs(b_node->gap_to_top) + ft_abs(b_node->closest_upper_address->gap_to_top));
		if (current_sum_of_gaps < lowest_sum_of_gaps)
		{
			lowest_sum_of_gaps = current_sum_of_gaps;
			best_push_address = b_node;
		}
//		if (current_sum_of_gaps == 0 || current_sum_of_gaps == ft_abs(1))
//			return(best_push_address);
//		else
			b_node = b_node->next;
	}
	return(best_push_address);
}

void	ft_choose_single_commands(t_list **stack_a, t_list **stack_b, t_list *b_best_push, int *command_counter)
{
	t_list	*a_best_push;
	int		a_gap;
	int		b_gap;
	
	a_best_push = b_best_push->closest_upper_address; // change to a_best_push = ft_find_best_push(stack_b) y lo elimino del main?????
	a_gap = a_best_push->gap_to_top;
	b_gap = b_best_push->gap_to_top;

	if (a_gap > 0 && b_gap > 0)
	{
		while (a_gap > 0 && b_gap > 0)
		{
			a_gap--;
			b_gap--;
			ft_rotate_both(stack_a, stack_b, command_counter);
		}
	}
	else if (a_gap < 0 && b_gap < 0)
	{
		while (a_gap < 0 && b_gap < 0)
		{
			a_gap++;
			b_gap++;
			ft_reverse_rotate_both(stack_a, stack_b, command_counter);
		}
	}
	while (a_best_push->gap_to_top)
	{
		if (a_gap > 0)
		{
			ft_rotate(stack_a, "ra", command_counter);
			a_gap--;
		}
		else if(a_gap < 0)
		{
			ft_reverse_rotate(stack_a, "rra", command_counter);
			a_gap++;
		}
	}
	while (b_gap)
	{
		if (b_gap > 0)
		{
			ft_rotate(stack_b, "rb", command_counter);
			b_gap--;
		}
		else if(b_gap < 0)
		{
			ft_reverse_rotate(stack_b, "rrb", command_counter);
			b_gap++;
		}
	}
	ft_push(stack_a, stack_b, "pa", command_counter);
}
/*
void	ft_choose_single_commands(t_list **stack_a, t_list **stack_b, t_list *b_best_push, int *command_counter)
{
	t_list	*a_best_push;
	
	a_best_push = b_best_push->closest_upper_address; // change to a_best_push = ft_find_best_push(stack_b) y lo elimino del main?????
	if (a_best_push->gap_to_top > 0 && b_best_push->gap_to_top > 0)
	{
		while (a_best_push->gap_to_top > 0 && b_best_push->gap_to_top > 0)
		{
			(a_best_push->gap_to_top)--;
			(b_best_push->gap_to_top)--;
			ft_rotate_both(stack_a, stack_b, command_counter);
		}
	}
	else if (a_best_push->gap_to_top < 0 && b_best_push->gap_to_top < 0)
	{
		while (a_best_push->gap_to_top < 0 && b_best_push->gap_to_top < 0)
		{
			(a_best_push->gap_to_top)++;
			(b_best_push->gap_to_top)++;
			ft_reverse_rotate_both(stack_a, stack_b, command_counter);
		}
	}
	while (a_best_push->gap_to_top)
	{
		if (a_best_push->gap_to_top > 0)
		{
			ft_rotate(stack_a, "ra", command_counter);
			(a_best_push->gap_to_top)--;
		}
		else if(a_best_push->gap_to_top < 0)
		{
			ft_reverse_rotate(stack_a, "rra", command_counter);
			(a_best_push->gap_to_top)++;
		}
	}
	while (b_best_push->gap_to_top)
	{
		if (b_best_push->gap_to_top > 0)
		{
			ft_rotate(stack_b, "rb", command_counter);
			(b_best_push->gap_to_top)--;
		}
		else if(b_best_push->gap_to_top < 0)
		{
			ft_reverse_rotate(stack_b, "rrb", command_counter);
			(b_best_push->gap_to_top)++;
		}
	}
}
*/
/*
void	ft_choose_single_commands(t_list **stack_a, t_list **stack_b, t_list *b_best_push, int *command_counter)
{
	t_list	*a_best_push;
	int		i;

	i = 0;
	a_best_push = b_best_push->closest_upper_address;
//	if (a_best_push->gap_to_top == 0 && b_best_push->gap_to_top == 0)
//	{
//		ft_push(stack_a, stack_b, "pa", command_counter);
//		return ;
//	}
	if (a_best_push->gap_to_top == 0 && b_best_push->gap_to_top > 0)
	{
		while (i <= ft_abs(b_best_push->gap_to_top))
		{
			ft_rotate(stack_b, "rb", command_counter);
			i++;
printf("\tA_best = %d\tB_best = %d\n", b_best_push->closest_upper_address->index, b_best_push->index);
printf("\tA_gap = %d\tB_gap = %d\ti = %d\n", b_best_push->closest_upper_address->gap_to_top, b_best_push->gap_to_top, i);
		}
	}
	else if (a_best_push->gap_to_top == 0 && b_best_push->gap_to_top < 0)
	{
		while (i <= ft_abs(b_best_push->gap_to_top))
		{
			ft_reverse_rotate(stack_b, "rrb", command_counter);
			i++;
		}
printf("\tA_best = %d\tB_best = %d\n", b_best_push->closest_upper_address->index, b_best_push->index);
printf("\tA_gap = %d\tB_gap = %d\ti = %d\n", b_best_push->closest_upper_address->gap_to_top, b_best_push->gap_to_top, i);
	}
	else if (a_best_push->gap_to_top > 0 && b_best_push->gap_to_top == 0)
	{
		while (i <= ft_abs(a_best_push->gap_to_top))
		{
			ft_rotate(stack_a, "ra", command_counter);
			i++;
		}
printf("\tA_best = %d\tB_best = %d\n", b_best_push->closest_upper_address->index, b_best_push->index);
printf("\tA_gap = %d\tB_gap = %d\ti = %d\n", b_best_push->closest_upper_address->gap_to_top, b_best_push->gap_to_top, i);
	}
	else if (a_best_push->gap_to_top < 0 && b_best_push->gap_to_top == 0)
	{
		while (i <= ft_abs(a_best_push->gap_to_top))
		{
			ft_reverse_rotate(stack_a, "rra", command_counter);
			i++;
		}
printf("\tA_best = %d\tB_best = %d\n", b_best_push->closest_upper_address->index, b_best_push->index);
printf("\tA_gap = %d\tB_gap = %d\ti = %d\n", b_best_push->closest_upper_address->gap_to_top, b_best_push->gap_to_top, i);
	}
	else if (a_best_push->gap_to_top > 0 && b_best_push->gap_to_top < 0)
	{
		while (i <= ft_abs(a_best_push->gap_to_top))
		{
			ft_rotate(stack_a, "ra", command_counter);
			i++;
		}
		while (i <= ft_abs(b_best_push->gap_to_top))
		{
			ft_reverse_rotate(stack_b, "rrb", command_counter);
			i++;
		}					
printf("\tA_best = %d\tB_best = %d\n", b_best_push->closest_upper_address->index, b_best_push->index);
printf("\tA_gap = %d\tB_gap = %d\ti = %d\n", b_best_push->closest_upper_address->gap_to_top, b_best_push->gap_to_top, i);
	}
	else if (a_best_push->gap_to_top < 0 && b_best_push->gap_to_top > 0)
	{
		while (i <= ft_abs(b_best_push->gap_to_top))
		{
			ft_rotate(stack_b, "rb", command_counter);
			i++;
		}
		while (i <= ft_abs(a_best_push->gap_to_top))
		{
			ft_reverse_rotate(stack_a, "rra", command_counter);
			i++;
		}
printf("\tA_best = %d\tB_best = %d\n", b_best_push->closest_upper_address->index, b_best_push->index);
printf("\tA_gap = %d\tB_gap = %d\ti = %d\n", b_best_push->closest_upper_address->gap_to_top, b_best_push->gap_to_top, i);
	}
	else if (a_best_push->gap_to_top > 0 && b_best_push->gap_to_top > 0)	
	{
		if (a_best_push->gap_to_top > b_best_push->gap_to_top)
		{
			while (i <= ft_abs(b_best_push->gap_to_top))
			{
				ft_rotate_both(stack_a, stack_b, command_counter);
				i++;
			}
			while (i <= ft_abs(a_best_push->gap_to_top + b_best_push->gap_to_top))
			{
				ft_rotate(stack_a, "ra", command_counter);
				i++;
			}
		}
		else if (b_best_push->gap_to_top > a_best_push->gap_to_top)
		{
			while (i <= ft_abs(a_best_push->gap_to_top))
			{
				ft_rotate_both(stack_a, stack_b, command_counter);
				i++;
			}
			while (i <= ft_abs(b_best_push->gap_to_top + b_best_push->gap_to_top))
			{
				ft_rotate(stack_b, "rb", command_counter);
				i++;
			}
		}
		else if (b_best_push->gap_to_top == a_best_push->gap_to_top)
			while (i <= ft_abs(a_best_push->gap_to_top))
			{
				ft_rotate_both(stack_a, stack_b, command_counter);
				i++;
			}
printf("\tA_best = %d\tB_best = %d\n", b_best_push->closest_upper_address->index, b_best_push->index);
printf("\tA_gap = %d\tB_gap = %d\ti = %d\n", b_best_push->closest_upper_address->gap_to_top, b_best_push->gap_to_top, i);
	}
	else if (a_best_push->gap_to_top < 0 && b_best_push->gap_to_top < 0)
	{
		if (a_best_push->gap_to_top > b_best_push->gap_to_top)
		{
			while (i <= ft_abs(a_best_push->gap_to_top))
			{
				ft_reverse_rotate_both(stack_a, stack_b, command_counter);
				i++;
			}
			while (i <= ft_abs(a_best_push->gap_to_top + b_best_push->gap_to_top))
			{
				ft_reverse_rotate(stack_b, "rrb", command_counter);
				i++;
			}
		}		
		else if (b_best_push->gap_to_top > a_best_push->gap_to_top)
		{
			while (i <= ft_abs(b_best_push->gap_to_top))
			{
				ft_reverse_rotate_both(stack_a, stack_b, command_counter);
				i++;
			}
			while (i <= ft_abs(a_best_push->gap_to_top + b_best_push->gap_to_top))
			{
				ft_reverse_rotate(stack_a, "rra", command_counter);
				i++;
			}
		}	
		else if (b_best_push->gap_to_top == a_best_push->gap_to_top)
			while (i <= ft_abs(a_best_push->gap_to_top))
			{
				ft_reverse_rotate_both(stack_a, stack_b, command_counter);
				i++;
			}
printf("\tA_best = %d\tB_best = %d\n", b_best_push->closest_upper_address->index, b_best_push->index);
printf("\tA_gap = %d\tB_gap = %d\ti = %d\n", b_best_push->closest_upper_address->gap_to_top, b_best_push->gap_to_top, i);
	}
	ft_push(stack_a, stack_b, "pa", command_counter);
printf("\tA_best = %d\tB_best = %d\n", b_best_push->closest_upper_address->index, b_best_push->index);
printf("\tA_gap = %d\tB_gap = %d\ti = %d\n", b_best_push->closest_upper_address->gap_to_top, b_best_push->gap_to_top, i);		
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
