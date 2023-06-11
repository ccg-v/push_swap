#include "push_swap.h"

void	ft_print_list(t_list *lst, char stack_name)
{
	if (lst->closest_upper_address != NULL && lst->closest_upper_address->gap_to_top)
	{
		if (stack_name == 'A')
		{
			printf("\n%c::\tVALUE\tPlace\tIndex\tB_gap\tUpper\tptr\n", stack_name);
			while (lst)
			{
				printf("\t%d\t%d\t%d\t%d\t%c\t%p\n", lst->value, lst->place, lst->index, lst->gap_to_top, '-', (void*)lst);
				lst = lst->next;
			}
			printf("\n");
		}
		else if (stack_name == 'B')
		{
			printf("\n%c::\tVALUE\tPlace\tIndex\tB_gap\tUpper\tptr\n", stack_name);
			while (lst)
			{
				printf("\t%d\t%d\t%d\t%d\t%d\t%p\n", lst->value, lst->place, lst->index, lst->gap_to_top, lst->closest_upper, lst->closest_upper_address);
				lst = lst->next;
			}
			printf("\n");
		}
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