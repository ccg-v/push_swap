/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 22:24:33 by ccarrace          #+#    #+#             */
/*   Updated: 2023/04/16 21:51:12 by ccarrace         ###   ########.fr       */
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
	ra (rotate a):	Shift up all elements of stack a by 1.
					The first element becomes the last one.
*/

void	ft_rotate(t_list **lst)
{
	t_list	*head;
	t_list	*tail;
	t_list	*tmp;

	tail = NULL;
	head = *lst;
	tmp = head;
	*lst = head->next;
	while (tmp->next)
		tmp = tmp->next;
	tail = tmp;
	tail->next = head;
	head->next = NULL;
}

t_list	*ft_last_node(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_create_elem(void *data)
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
	lst = ft_create_elem(&a);
	lst->next = ft_create_elem(&b);
	lst->next->next = ft_create_elem(&c);
	lst->next->next->next = ft_create_elem(&d);
	printf("List is: ");
	ft_print_list(lst);
	ft_rotate(&lst);
	printf("List rotated is: ");
	ft_print_list(lst);
	return (0);
}
