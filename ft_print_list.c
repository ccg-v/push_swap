#include "push_swap.h"

void	ft_print_list(t_list *lst, char stack_name)
{
	printf("\n%c:\tValue\tPosit\tIndex\tTarget\n", stack_name);
	while (lst)
	{
		printf("\t%d\t%d\t%d\n", lst->value, lst->index, lst->target_pos);
		lst = lst->next;
	}
	printf("\n");
}