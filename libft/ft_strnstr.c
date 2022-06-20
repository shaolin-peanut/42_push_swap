/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:51:49 by sbars             #+#    #+#             */
/*   Updated: 2021/10/19 11:51:51 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	int		counter;

	i = -1;
	j = -1;
	counter = 0;
	if (haystack == needle || (ft_strlen((char *)needle) == 0))
		return ((char *) haystack);
	while (haystack[++i] || i < (int) len)
	{
		while (needle[++j] && (i + j) < ft_strlen((char *)haystack) - counter)
		{
			if (haystack[i + j] == needle[j])
				++counter;
			else
				counter = 0;
			if (counter == ft_strlen((char *)needle))
				return ((char *) &haystack[i]);
			if (ft_strlen((char*)haystack) + j > ft_strlen((char *)haystack))
				return (NULL);
		}
		j = -1;
	}
	return (NULL);
}
