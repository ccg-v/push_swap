/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 01:00:26 by ccarrace          #+#    #+#             */
/*   Updated: 2023/05/02 23:18:55 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_list_size(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

void	ft_update_positions(t_list **lst)
{
	t_list *current;
	int	i;

	current = *lst;
	i = 1;
	while (current)
	{
		current->position = i;
		i++;
		current = current->next;
	}
}

int	ft_find_and_index_minimum(t_list *lst)
{
	t_list	*current;
	int		min;

	current = lst;
	min = current->value;
	while (current)
	{
		if (current->value > min)
			min = current->value;;
		current = current->next;
	}
	current = lst;
	return (min);
}

/*	Initializing the 'min' variable with the maximum possible integer value
	is a common technique used in finding the minimum value in a list. When
   	you initialize the 'min' variable with INT_MAX, any other value in the
	list will be less or equal to 'min'. This means that the first value you
	compare to 'min' will always become the new minimum.
	We could also create an extra function to search for the maximum value
	in the list, and use it to initialize the 'min' variable. But obviously,
	the first solution is pretty much easier.
*/	

void ft_list_indexing(t_list **lst)
{
    t_list *current;
	t_list *min_node;
    int 	i;
	int		min;

 	current = *lst;
	min_node = NULL;
	i = 1;
    while (current && i <= ft_list_size(current))
    {
		min = INT_MAX;
		while (current)
        {
            if (current->value < min && current->index == 0)
            {
                min = current->value;
                min_node = current;
            }
            current = current->next;
        }
//        if (min_node != NULL)
            min_node->index = i;
        i++;
        current = *lst;
    }
}

t_list	*ft_create_node(int	num)
{
	t_list	*node;
	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = num;
	node->next = NULL;
	return (node);
}

void	ft_add_to_front(t_list **lst, int value)
{
	t_list	*new_node;

	if (!*lst)
		*lst = ft_create_node(value);
	else
	{
		new_node = ft_create_node(value);
		new_node->next = *lst;
		*lst = new_node;
	}
}

void	ft_add_to_back(t_list **lst, int value)
{
	t_list	*old_tail;
	t_list	*new_tail;
	t_list	*current;

	if (!*lst)
		*lst = ft_create_node(value);
	else
	{
		current = *lst;
		new_tail = ft_create_node(value);
		while (current->next)
			current = current->next;
		old_tail = current;
		old_tail->next = new_tail;
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
/*
int	main(void)
{
	t_list *stack_a;
	int	a = 6;
	int b = 10;
	int c = 3;
	int	d = 42;
	int e = 2;
	int f = 5;
	int g = 7;

	stack_a = NULL;
	ft_add_to_front(&stack_a, a);
	ft_add_to_front(&stack_a, b);
	ft_add_to_front(&stack_a, c);
	ft_add_to_front(&stack_a, d);
	ft_add_to_front(&stack_a, e);
	ft_add_to_front(&stack_a, f);
	ft_add_to_front(&stack_a, g);
	ft_update_positions(&stack_a);
//	ft_find_and_index_minimum (stack_a);
	ft_list_indexing(&stack_a);
	ft_print_list(stack_a);
//	printf("min value is %d\n", ft_find_and_index_minimum(stack_a));
	printf("size of list is %d\n", ft_list_size(stack_a));
}
*/
int	main(int argc, char **argv)
{
	t_list	*stack_a;
	int		value;
	int		i;

	i = 1;
	stack_a = NULL;
	while (i < argc)
	{
		value = atoi(argv[i]);
		ft_add_to_back(&stack_a, value);
		i++;
	}
	ft_update_positions(&stack_a);
	ft_list_indexing(&stack_a);
	ft_print_list(stack_a);
	printf("min value is %d\n", ft_find_and_index_minimum(stack_a));
	return (0);
}
