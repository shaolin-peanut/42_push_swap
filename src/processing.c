/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:25:34 by sbars             #+#    #+#             */
/*   Updated: 2022/08/11 15:23:58 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	check_repetitions(int num, t_meta *pkg)
{
	int		i;
	t_list	*current_node;

	i = -1;
	current_node = pkg->list_a_head;
	while (current_node != NULL)
	{
		if (num == current_node->num)
			errormsg("Error\n", pkg);
		current_node = current_node->next;
	}
	i = 1;
	return (i);
}

// Where all the cool stuff is coordinated
int	war_room(int c, char	**argv)
{
	int		i;
	int		tmp_num;
	char	**str;
	t_meta	*pkg;

	pkg = NULL;
	pkg = init_pkg(pkg);
	if (c == 2)
	{
		c = count_digits(argv[1], ' ');
		argv = ft_split(argv[1], ' ');
		//argv = str;
		//free(str);
	}
	else
	{
		argv = (argv + 1);
		c -= 1;
	}
	i = c;
	while (--i > -1 /*&& argv[i - 1] != NULL*/)
	{
		// Don't forget to check min and max int
		if (*argv[i] == '0')
			tmp_num = 0;
		else
			tmp_num = ft_atoi(argv[i]);
		if (check_repetitions(tmp_num, pkg) == -1)
			errormsg("Error\n", pkg);
		else
			pkg->list_a_head = put(tmp_num, pkg);
	}
	if (is_sorted(pkg->list_a_head) == -1)
		sort(pkg);
	if (c == 2)
		free(argv);
	free_all(pkg);
	return (1);
}
