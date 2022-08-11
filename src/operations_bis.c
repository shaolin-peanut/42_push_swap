/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:27:41 by sbars             #+#    #+#             */
/*   Updated: 2022/08/09 15:52:53 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ra(t_meta	*pkg)
{
	t_list	*head;

	if (pkg->a_size < 2)
		return (0);
	head = save_and_cut_head('a', pkg);
	update_list_butt(pkg);
	pkg->list_a_butt->next = head;
	head->previous = pkg->list_a_butt;
	pkg->list_a_butt = head;
	write(1, "ra\n", 3);
	return (0);
}

int	rb(t_meta	*pkg)
{
	t_list	*head;

	if (pkg->b_size < 2)
		return (0);
	head = save_and_cut_head('b', pkg);
	update_list_butt(pkg);
	pkg->list_b_butt->next = head;
	head->previous = pkg->list_b_butt;
	pkg->list_b_butt = head;
	write(1, "rb\n", 3);
	return (0);
}

int	rra(t_meta	*pkg)
{
	t_list	*butt;

	if (pkg->a_size < 2)
		return (0);
	update_list_butt(pkg);
	butt = pkg->list_a_butt;
	if (pkg->list_a_butt->previous != NULL)
		pkg->list_a_butt = pkg->list_a_butt->previous;
	pkg->list_a_butt->next = NULL;
	butt->previous = NULL;
	butt->next = pkg->list_a_head;
	pkg->list_a_head->previous = butt;
	pkg->list_a_head = butt;
	update_list_butt(pkg);
	write(1, "rra\n", 4);
	return (0);
}

int	rrb(t_meta	*pkg)
{
	t_list	*butt;

	if (pkg->b_size < 2)
		return (0);
	update_list_butt(pkg);
	butt = pkg->list_b_butt;
	if (pkg->list_b_butt->previous != NULL)
		pkg->list_b_butt = pkg->list_b_butt->previous;
	pkg->list_b_butt->next = NULL;
	butt->previous = NULL;
	butt->next = pkg->list_b_head;
	pkg->list_b_head->previous = butt;
	pkg->list_b_head = butt;
	update_list_butt(pkg);
	write(1, "rrb\n", 4);
	return (0);
}

int	rr(char sign, t_meta *pkg)
{
	if (sign == 0)
	{
		ra(pkg);
		rb(pkg);
	}
	else if (sign == -1)
	{
		rra(pkg);
		rrb(pkg);
	}
	else
		return (-1);
	return (0);
}
