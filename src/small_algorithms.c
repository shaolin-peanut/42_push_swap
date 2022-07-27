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

void	update_onetwothree(t_meta	*pkg, int	*one, int	*two, int	*three)
{
	t_list	*tmp;

	tmp = pkg->list_a_head;
	*one = tmp->num;
	tmp = tmp->next;
	*two = tmp->num;
	tmp = tmp->next;
	*three = tmp->num;
}

void	fast_sort(t_meta *pkg)
{
	int		one;
	int		two;
	int		three;


	one = 0;
	two = 0;
	three = 0;
	if (pkg->a_size < 2)
		exit (EXIT_FAILURE);
	//while (is_sorted(pkg->list_a_head) == -1)
	sort_three(pkg, one, two, three);
}


// if (one > three)
// swap a and c
// which is done 
void	sort_three(t_meta *pkg, int	one, int two, int three)
{
	if (one > three)
	{
		sa(pkg);
		rra(pkg);
	}
	update_onetwothree(pkg, &one, &two, &three);	
	if (one > two)
	{
		sa(pkg);
	}
	update_onetwothree(pkg, &one, &two, &three);	
	if (two > three)
	{
		ra(pkg);
		sa(pkg);
		rra(pkg);
	}
	update_onetwothree(pkg, &one, &two, &three);	
	if (one > two)
	{
		sa(pkg);
	}
	/*if (two > onedd && one > three)
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
	}*/
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
