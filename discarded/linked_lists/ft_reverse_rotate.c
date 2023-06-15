/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:17:55 by ccarrace          #+#    #+#             */
/*   Updated: 2023/04/16 21:45:53 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	int				*num;
	struct s_list	*next;
}					t_list;

/*
	reverse rotate (rra):	Shift down all elements of stack a by 1.
							The last element becomes the first one.
*/

void	ft_reverse_rotate(t_list **lst)
{
	t_list	*head;
	t_list	*old_tail;
	t_list	*new_tail;
	t_list	*tmp;

	head = *lst;
	tmp = head;
	while (tmp->next->next)
	{
		new_tail = tmp->next;
		old_tail = new_tail->next;
		tmp = tmp->next;
	}
	new_tail->next = NULL;
	old_tail->next = head;
	*lst = old_tail;
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
		printf("%d ", *(lst)->num);
		lst = lst->next;
	}
	printf("\n");
}

int	main(void)
{
	t_list	*lst;
	int		a;
	int		b;
	int		c;
	int		d;

	a = 1;
	b = 2;
	c = 3;
	d = 4;
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
