/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:24:55 by btan              #+#    #+#             */
/*   Updated: 2023/10/24 14:40:18 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	char	*ptr;

	ptr = s;
	while (*ptr)
		ptr++;
	return (ptr - s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*arr;

	arr = malloc(nmemb * size);
	if (!arr)
		return (NULL);
	while (nmemb > 0)
		arr[--nmemb] = 0;
	arr[nmemb] = 0;
	return ((void *) arr);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
		if (*(str++) == c)
			return ((char *) str);
	return (NULL);
}
