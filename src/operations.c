/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:03:05 by sbars             #+#    #+#             */
/*   Updated: 2022/08/10 11:08:42 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_meta	*pkg)
{
	t_list	*node_a;
	t_list	*node_b;
	t_list	*node_c;

	if (pkg->a_size < 2)
		return (0);
	// set placeholders
	node_a = pkg->list_a_head;
	node_b = node_a->next;
	node_c = node_b->next;
	// swap
	node_b->next = node_a;
	node_a->previous = node_b;
	node_b->previous = NULL;
	node_a->next = node_c;
	if (node_c != NULL)
		node_c->previous = node_a;
	pkg->list_a_head = node_b;
	write(1, "sa\n", 3);
	return (0);
}

int	sb(t_meta	*pkg)
{
	t_list	*node_a;
	t_list	*node_b;
	t_list	*node_c;

	if (pkg->b_size < 2)
		return (0);
	// set placeholders
	node_a = pkg->list_b_head;
	node_b = node_a->next;
	node_c = node_b->next;
	// swap
	node_b->next = node_a;
	node_a->previous = node_b;
	node_b->previous = NULL;
	node_a->next = node_c;
	if (node_c != NULL)
		node_c->previous = node_a;
	pkg->list_b_head = node_b;
	write(1, "sb\n", 3);
	return (0);
}

void	ss(t_meta	*pkg)
{
	sa(pkg);
	sb(pkg);
}

// don't forget to increment list size every time you push to a list
int	pa(t_meta	*pkg)
{
	t_list	*a_head;
	t_list	*b_head;

	if (pkg->b_size < 1)
		return (0);
	// cut b_head and relink meta to next b node
	a_head = pkg->list_a_head;
	b_head = pkg->list_b_head;
	if (pkg->b_size == 1)
	{
		pkg->list_b_head = NULL;
	}
	else
	{
		pkg->list_b_head = pkg->list_b_head->next;
		pkg->list_b_head->previous = NULL;
	}
	// push b_head on a list
	connect_ab(b_head, a_head);
	pkg->list_a_head = b_head;
	update_list_butt(pkg);
	pkg->a_size++;
	pkg->b_size--;
	write(1, "pa\n", 3);
	return (0);
}

int	pb(t_meta	*pkg)
{
	t_list	*a_head;
	t_list	*b_head;

	if (pkg->a_size < 2)
		return (0);
	// save a_head and link meta to next a node
	b_head = pkg->list_b_head;
	a_head = pkg->list_a_head;
	pkg->list_a_head = pkg->list_a_head->next;
	pkg->list_a_head->previous = NULL;
	// push a_head on b list
	connect_ab(a_head, b_head);
	pkg->list_b_head = a_head;
	update_list_butt(pkg);
	pkg->a_size--;
	pkg->b_size++;
	write(1, "pb\n", 3);
	return (0);
}
