/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:25:09 by sbars             #+#    #+#             */
/*   Updated: 2022/08/16 16:28:37 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
// REMOVE AFTER
#include <stdio.h>

t_meta	*init_pkg(t_meta *pkg)
{
	pkg = (t_meta *)malloc(sizeof(t_meta) * 1);
	if (!pkg)
		errormsg("Error\n", pkg);
	pkg->list_a_head = 0;
	pkg->list_a_butt = 0;
	pkg->a_size = 0;
	pkg->list_b_head = 0;
	pkg->list_b_butt = 0;
	pkg->b_size = 0;
	return (pkg);
}

void	errormsg(char *msg, t_meta	*pkg)
{
	int	i;

	i = -1;
	while (msg[++i])
		write(2, &msg[i], 1);
	free_all(pkg);
	exit(EXIT_FAILURE);
}

void	free_all(t_meta	*pkg)
{
	if (pkg->list_a_head != 0)
		free_list(pkg->list_a_head);
	if (pkg->list_b_head != 0)
		free_list(pkg->list_b_head);
	free(pkg);
}

void	free_list(t_list *list)
{
	t_list	*current_node;

	current_node = NULL;
	while (list != NULL)
	{
		current_node = list;
		list = list->next;
		free(current_node);
	}
}
