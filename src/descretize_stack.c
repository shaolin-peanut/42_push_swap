/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   descretize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:59:42 by sbars             #+#    #+#             */
/*   Updated: 2022/08/09 14:36:32 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	incrementer(int *list, int *low, int *high, int i)
{
	while (list[i] < list[*low] && i <= *high)
		i++;
	return (i);
}

int	decrementer(int	*list, int	*low, int j)
{
	while (list[j] > list[*low] && j >= *low)
		j--;
	return (j);
}

void	quicksort(int *list, int low, int high)
{
	int	i;
	int	j;
	int	temp;

	if (low < high)
	{
		i = low;
		j = high;
		while (i < j)
		{
			i = incrementer(list, &low, &high, i);
			j = decrementer(list, &low, j);
			if (i < j)
			{
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}
		temp = list[j];
		list[j] = list[low];
		list[low] = temp;
		quicksort(list, low, j - 1);
		quicksort(list, j + 1, high);
	}
}

int	*copy_to_int_array(t_meta	*pkg)
{
	int		i;
	int		*copy;
	t_list	*node;

	i = -1;
	copy = (int *)malloc(sizeof(int) * pkg->a_size);
	if (!copy)
		return (0);
	node = pkg->list_a_head;
	while (node != NULL)
	{
		copy[++i] = node->num;
		node = node->next;
	}
	return (copy);
}

int	replace_by_tidy_num(t_meta	*pkg)
{
	int		*copy;
	int		j;
	t_list	*node;

	node = pkg->list_a_head;
	copy = NULL;
	copy = copy_to_int_array(pkg);
	if (!copy)
		return (-1);
	quicksort(copy, 0, pkg->a_size - 1);
	while (node != NULL)
	{
		j = -1;
		while (++j < pkg->a_size)
		{
			if (node->num == copy[j])
				node->num = j;
		}
		node = node->next;
	}
	free(copy);
	return (0);
}
