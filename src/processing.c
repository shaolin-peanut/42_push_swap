/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:25:34 by sbars             #+#    #+#             */
/*   Updated: 2022/08/16 16:35:04 by sbars            ###   ########.fr       */
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

int	min_max(int num)
{
	if (num > INT_MAX)
		return (-1);
	else if (num < INT_MIN)
		return (-1);
	else
		return (1);
}

// Where all the cool stuff is coordinated
int	parsing_multi_args(int c, char	**argv)
{
	int		tmp_num;
	t_meta	*pkg;

	pkg = NULL;
	pkg = init_pkg(pkg);
	argv = (argv + 1);
	c -= 1;
	while (--c > -1 && argv[c - 1] != NULL)
	{
		if (*argv[c] == '0')
			tmp_num = 0;
		else if (ft_isnumber(argv[c]) != 1)
			errormsg("Error\n", pkg);
		else
			tmp_num = ft_atoi(argv[c]);
		if (check_repetitions(tmp_num, pkg) == -1 || min_max(tmp_num) == -1)
			errormsg("Error\n", pkg);
		else
			pkg->list_a_head = put(tmp_num, pkg);
	}
	if (is_sorted(pkg->list_a_head) == -1)
		sort(pkg);
	free_all(pkg);
	return (1);
}

void	free_str(char	**str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

int	parsing_one_arg(int c, char	**argv)
{
	int		i;
	int		tmp_num;
	char	**str;
	t_meta	*pkg;

	pkg = NULL;
	pkg = init_pkg(pkg);
	str = ft_split(argv[1], ' ');
	i = ft_tablen(str);
	while (--i > -1)
	{
		if (*str[i] == '0')
			tmp_num = 0;
		else
			tmp_num = ft_atoi(str[i]);
		if (check_repetitions(tmp_num, pkg) == -1 || min_max(tmp_num) == -1)
			errormsg("Error\n", pkg);
		else
			pkg->list_a_head = put(tmp_num, pkg);
	}
	if (is_sorted(pkg->list_a_head) == -1)
		sort(pkg);
	free_str(str);
	free_all(pkg);
	return (1);
}
