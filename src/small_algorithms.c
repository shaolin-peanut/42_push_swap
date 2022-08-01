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
	t_list	*tmp;

	tmp = pkg->list_a_head;
	int	num1;
	int	num2;

	num1 = tmp->num;
	num2 = tmp->next->num;
	if_swap_a(pkg, num1, num2);
}

void	update_onetwothree(t_list	*tmp, int	*one, int	*two, int	*three)
{
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
	sort_three_a(pkg, one, two, three);
}

void	sort_six(t_meta	*pkg)
{
	int	size;
	int	one;
	int	two;
	int three;
	int	pivot;

	one = 0;
	two = 0;
	three = 0;
	size = pkg->a_size;
	pivot = choose_pivot(pkg->list_a_head, pkg->a_size);
	if (size == 6 || size == 5)
	{
		while (pkg->a_size != 3)
		{
			if (pkg->list_a_head->num < pivot)
				pb(pkg);
			else
				ra(pkg);
		}
		if (pkg->b_size == 2)
			sort_two(pkg);
		else
			sort_three_b(pkg, one, two, three);
		sort_three_a(pkg, one, two, three);
		while (pkg->b_size != 0)
			pa(pkg);
	}
	else if (size == 5)
	{
	}
	//else if (size == 4)

}


// if (one > three)
// swap a and c
// which is done 
void	sort_three_a(t_meta *pkg, int	one, int two, int three)
{
	if (one > two && two < three && one < three)
	{
		sa(pkg);
	}
	else if (one > two && two > three && one > three)
	{
		sa(pkg);
		rra(pkg);
	}
	else if (one > two && two < three && one > three)
	{
		ra(pkg);
	}
	else if (one < two && two > three && one < three)
	{
		sa(pkg);
		ra(pkg);
	}
	else if (one < two && two > three && one > three)
	{
		rra(pkg);
	}
	/*if (one > three)
	{
		sa(pkg);
		rra(pkg);
		//ra(pkg);
		//ra(pkg);
	}
	update_onetwothree(pkg->list_a_head, &one, &two, &three);	
	if (one > two)
		sa(pkg);
	update_onetwothree(pkg->list_a_head, &one, &two, &three);	
	if (two > three)
	{
		ra(pkg);
		sa(pkg);
		rra(pkg);
	}
	update_onetwothree(pkg->list_a_head, &one, &two, &three);	
	if (one > two)
<<<<<<< HEAD
	{
		sa(pkg);
	}*/
}
void	sort_three_faster(t_meta	*pkg)
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
=======
		sa(pkg);
	printf("a sorted successfully (hopefully)");
>>>>>>> ebd1836cd884a375ae73a28d776ce7abc29f8f2a
}

void	sort_three_b(t_meta *pkg, int	one, int two, int three)
{
	if (one < three)
	{
		sb(pkg);
		rrb(pkg);
	}
	update_onetwothree(pkg->list_b_head, &one, &two, &three);	
	if (one < two)
		sb(pkg);
	update_onetwothree(pkg->list_b_head, &one, &two, &three);	
	if (two < three)
	{
		rb(pkg);
		sb(pkg);
		rrb(pkg);
	}
	update_onetwothree(pkg->list_b_head, &one, &two, &three);	
	if (one < two)
		sb(pkg);
	printf("b sorted successfully (hopefully)");
}
