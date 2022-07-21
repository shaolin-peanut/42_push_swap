#include "push_swap.h"

void	qwhacksort(t_meta	*pkg)
{
	int i;
	int j;
	int	pivot;

	i = -1;
	j = 0;
	while (++i < 100 && is_sorted(pkg->list_a_head) == -1)
	{
		// Split A with pivot
		j = pkg->a_size;
		pivot = (list_min(pkg->list_a_head) + list_max(pkg->list_a_head)) / 2;
		while (j-- > -1)
		{
			if (pkg->list_a_head->num <= pivot)
				pb(pkg);
			else
				ra(pkg);
		}
		// Split B with pivot
		j = pkg->b_size;
		pivot = (list_min(pkg->list_b_head) + list_max(pkg->list_b_head)) / 4;
		if (is_sorted(pkg->list_a_head) == 1)
			break;
		while (j-- > -1 && pkg->list_b_head != NULL)
		{
			if (pkg->list_b_head->num > pivot)
			{
				pa(pkg);
			}
			else if (pkg->list_b_butt->num > pivot)
			{
				rrb(pkg);
				pa(pkg);
			}
			else
				rb(pkg);
		}
	}
	i = 0;
//	while (i < pkg->b_size)
//		pa(pkg);
}

void	if_swap_a(t_meta	*pkg, int	a, int b)
{
	if (a > b)
	{
		sa(pkg);
		printf("sa\n");
	}
}

void	sort_two(t_meta	*pkg)
{
	int	num1;
	int	num2;

	num1 = pkg->list_a_head->num;
	num2 = pkg->list_a_head->next->num;
	if_swap_a(pkg, num1, num2);
}

void	sort_three(t_meta *pkg)
{
	t_list	*tmp;

	tmp = pkg->list_a_head;
	// if lower is smaller, swap
	if_swap_a(pkg, tmp->num, tmp->next->num);
	// rotate
	ra(pkg);
	tmp = tmp->next;
	// if lower is smaller, swap
	if_swap_a(pkg, tmp->num, tmp->next->num);
	// reverse rotate
	rra(pkg);
	tmp = tmp->previous;
	// third check
	if_swap_a(pkg, tmp->num, tmp->next->num);
}

/*void	bubble_sort(t_meta	*pkg)
{
	int	i;

	while (is_sorted(pkg->list_a_head) == -1)
	{
		i = pkg->a_size;
		while (i > 0)
		{
			ra(pkg);
			if (pkg->list_a_head->num > pkg->list_a_head->next->num)
				sa(pkg);
			i--;
		}
	}
	printf("sorted\n");
}*/
