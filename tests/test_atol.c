#include "push_swap.h"

static void	ft_print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d ", lst->value);
		lst = lst->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_list *lst1;
	t_list *lst2;
	int	i;
	int	value;

	lst1 = NULL;
	lst2 = NULL;
	i = 1;
	while (i < argc)
	{
		value = atol(argv[i]);
		ft_add_to_back(&lst1, value);
		i++;
	}
	printf("Standard atol: ");
	ft_print_list(lst1);
	i = 1;
	while (i < argc)
	{
		value = ft_atol(argv[i]);
		ft_add_to_back(&lst2, value);
		i++;
	}	
	printf("My ft_atol   : ");
	ft_print_list(lst2);
	return (0);
}
