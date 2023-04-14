/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:17:55 by ccarrace          #+#    #+#             */
/*   Updated: 2023/04/15 00:45:51 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_list
{
	int				*num;
	struct s_list	*next;
}					t_list;

#include <stdlib.h>
#include <stdio.h>

/*
	reverse rotate (rra):	Shift down all elements of stack a by 1.
							The last element becomes the first one.
*/

void	ft_print_list(t_list *lst);

void	ft_reverse_rotate(t_list **lst)
{
	t_list	*head;
	t_list	*tail;
	t_list	*tmp;

	head = *lst;
	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tail = tmp;
						printf("tail = ");
						ft_print_list(tail);
	tail->next = head;
	*lst = tail;
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

void ft_print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d ", *(lst)->num);
		lst = lst->next;
	}
	printf("\n");
}

int	main(void)
{
	t_list	*lst;
	int		a = 1;
	int		b = 2;
	int		c = 3;
	int		d = 4;

	lst = ft_create_node(&a);
	lst->next = ft_create_node(&b);
	lst->next->next = ft_create_node(&c);
	lst->next->next->next = ft_create_node(&d);
	printf("List is ");
	ft_print_list(lst);	
	printf("Reverse rotated list is ");
	ft_reverse_rotate(&lst);
	ft_print_list(lst);
	return (0);
}
