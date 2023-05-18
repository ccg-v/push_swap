#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
     int value;
     struct s_list *next;
}     t_list;

t_list    *ft_create_node(int    num)
{
    t_list    *node;
    node = malloc(sizeof(t_list));
    if (!node)
        return (NULL);
    node->value = num;
    node->next = NULL;
    return (node);
}

void    ft_add_to_back(t_list **lst, int value)
{
    t_list    *old_tail;
    t_list    *new_tail;
    t_list    *current;

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

int    ft_list_size(t_list *lst)
{
    int    i;

    i = 0;
    while(lst)
    {
        i++;
        lst = lst->next;
    }
    return (i);
}

void	ft_push(t_list **dst, t_list **src)
{
	t_list	*tmp;

	if (*src)
	{
		tmp = *src;
		*src = (*src)->next;
		tmp->next = *dst;
		*dst = tmp;
	}
}

void	ft_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;
	t_list	*tmp;

	tail = NULL;
	head = *stack;
	tmp = head;
	*stack = head->next;
	while (tmp->next)
		tmp = tmp->next;
	tail = tmp;
	tail->next = head;
	head->next = NULL;
}

void ft_parse_list(t_list **lst_a, t_list **lst_b)
{
    t_list	*current_node;
    t_list  **new_head;
	int		half_list;

	current_node = *lst_a;
    new_head = lst_a;
	half_list = ft_list_size(*lst_a) / 2;
	while(current_node)
	{
		if(current_node->value <= half_list)
        {
			printf("%d is lesser or equal than %d\n", current_node->value, half_list);
            ft_push(lst_b, lst_a);
        }
		else
        {
			printf("%d is greater than %d\n", current_node->value, half_list);
            ft_rotate(lst_a);
        }
		current_node = (*new_head)->next;
	}
}

static void	ft_print_list(t_list *lst, char name)
{
	printf("\n%c:\tValue\n", name);
	while (lst)
	{
		printf("\t%d\n", lst->value);
		lst = lst->next;
	}
	printf("\n");
}

int main(void)
{
    t_list  *lst_a;
    t_list  *lst_b;
    int     arr[] = {2, 3, 1, 4, 6, 5};
    int     i = 0;

    lst_a = NULL;
    lst_b = NULL;
    while (i < 6)
    {
        ft_add_to_back(&lst_a, arr[i]);
        i++;
    }
    ft_parse_list(&lst_a, &lst_b);
    ft_print_list(lst_a, 'A');
    ft_print_list(lst_b, 'B');
}