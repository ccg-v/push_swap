#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int				*value;
	struct s_list 	*next;
}					t_list;

t_list	*ft_create_node(int	num)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = malloc(sizeof(int));
	if (!node->value)
	{
		free(node);
		return (NULL);
	}
	*(node)->value = num;
	node->next = NULL;
	return (node);
}

void	ft_add_to_front(t_list **stack, int *value)
{
	t_list	*new_node;

	if (!*stack)
		*stack = ft_create_node(*value);
	else
	{
		new_node = ft_create_node(*value);
		new_node->next = *stack;
		*stack = new_node;
	}
}

// A separate pointer ('current') is needed to traverse the list
// while keeping the head pointer ('*stack') intact. If ('*stack')
// is used to traverse the list, the original head pointer will not
// be preserved, so the program loses track of the head of the list

void	ft_add_to_back(t_list **stack, int value)
{
	t_list	*old_tail;
	t_list	*new_tail;
	t_list	*current;

	if (!*stack)
		*stack = ft_create_node(value);
	else
	{
		new_tail = ft_create_node(value);
		current = *stack;
		while(current)
		{
			old_tail = current;
			current = current->next;
		}
		old_tail->next = new_tail;
	}
}

void	ft_print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d ", *(lst)->value);
		lst = lst->next;
	}
	printf("\n");
}

size_t	ft_list_size(t_list *lst);
t_list	*ft_list_max(t_list **lst);
t_list	*ft_list_min(t_list **lst);

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		value;
	int		i;
	t_list	*max_node;
	t_list	*min_node;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;

	while (i < argc)
	{
		value = atoi(argv[i]);
		ft_add_to_front(&stack_a, &value);
		i++;
	}
	i = 1;
	while (i < argc)
	{
		value = atoi(argv[i]);
		ft_add_to_back(&stack_b, value);
		i++;
	}
	printf("stack_a: ");
	ft_print_list(stack_a);
	printf("stack_b: ");
	ft_print_list(stack_b);
	printf("size of list is %zu\n", ft_list_size(stack_a));
	max_node = ft_list_max(&stack_a);
	printf("max value is %d\n", *(max_node->value));
	min_node = ft_list_min(&stack_a);
	printf("min value is %d\n", *(min_node->value));	
	return (0);
}
