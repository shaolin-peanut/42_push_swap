#include "push_swap.h"

void	sort(t_meta	*pkg)
{
	if (pkg->a_size == 2)
		sort_two(pkg);
	else if (pkg->a_size == 3)
		sort_three(pkg);
	else if (pkg->a_size == 5)
		sort_five(pkg);
	//else
	//	split_in_groups(pkg);
}

void	split_in_groups(t_meta	*pkg)
{
	int	pivot;
	int	min;
	t_list	*top;

	pivot = pkg->a_size;
	pivot = choose_pivot(pkg->list_a_head, pkg->a_size); 
	while (pkg->a_size > 1)
	{
		top = pkg->list_a_head;
		min	= list_min(pkg->list_a_head, pkg->a_size);
		pivot = choose_pivot(pkg->list_a_head, pkg->a_size); 
		if (pivot <= min)
			pivot += pivot;
		if (top->num <= pivot)
			pb(pkg);
		else
			ra(pkg);
	}
	while (pkg->b_size > 0)
	{
		pa(pkg);
		pa(pkg);
		pa(pkg);
		if (pkg->b_size < 3)
			sort_two(pkg);
		else
			sort_three(pkg);
	}
}

// this can be optimized, calculate distance to choose between ra or rra
void	push_min_to_b(t_meta	*pkg)
{
	int	min;

	min = list_min(pkg->list_a_head, pkg->a_size);
	while (pkg->list_a_head->num != min)
		ra(pkg);
	pb(pkg);
}
