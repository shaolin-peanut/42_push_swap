/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:24:16 by sbars             #+#    #+#             */
/*   Updated: 2022/08/15 15:57:37 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	else if (argc == 2)
		parsing_one_arg(argc, argv);
	else
		parsing_multi_args(argc, argv);
	return (0);
}
