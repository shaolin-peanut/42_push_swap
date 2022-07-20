#include "push_swap.h"

int	is_sorted(t_list	*head)
{
	while (head && head->next)
	{
		if (head->num > head->next->num)
			return (-1);
		head = head->next;
	}
	return (1);
}
