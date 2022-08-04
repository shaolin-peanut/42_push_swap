/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:30:39 by sbars             #+#    #+#             */
/*   Updated: 2022/08/04 16:32:07 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_sqrt(int nbr)
{
	int	sqrt;

	if (nbr < 0)
		return (0);
	sqrt = 0;
	while (sqrt * sqrt < nbr)
	{
		sqrt++;
		if (sqrt * sqrt == nbr)
			return (sqrt / 1.5);
	}
	return (sqrt / 1.5);
}

int	is_sorted(t_list	*head)
{
	while (head != NULL && head->next != NULL)
	{
		if (head->num > head->next->num)
			return (-1);
		head = head->next;
	}
	return (1);
}

int	list_min(t_list	*list, int limit)
{
	int	min;
	int	i;

	i = -1;
	if (list)
		min = list->num;
	else
		return (min = 0);
	while (list != NULL && ++i < limit)
	{
		if (list->num < min)
			min = list->num;
		list = list->next;
	}
	return (min);
}

int	list_max(t_list	*list, int limit)
{
	int	max;
	int	i;

	i = -1;
	if (list)
		max = list->num;
	else
		return (max = 0);
	while (list != NULL && ++i < limit)
	{
		if (list->num > max)
			max = list->num;
		list = list->next;
	}
	return (max);
}

int	choose_pivot(t_list	*list, int limit)
{
	int	range;

	range = list_min(list, limit) + list_max(list, limit);
	return (range / get_sqrt(limit));
}
