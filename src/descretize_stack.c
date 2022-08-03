/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   descretize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:59:42 by sbars             #+#    #+#             */
/*   Updated: 2022/08/03 15:40:26 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void quicksort(int *list, int low, int high)
{
    int	pivot;
	int	i;
	int	j;
	int	temp;

    if (low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while (i < j) 
        {
            while (list[i] < list[pivot] && i <= high)
                i++;
            while (list[j] > list[pivot] && j >= low)
                j--;
            if (i < j)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
        temp = list[j];
        list[j] = list[pivot];
        list[pivot] = temp;
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
	int	*copy;
	int	j;
	t_list	*node;

	j = -1;
	node = pkg->list_a_head;
	copy = NULL;
	copy = copy_to_int_array(pkg);
	if (!copy)
		return (-1);
	quicksort(copy, 0, pkg->a_size - 1);
	// REMOVE
	//while (++i < pkg->a_size)
//		printf("%d\n", copy[i]);
	// REMOVE
	while (node != NULL)
	{
		while (++j < pkg->a_size)
		{
			if (node->num == copy[j])
				node->num = j;
		}
		j = -1;
		node = node->next;
	}
	free(copy);
	return (0);
}
