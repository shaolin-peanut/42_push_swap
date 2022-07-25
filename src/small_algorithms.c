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

void	fast_sort(t_meta *pkg)
{
	t_list	*tmp;

	tmp = pkg->list_a_head;
	if (pkg->a_size > 2)
		sort_three(pkg, tmp->num, tmp->next->num, tmp->next->next->num);
	else
		exit(EXIT_FAILURE);
}

void	sort_three(t_meta *pkg, int	one, int two, int three)
{
	if (two > three && one > three)
		sa(pkg);
	else if (two > three && three > one)
		rra(pkg);
	else if (one > three && three > two)
	{
		rra(pkg);
		sa(pkg);
	}
	else if (three > two && two > one)
	{
		ra(pkg);
		sa(pkg);
	}
	else
	{
		sa(pkg);
		rra(pkg);
		sa(pkg);
	}
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
