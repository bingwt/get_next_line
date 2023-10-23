/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:24:40 by btan              #+#    #+#             */
/*   Updated: 2023/10/23 09:40:46 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char	*buffer)
{
	int		len;
	char	*temp;

	len = 0;
	while (buffer[len] != '\n')
		len++;
	len++;
	temp = ft_calloc(len + 1, sizeof(char));
	while (len--)
		temp[len] = buffer[len];
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	int			read_bytes;
	char		*temp;
	char		*new;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
		return (NULL);
	if (buffer == NULL)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		read_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	while (ft_strchr(buffer, '\n') == NULL && read_bytes)
	{
		temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		read_bytes = read(fd, temp, BUFFER_SIZE);
		new = ft_strjoin(buffer, temp);
		free(buffer);
		buffer = NULL;
		free(temp);
		temp = NULL;
		buffer = ft_strdup(new);
		free(new);
		new = NULL;
	}
	if (ft_strchr(buffer, '\n') != NULL)
	{
		new = get_line(buffer);
		temp = ft_strdup(ft_strchr(buffer, '\n'));
		free(buffer);
		buffer = NULL;
		buffer = ft_strdup(temp);
		free(temp);
		temp = NULL;
		if (!*buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		return (new);
	}
	if (!*buffer)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

//#include <fcntl.h>
//#include <stdio.h>
//int	main()
//{
//	int	fd = open("tests/test.txt", O_RDONLY);
//	char	*line = get_next_line(fd);
//
//	for (int i = 1; i < 6; i++)
//	{
//		printf("Line %d: %s", i, line);
//		free(line);
//		line = get_next_line(fd);
//	}
//}
