/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:23:48 by sbars             #+#    #+#             */
/*   Updated: 2022/08/16 16:36:45 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_isnumber(char	*str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_isdigit(str[i] != 1))
			return (-1);
	}
	return (1);
}

int	ft_tablen(char	**tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		;
	return (i);
}
