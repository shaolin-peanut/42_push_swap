#include "push_swap.h"

int	is_sorted(t_list	*head)
{
	while (head != NULL && head->next != NULL)
	{
		if (head->num > head->next->num)
			return (-1);
		//printf("is_sorted() comparing %d and %d\n", head->num, head->next->num);
		head = head->next;
	}
	return (1);
}

int	list_min(t_list	*list, int limit)
{
	int	min;
	int	i;

	i = -1;
	if (list)
		min = list->num;
	else
		return (min = 0);
	while (list != NULL && ++i < limit)
	{
		if (list->num < min)
			min = list->num;
		list = list->next;
	}
	return (min);
}

int	list_max(t_list	*list, int limit)
{
	int	max;
	int	i;

	i = -1;
	if (list)
		max = list->num;
	else
		return (max = 0);
	while (list != NULL && ++i < limit)
	{
		if (list->num > max)
			max = list->num;
		list = list->next;
	}
	return (max);
}

int	choose_pivot(t_list	*list, int limit)
{
	return (list_min(list, limit) + list_max(list, limit) / 2);
}
