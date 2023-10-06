/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:24:55 by btan              #+#    #+#             */
/*   Updated: 2023/10/05 17:19:16 by btan             ###   ########.fr       */
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

int	is_end(const char c)
{
	if (c == '\n')
		return (1);
	return (0);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int	i;
	int	len;
	char	*joined;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	joined = malloc(sizeof(char) * (len + 1));
	if (!joined)
		return (NULL);
	while (i < len)
	{
		if (*s1)
			joined[i++] = *(s1++);
		else if (*s2)
			joined[i++] = *(s2++);
	}
	joined[len] = '\0';
	return (joined);
}
