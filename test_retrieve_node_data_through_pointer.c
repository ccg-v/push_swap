#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

typedef struct s_list
{
    int             value;
    int             index;
    int             place;
    int             gap_to_top;
    int             closest_upper;
    struct s_list   *closest_upper_address;
    struct s_list   *next;
}                   t_list;

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

int	ft_list_size(t_list *lst)
{
	int	i;

	i = 0;
	while(lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_list	*ft_find_min_node(t_list **lst)
{
	t_list	*min_node;
	t_list	*current_node;

	min_node = *lst;
	current_node = (*lst)->next;
	while (current_node)
	{
		if (current_node->value < min_node->value)
			min_node = current_node;
		current_node = current_node->next;
	}
	return (min_node);
}

void ft_index_list(t_list **lst)
{
    t_list	*current;
	t_list	*min_node;
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
        min_node->index = i;
        i++;
        current = *lst;
    }
}

void	ft_assign_places(t_list **lst)
{
	t_list *current;
	int	i;

	current = *lst;
	i = 0;
	while (current)
	{
		current->place = i;
		i++;
		current = current->next;
	}
}

void	ft_assign_gaps(t_list **lst)
{
	t_list  *current;
	int	    lst_size;  
	int		gap_to_top; 

	current = *lst;
	gap_to_top = 0;
    lst_size = ft_list_size(*lst);
	while (current && (current->place <= (lst_size / 2)))
	{
		current->gap_to_top = gap_to_top++;
		current = current->next;
	}
	if (lst_size % 2 == 0)
		gap_to_top--;
	while (current && (current->place > (lst_size / 2)))
	{
		current->gap_to_top = (--gap_to_top) * -1;
		current = current->next;
	}
}

void	ft_assign_closest_upper(t_list **a, t_list **b)
{
	t_list	*a_node;
	t_list	*b_node;
	int		closest_upper;
	t_list	*closest_upper_address;

	b_node = *b;
	while (b_node)
	{
		closest_upper = INT_MAX;
		a_node = *a;
		while(a_node)
		{
			if (a_node->index > b_node->index && a_node->value < closest_upper)
			{
				closest_upper = a_node->index;
				closest_upper_address = a_node;
			}
			a_node = a_node->next;
		}
		if (closest_upper == INT_MAX)
		{
			b_node->closest_upper = ft_find_min_node(a)->value;
			closest_upper_address = ft_find_min_node(a);
		}
		b_node->closest_upper = closest_upper;
		b_node->closest_upper_address = closest_upper_address;
		b_node = b_node->next;	
	}
}

void	ft_push(t_list **dst, t_list **src, char *move_name)
{
	t_list	*tmp;

	if (*src)
	{
		tmp = *src;
		*src = (*src)->next;
		tmp->next = *dst;
		*dst = tmp;
	}
	printf("%s\n", move_name);
}

void	ft_print_list(t_list *lst, char stack_name)
{
	if (lst->closest_upper_address != NULL)
	{
		printf("\n%c::\tVALUE\tPlace\tIndex\tGapTop\tUpper\n", stack_name);
		while (lst)
		{
			printf("\t%d\t%d\t%d\t%d\t%d\n", lst->value, lst->place, lst->index, lst->gap_to_top, lst->closest_upper_address->index);
			lst = lst->next;
		}
		printf("\n");
	}
	else
	{
		printf("\n%c::\tVALUE\tPlace\tIndex\tGapTop\n", stack_name);
		while (lst)
		{
			printf("\t%d\t%d\t%d\t%d\n", lst->value, lst->place, lst->index, lst->gap_to_top);
			lst = lst->next;
		}
		printf("\n");		
	}
}

int main(int argc, char **argv)
{
    t_list  *a;
    t_list  *b;
    int     i;

    a = NULL;
    b = NULL;

	i = 1;
	while (i < argc)
	{
		ft_add_to_back(&a, atoi(argv[i]));
		i++;
	}
	ft_index_list(&a);
	ft_assign_places(&a);   
	ft_assign_gaps(&a);
ft_print_list(a, 'A');
	while (ft_list_size(a) > 3)
		ft_push(&b, &a, "pb");
	ft_assign_places(&a);
	ft_assign_places(&b);
	ft_assign_gaps(&a);
    ft_assign_gaps(&b);
    ft_assign_closest_upper(&a, &b);
ft_print_list(a, 'A');
ft_print_list(b, 'B');
    return (0);
}