/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:24:40 by btan              #+#    #+#             */
/*   Updated: 2023/10/11 01:54:19 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	int	buffer_index;
	static int	read_bytes;
	char	buffer[BUFFER_SIZE];
	char	*line;
	
	line = "";
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	while (read_bytes > 0)
	{
		buffer_index = 0;
		while (buffer_index < BUFFER_SIZE)
		{
			if (buffer[buffer_index + BUFFER_SIZE - 1] == '\n')
			{
				line = ft_strjoin(line, &buffer[buffer_index]);
				return (line);
			}
			line = ft_strjoin(line, &buffer[buffer_index]);
			buffer_index += BUFFER_SIZE;
		}
		read_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	return (line);
}
/*{
	char	buffer[BUFFER_SIZE];
	char	*ptr;
	int	i;

	line = malloc(sizeof(char) * 1000);
	ptr = line;
	buffer[BUFFER_SIZE - 1] = '\0';
	while (*buffer != '\n')
	{
		i = 0;
		if (BUFFER_SIZE == 1)
			{
				read(fd, buffer, BUFFER_SIZE);
				*ptr = buffer[i++];
				ptr++;
			}
		else
			read(fd, buffer, BUFFER_SIZE - 1);
		while (i < BUFFER_SIZE - 1)
		{
			*ptr = buffer[i++];
			ptr++;
		}
	}
	*ptr = '\0';
	return (line);
}

{
	int	i;
	char	buffer[BUFFER_SIZE];
	int	offset;
	int	bytes;
	char	*temp;


	if (line)
		free(line);
	line = "";
	offset = 0;
	bytes = 0;
	while (1)
	{
		if (offset >= bytes)
		{
			bytes = read(fd, buffer, BUFFER_SIZE);
			offset = 0;
		}
		if (bytes <= 0)
			return (line);
		i = offset;
		while (i < bytes)
		{
			temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
			if (!temp)
				return (NULL);
			if (buffer[i] == '\n')
			{
				line = ft_strjoin(line, buffer + offset);
				offset = i + 1;
				free(temp);
				return (line);
			}
			temp[i] = (buffer + offset)[i];
			i++;
		}
		line = ft_strjoin(line, buffer + offset);
		offset = bytes;
	}
}

static char	*line;

char	*get_next_line(int fd)
{

	int	i;
	char	buffer[BUFFER_SIZE];
	char	*temp;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	line = "";
	while (read(fd, buffer, BUFFER_SIZE))
	{
		i = 0;
		while (i < BUFFER_SIZE)
		{
			if (buffer[i] == '\n')
			{
				free(temp);
				return (line);
			}
			temp[i] = buffer[i];
			i++;
		}
		temp[i] = '\0';
		line = ft_strjoin(line, temp);
		if (buffer[i] == '\n')
		{
			free(temp);
			return (line);
		}
	}
	return (line);
}
*/
#include <stdio.h>
#include <fcntl.h>
int	main()
{
	int fd = open("tests/test.txt", O_RDONLY);

	printf("Line 1: %s\n", get_next_line(fd));
	printf("Line 2: %s\n", get_next_line(fd));
	printf("Line 3: %s\n", get_next_line(fd));
	printf("Line 4: %s\n", get_next_line(fd));
}
