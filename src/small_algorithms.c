#include "push_swap.h"

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

void	bubble_sort(t_meta	*pkg)
{
	while (is_sorted(pkg->list_a_head) == -1)
	{
		ra(pkg);
		if (pkg->list_a_head->num > pkg->list_a_head->next->num)
			sa(pkg);
	}
	printf("sorted\n");
}
