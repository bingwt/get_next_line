/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:24:40 by btan              #+#    #+#             */
/*   Updated: 2023/10/17 12:40:42 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;

	arr = malloc(nmemb * size);
	if (!arr)
		return (NULL);
	ft_bzero(arr, nmemb * size);
	return (arr);
}

char	*ft_realloc(char *buffer)
{
	char	*temp;

	temp = ft_calloc(1, 1);
	temp = ft_strjoin(temp, buffer + is_newline(buffer) + 1);
	free (buffer);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		raw[BUFFER_SIZE + 1];
	int			read_bytes;
	char		*line;

	if (fd > 0)
	{
		if (is_newline(buffer))
			buffer = ft_realloc(buffer);
		ft_bzero(raw, BUFFER_SIZE);
		read_bytes = read(fd, raw, BUFFER_SIZE);
		buffer = ft_strjoin(buffer, raw);
		while (!is_newline(buffer) && read_bytes)
		{
			read_bytes = read(fd, raw, BUFFER_SIZE);
			buffer = ft_strjoin(buffer, raw);
		}
		if (!buffer[is_newline(buffer)] && !read_bytes)
		{
			line = ft_subdup(buffer, is_newline(buffer));
			free(buffer);
			return (line);
		}
		return (ft_subdup(buffer, is_newline(buffer)));
	}
	return (NULL);
}
/*{
	static char	*buffer;
	char		*line;
	int		end;

	while (!is_newline(buffer))
	{
		read(fd, buffer, BUFFER_SIZE);
		end = is_newline(buffer);
		if (end)
		{
			line = ft_subdup(buffer, end);
			buffer = buffer + end;
			return (line);
		}
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	int	buffer_index;
	int	read_bytes;
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
}*/
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
	chark-check=full --show-leak-kinds=all	*temp;


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

	tne);
	emp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
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
		e	renurn (line);
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

	char	*line = get_next_line(fd);
	printf("Line 1: %s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("Line 2: %s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("Line 3: %s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("Line 4: %s\n", line);
	free(line);
}
