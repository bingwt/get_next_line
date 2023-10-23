/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:24:40 by btan              #+#    #+#             */
/*   Updated: 2023/10/23 15:43:30 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char	*buffer)
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

	read_bytes = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
		return (NULL);
	if (buffer == NULL)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		read_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	while (ft_strchr(buffer, '\n') == NULL)
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
		if (read_bytes < 1)
			break ;
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
			buffer = NULL;
			return (NULL);
		}
	new = ft_strdup(buffer);
	free(buffer);
	buffer = NULL;
	return (new);
}

//#include <fcntl.h>
//#include <stdio.h>
//int	main()
//{
//	int	fd = open("tests/read_error.txt", O_RDONLY);
//	char	*line = get_next_line(fd);
//	for (int i = 1; i < 16; i++)
//	{
//		printf("Line %d: %s", i, line);
//		free(line);
//		line = get_next_line(fd);
//	}
//}

// int main(void)
// {
//   // Create a temporary file and write test content to it.
//   char test_content[] = 
// 						// "0123456789012345678901234567890123456789x0\n"
// 						// "0123456789012345678901234567890123456789x1\n"
// 						// "0123456789012345678901234567890123456789x2\n"
// 						// "0123456789012345678901234567890123456789x3\n"
// 						// "0123456789012345678901234567890123456789x4\n"
// 						// "0123456789012345678901234567890123456789x5\n"
// 						// "\n"
// 						// "\n"
// 						// "\n"
// 							// "0123456789\n"
// 							// "012345678\n"
// 							// "90123456789\n" //here ownwards weird
// 							// "0123456789\n"
// 							// "xxxx\n"

// 						"\n"
// 						"0123456789012345678901234567890123456789x2\n"
// 						"0123456789012345678901234567890123456789x3\n"
// 						"\n"
// 						"0123456789012345678901234567890123456789x5\n"
// 						"\n"
// 						"\n"
// 						"0123456789012345678901234567890123456789x8\n"
// 						"\n"
// 						"\n"
// 						"\n"
// 						"0123456789012345678901234567890123456789x12";

// 	FILE *temp = fopen("temp_test.txt", "w+");
// 	if (!temp)
// 	{
// 		perror("Error creating temporary file");
// 		return 1;
// 	}
// 	fwrite(test_content, sizeof(char), sizeof(test_content) - 1, temp);
// 	fclose(temp);
// 	// Open the temporary file to read with get_next_line.
// 	int fd = open("temp_test.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening the temporary file");
// 		return 1;
// 	}
// 	int i = 0;
// 	char *line = NULL;
// 	// line = get_next_line(fd);
// 	// printf("res:%s;\n",line);
// 	while ( (line = get_next_line(fd)) != NULL)
// 	{
// 		if (line[0] == '\0')
// 		{
// 			free(line);
// 			break;
// 		}
// 		printf("res%d:%s;\n",i ,line);
// 		free(line);
// 		i ++;
// 	}
// 	close(fd);
// 	// Optionally, remove the temporary file after testing.
// 	remove("temp_test.txt");
// 	return 0;
// }
