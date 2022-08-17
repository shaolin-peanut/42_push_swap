/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:23:48 by sbars             #+#    #+#             */
/*   Updated: 2022/08/17 16:28:44 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_isnumber(char	*str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[i]) != 1 && str[i] != '-')
		return (-1);
	while(str[++i])
	{
		if (ft_isdigit(str[i]) != 1)
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
