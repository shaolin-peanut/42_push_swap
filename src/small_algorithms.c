/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algorithms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:34:16 by sbars             #+#    #+#             */
/*   Updated: 2022/08/04 16:46:45 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_swap_a(t_meta *pkg, int a, int b)
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
	int		num1;
	int		num2;

	tmp = pkg->list_a_head;
	num1 = tmp->num;
	num2 = tmp->next->num;
	if_swap_a(pkg, num1, num2);
}

void	sort_small(t_meta	*pkg)
{
	while (pkg->a_size > 3)
		push_min_to_b(pkg);
	sort_three(pkg);
	while (pkg->b_size > 0)
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
