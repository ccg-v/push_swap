/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:34:28 by ccarrace          #+#    #+#             */
/*   Updated: 2023/05/05 21:14:35 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_list
{
	int				*num;
	struct s_list	*next;
}					t_list;

/*
 	sa (swap a):	Swap the first 2 elements at the top of stack a.
					Do nothing if there is only one or no elements.
*/

/*
	First version: 	Swapping THE VALUES of the pointers, not the 
					pointers themselves (parameters received are
					pointers, hence we have to derefence them)
*/

void	ft_sa(int *a, int *b)
{
	int	tmp;

	if (*a && *b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

/*
	Second version:	The parameter passed is a double pointer to the
					first node of the list, because we need to update
					this pointer to swap the first two nodes.

				*	We create a temporary pointer 'tmp' that points
					to the second node of the list, and we swap the
					'next' pointers of the first two nodes.

				*	Finally we update the 'lst' pointer to point to
					the new first node of the list (originally the
					second node).
*/

/*
void	ft_ssa(t_list **lst)
{
	t_list	*tmp;;

	if (!(*lst) || !(*lst)->next)
		return ;
	tmp = (*lst)->next;
	(*lst)->next = tmp->next;
	tmp->next = *lst;
	*lst = tmp;
}
*/

/*
	Third version:	Same as previous solution, but the temporary
					pointer points to the first node of the list
 
*/
void	ft_ssa(t_list **lst)
{
	t_list	*tmp;

	if (!(*lst) || !(*lst)->next)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = (*lst)->next;
	(*lst)->next = tmp;
}

t_list	*ft_create_node(void *data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->num = data;
	node->next = NULL;
	return (node);
}

void	ft_print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d ", *(int *)lst->num);
		lst = lst->next;
	}
	printf("\n");
}

int	main(void)
{
	t_list	*lst;
	int		first;
	int		second;
	int		third;
	int		last;

	first = 1;
	second = 2;
	third = 3;
	last = 4;
	lst = ft_create_node(&first);
	lst->next = ft_create_node(&second);
	lst->next->next = ft_create_node(&third);
	lst->next->next->next = ft_create_node(&last);
	ft_print_list(lst);
	printf("Swapping first two elements:\n");
	ft_sa(lst->num, lst->next->num);
	ft_print_list(lst);
	return (0);
}
