#include "push_swap.h"

void	if_swap_a(t_meta	*pkg, int	a, int b)
{
	if (a > b)
	{
		sa(pkg);
		printf("sa\n");
	}
}

void	update_onetwothree(t_list	*tmp, int	*one, int	*two, int	*three)
{
	*one = tmp->num;
	tmp = tmp->next;
	*two = tmp->num;
	tmp = tmp->next;
	*three = tmp->num;
}

void	sort_two(t_meta	*pkg)
{
	t_list	*tmp;

	tmp = pkg->list_a_head;
	int	num1;
	int	num2;

	num1 = tmp->num;
	num2 = tmp->next->num;
	if_swap_a(pkg, num1, num2);
}

void	sort_five(t_meta	*pkg)
{
	push_min_to_b(pkg);
	push_min_to_b(pkg);
	sort_three(pkg);
	pa(pkg);
	pa(pkg);
}


void	sort_three(t_meta *pkg)
{
	int		one;
	int		two;
	int		three;


	one = 0;
	two = 0;
	three = 0;
	update_onetwothree(pkg->list_a_head, &one, &two, &three);
	if (one > two && two < three && three < one)
		ra(pkg);
	else if (one > two && two > three && three < one)
	{
		sa(pkg);
		rra(pkg);
	}
	else if (one > two && two < three && three > one)
		sa(pkg);
	else if (one < two && two > three && three > one)
	{
		sa(pkg);
		ra(pkg);
	}
	else if (one < two && two > three && three < one)
		rra(pkg);
}

/*void	sort_three_faster(t_meta	*pkg)
{
	t_list	*one;
	t_list	*two;
	t_list	*three;

	one = pkg->list_a_head;
	two = one->next;
	three = two->next;
	if (one > two && two < three)
	{
		sa(pkg);
	}
	else if (one > two && two > three)
	{
		sa(pkg);
		rra(pkg);
	}
	else if (one > two && two < three)
	{
		ra(pkg);
	}
	else if (one < two && two > three)
	{
		sa(pkg);
		ra(pkg);
	}
	else if (one < two && two > three)
	{
		rra(pkg);
	}
		sa(pkg);
	printf("a sorted successfully (hopefully)");
}
*/

