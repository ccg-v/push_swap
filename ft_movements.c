/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:53:47 by ccarrace          #+#    #+#             */
/*   Updated: 2023/04/27 23:37:47 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_push(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;
	
	if (lst_b)

}

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

void	ft_rotate_all(t_list **lst_a, t_list **lst_b)
{
	ft_rotate(*lst_a);
	ft_rotate(*lst_b);
	write(1, "rrr", 3);
}
