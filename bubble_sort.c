#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int				*value;
	struct s_list 	*next;
}					t_list;

/*
void	bubble_sort(t_list *stack_a, t_list *stack_b)
{
	while (stack_a->next)
	{
		if (stack_a->value < stack_a->next->value)

	}
}
*/

t_list	*ft_create_node(void *data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = data;
	node->next = NULL;
	return (node);
}

void	ft_add_to_front(t_list **stack, int *value)
{
	t_list	*new_node;

	if (!*stack || *stack == NULL)
		*stack = ft_create_node(value);
	else
	{
		new_node = ft_create_node(value);
		new_node->next = *stack;
		*stack = new_node;
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

/*
int	main(void)
{
	t_list	*stack_a;
	int		a = 12;
	int		b = 23;
	int		c = 34;
	
	stack_a = NULL;
	ft_add_to_front(&stack_a, &a);
	ft_add_to_front(&stack_a, &b);
	ft_add_to_front(&stack_a, &c);
	ft_print_list(stack_a);
	return (0);
}
*/

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		value;
	int		i;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
printf("argc is %d\n", argc);

	while (i < argc)
	{
		value = atoi(argv[i]);
printf("argv[%d] is %d\n", i, value);
		ft_add_to_front(&stack_a, &value);
		i++;
	}
	printf("stack_a: ");
	ft_print_list(stack_a);
	printf("stack_b: ");
	ft_print_list(stack_b);
	return (0);
}
