/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:24:55 by btan              #+#    #+#             */
/*   Updated: 2023/10/23 09:44:25 by btan             ###   ########.fr       */
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

char	*ft_strdup(char *s)
{
	int		len;
	char	*dup;

	len = ft_strlen(s);
	dup = ft_calloc(len + 1, sizeof(char));
	while (len--)
		dup[len] = s[len];
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*joined;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined = ft_calloc(len1 + len2 + 1, sizeof(char));
	while (len2--)
		joined[len1 + len2] = s2[len2];
	while (len1--)
		joined[len1] = s1[len1];
	return (joined);
}
