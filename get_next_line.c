/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:24:40 by btan              #+#    #+#             */
/*   Updated: 2023/10/22 16:34:40 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*















































//char	*ft_strallocjoin(char *s1, char *s2)
//{
//	int	len1;
//	int	len2;
//	char	*joined;
//
//	len1 = ft_strlen(s1);
//	len2 = ft_strlen(s2);
//	joined = ft_calloc(len1 + len2 + 1, sizeof(char));
//	while (len2--)
//		joined[len1 + len2] = s2[len2];
//	while (len1--)
//		joined[len1] = s1[len1];
//	free(s1);
//	free(s2);
//	return (joined);
//}
//
//char	*ft_linedup(char *buffer)
//{
//	int	i;
//	char	*original;
//	char	*line;
//	int	len;
//
//	i = 0;
//	original = buffer;
//	free(buffer);
//	buffer = NULL;
//	line = ft_calloc((is_newline(original) + 1), sizeof(char));
//	len = is_newline(original);
//	if (!dup)
//		return (NULL);
//	while (i < len)
//	{
//		line[i] = buffer[i];
//		i++;
//	}
//	if (original[i])
//		buffer = ft_strdup(original + ft_strlen(len);
//	return (line);
//}
//
//char	*get_next_line(int fd)
//{
//	static char	*buffer = NULL;
//	int		read_bytes;
//	char		*temp;
//
//	if (fd >= 0 && BUFFER_SIZE > 0 && read(fd, buffer, 0) > -1)
//	{
//		if (!buffer)
//		{
//			buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
//			read_bytes = read(fd, buffer, BUFFER_SIZE);
//		}
//		while (!is_newline(buffer))
//		{
//			temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
//			read_bytes = read(fd, temp, BUFFER_SIZE);
//			buffer = ft_strallocjoin(buffer, temp);
//		}
//		if (!is_newline(buffer))
//		{
//			temp = ft_strdup(buffer);
//			free(buffer);
//			return (temp);
//		}
//		return (ft_linedup(buffer));
//	}
//	return (NULL);
//}































//char	*ft_realloc(char *buffer)
//{
//	char	*temp;
//
//	temp = ft_calloc(1, 1);
//	temp = ft_strjoin(temp, buffer + is_newline(buffer));
//	free (buffer);
//	buffer = NULL;
//	return (temp);
//}
//
//char	*get_next_line(int fd)
//{
//	static char	*buffer = NULL;
//	int		read_bytes;
//	char	*temp;
//	char	*line;
//
//	if (is_not_empty(buffer) && is_newline(buffer))
//		buffer = ft_realloc(buffer);
//	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
//	read_bytes = read(fd, buffer, BUFFER_SIZE);
//	if (fd >= 0 && BUFFER_SIZE > 0 && read_bytes)
//	{
//		while (!is_newline(buffer))
//		{
//			temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
//			read_bytes = read(fd, temp, BUFFER_SIZE);
//			buffer = ft_strjoin(buffer, temp);
//			free(temp);
//		
//			if (!read_bytes && is_not_empty(buffer))
//			{
//				line = ft_strndup(buffer, ft_strlen(buffer));
//				free(buffer);
//				return (line);
//			}
//		}
//		line = ft_strndup(buffer, is_newline(buffer));
//		return (line);
//	}
//	free(buffer);
//	return (NULL);
//}
//
//void	*ft_calloc(size_t nmemb, size_t size)
//{
//	void	*arr;
//
//	arr = malloc(nmemb * size);
//	if (!arr)
//		return (NULL);
//	ft_bzero(arr, nmemb * size);
//	return (arr);
//}
//
//char	*ft_realloc(char *buffer)
//{
//	char	*temp;
//
//	temp = ft_calloc(1, 1);
//	temp = ft_strjoin(temp, buffer + is_newline(buffer));
//	free (buffer);
//	buffer = NULL;
//	return (temp);
//}
//
//char	*get_next_line(int fd)
//{
//	static char	*buffer = NULL;
//	char		raw[BUFFER_SIZE + 1];
//	int			read_bytes;
//	char		*line;
//
//	if (fd >= 0 || BUFFER_SIZE > 0)
//	{
//		ft_bzero(raw, BUFFER_SIZE + 1);
//		if (is_newline(buffer))
//			buffer = ft_realloc(buffer);
//		read_bytes = read(fd, raw, BUFFER_SIZE);
//		buffer = ft_strjoin(buffer, raw);
//		while (!is_newline(buffer) && read_bytes)
//		{
//			read_bytes = read(fd, raw, BUFFER_SIZE);
//			buffer = ft_strjoin(buffer, raw);
//		}
//		if (!read_bytes && !is_newline(buffer))
//		{
//			line = ft_subdup(buffer, is_newline(buffer));
//			free(buffer);
//			buffer = NULL;
//			return (line);
//		}
//		return (ft_subdup(buffer, is_newline(buffer)));
//	}
//	return (NULL);
//}
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
	cha_SIZE + 1];FFER_SIZE];
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
	line = get_next_line(fd);
	printf("Line 5: %s\n", line);
	free(line);
}
