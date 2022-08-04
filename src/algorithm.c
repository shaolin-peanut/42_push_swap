/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:02:21 by sbars             #+#    #+#             */
/*   Updated: 2022/08/04 17:02:59 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort(t_meta	*pkg)
{
	replace_by_tidy_num(pkg);
	if (pkg->a_size == 2)
		sort_two(pkg);
	else if (pkg->a_size == 3)
		sort_three(pkg);
	else if (pkg->a_size <= 12)
		sort_small(pkg);
	else
		radix_sort(pkg);
}

void	radix_sort(t_meta	*pkg)
{
	int	max_num;
	int	max_bits;
	int	i;
	int	j;
	int	num;
	int	size;


	i 		= -1;	
	j 		= -1;	
	num 	= pkg->list_a_head->num;
	size	= pkg->a_size;
	max_num = size - 1;
	max_bits = 0;

	while ((max_num >> max_bits) != 0)
		++max_bits;

	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			num = pkg->list_a_head->num;
			if (((num >> i)&1) == 1)
				ra(pkg);
			else
				pb(pkg);
		}
		while (pkg->b_size != 0)
			pa(pkg);
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
