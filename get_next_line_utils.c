/* ********************heck=full --show-reachable=yes ./a.out */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:24:55 by btan              #+#    #+#             */
/*   Updated: 2023/10/17 16:05:11 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	const char	*ptr;

	if (!s)
		return (0);
	ptr = s;
	while (*ptr)
		ptr++;
	return (ptr - s);
}

void	ft_bzero(void *s, size_t n)
{
	while (n > 0)
		((char *) s)[(n--) - 1] = 0;
}

int	is_newline(const char *s)
{
	char	*end;
	if (!s)
		return (0);
	end = (char *) s;
	while (*end)
	{
		if (*end == '\n')
			return (end - s + 1);
		end++;
	}
	return (0);
}

char	*ft_subdup(const char *s, int end)
{
	char	*dup;
	int	i;

	i = 0;
	dup = ft_calloc(sizeof(char), (ft_strlen(s) + 1));
	if (!dup)
		return (NULL);
	while (i < end)
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int	i;
	int	len1;
	int	len2;
	char	*joined;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined = ft_calloc(sizeof(char), (len1 + len2 + 1));
	if (!joined)
		return (NULL);
	if (!s1)
		s1 = ft_calloc(1, 1);
	while (i < (len1 + len2))
	{
		if (*s1)
			joined[i++] = *(s1++);
		else if (*s2)
			joined[i++] = *(s2++);
	}
	s1 -= len1;
	free((void *) s1);
	return (joined);
}
