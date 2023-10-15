/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:24:55 by btan              #+#    #+#             */
/*   Updated: 2023/10/15 17:22:01 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	const char	*end;

	end = s;
	while (*end)
		end++;
	return (end - s);
}

void	ft_bzero(void *s, size_t n)
{
	while (n > 0)
		((char *) s)[(n--) - 1] = '\0';
}

int	is_newline(const char *s)
{
	char	*end;

	end = (char *) s;
	while (*end)
	{
		if (*end == '\n')
			return (end - s);
		end++;
	}
	return (0);
}

char	*ft_subdup(const char *s, int end)
{
	char	*dup;
	int	i;

	i = 0;
	dup = malloc(sizeof(char) * (end + 1));
	if (!dup)
		return (NULL);
	while (i < end)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
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
	joined = malloc(sizeof(char) * (len1 + len2));
	if (!joined)
	{
		free((void *) s1);
		return (NULL);
	}
	while (i < (len1 + len2))
	{
		if (*s1)
			joined[i++] = *(s1++);
		else if (*s2)
			joined[i++] = *(s2++);
	}
	joined[i] = '\0';
	s1 -= len1;
	if (ft_strlen(s1))
		free((void *) s1);
	return (joined);
}
