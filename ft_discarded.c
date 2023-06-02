/*
	-- Function to fill part the STACK DATA --
	This function loops to calculat the distance of each node to its correct
	place and store it in the 'dist_to_right_place' variable of the struct
*/

void ft_assign_dist_to_right_place(t_list **lst)
{
	t_list	*current;
	
	current = *lst;
	while (current)
	{
		current->dist_to_right_place = current->index - current->place;
		current = current->next;
	}
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
