/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:45:28 by ccarrace          #+#    #+#             */
/*   Updated: 2023/04/14 20:16:01 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int				*num;
	struct s_list 	*next;
}					t_list;

/*
 	pa (push a):	Take the first element at the top of b and put it at the
					top of a. Do nothing if b is empty.
*/

void	ft_push(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;
	if (lst_b)
	{	
		tmp = *lst_b;
		*lst_b = (*lst_b)->next;
		tmp->next = *lst_a;
		*lst_a = tmp;
	}
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
		printf("%d ", *lst->num);
		lst = lst->next;
	}
	printf("\n");
}

int	main(void)
{
	t_list	*lst_a;
	t_list	*lst_b;
	int		a1 = 1;
	int		a2 = 2;
	int		a3 = 3;
	int		b1 = 1000;
	int		b2 = 2000;
	int		b3 = 3000;

	lst_a = ft_create_node(&a1);
	lst_a->next = ft_create_node(&a2);
	lst_a->next->next = ft_create_node(&a3);
	lst_b = ft_create_node(&b1);
	lst_b->next = ft_create_node(&b2);
	lst_b->next->next = ft_create_node(&b3);
	printf("list A: ");
	ft_print_list(lst_a);
	printf("list B: ");
	ft_print_list(lst_b);
	printf("Pushing B first node to A...\n");
	ft_push(&lst_a, &lst_b);
	printf("list A: ");
	ft_print_list(lst_a);
	printf("list B: ");
	ft_print_list(lst_b);
	return (0);
}
