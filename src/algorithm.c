/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:02:21 by sbars             #+#    #+#             */
/*   Updated: 2022/08/16 16:29:32 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort(t_meta	*pkg)
{
	if (pkg->a_size == 2)
		sa(pkg);
	else if (pkg->a_size == 3)
		sort_three(pkg);
	else if (pkg->a_size < 13)
		sort_small(pkg);
	else
		radix_sort(pkg);
}

t_radix	init_radix(t_radix	*data)
{
	data->max_bits = 0;
	data->i = 0;
	data->j = 0;
	data->num = 0;
	data->size = 0;
	return (*data);
}

int	finer_max_bits(t_meta	*pkg)
{
	int	i;
	int	max;

	i = 0;
	max = pkg->a_size - 1;
	while (max >> i != 0)
		i++;
	max = i;
	return (max);
}

void	radix_sort(t_meta	*pkg)
{
	t_radix	rad;

	init_radix(&rad);
	rad.i = -1;
	rad.j = -1;
	rad.size = pkg->a_size;
	replace_by_tidy_num(pkg);
	rad.max_bits = finer_max_bits(pkg);
	while (++rad.i < rad.max_bits)
	{
		rad.j = -1;
		while (++rad.j < rad.size)
		{
			if (((pkg->list_a_head->num >> rad.i) & 1) == 1)
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
