#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	int				*num;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

t_list	*ft_create_node(void *data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		node = NULL;
	node->num = data;
	node->prev = NULL;
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

void	ft_print_list_info(t_list *lst)
{
	t_list	*current;
	int		i;

	current = lst;
	i = 1;
	while (current)
	{
		printf("Element %d is %d. ", i, *(current)->num);
		if (current->prev)
			printf("Previous is %d. ", *(current)->prev->num);
		if (current->next)
			printf("Next is %d. ", *(current)->next->num);
		printf("\n");
		current = current->next;
		i++;
	}	
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
	lst->next->prev = lst;
	lst->next->next = ft_create_node(&c);
	lst->next->next->prev = lst->next;
	lst->next->next->next = ft_create_node(&d);
	lst->next->next->next->prev = lst->next->next;
	printf("List is ");
	ft_print_list(lst);
	ft_print_list_info(lst);
	return (0);
}
