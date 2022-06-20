/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:10:40 by sbars             #+#    #+#             */
/*   Updated: 2021/11/02 14:10:46 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		z;
	char	*output;

	i = 0;
	z = 0;
	j = ft_strlen((char *) s1) - 1;
	while (((ft_strchr(set, s1[i])) || s1[i] == ' ') && s1[i])
		i++;
	while (((ft_strchr(set, s1[j])) || s1[j] == ' ') && s1[i])
		j--;
	if (i > j)
		return (ft_calloc(1, 1));
	output = malloc(sizeof(char) * ((j - i)));
	if (output)
	{
		while (s1[i] && i < j + 1)
		{	
			output[z++] = s1[i++];
		}
		output[z] = '\0';
	}
	return (output);
}
