/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-g <jpedro-g@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:24:27 by jpedro-g          #+#    #+#             */
/*   Updated: 2025/05/26 11:23:05 by jpedro-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_until_newline(int fd, char *storage)
{
	char	*buffer;
	int		bytes;
	
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return(NULL);
	bytes = 1;

	while (!ft_strchr(buffer, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return(free(buffer), NULL);
		buffer[bytes] = '\0';
		storage = ft_strjoin(storage, buffer);
		if (bytes == 0)
			break;
	}
	return (free(buffer), (storage));
}

char	*extract_line(char	*storage)
{
	int	i;
	char	*line;

	i = 0;
	
	if (!storage && !*storage)
		return(NULL);
	while (storage && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return(NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
	{
		line[i] = storage[i];
		i++;
	}
	line[i] = '\0';
	return(line);
}

char	*update_storage(char *storage, char *line)
{
	size_t	len;
	char	*updated_storage;

	len = ft_strlen(line);
	if (!line)
		return(NULL);
	updated_storage = ft_strndup(storage, len);
	return(free(storage), updated_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (!line)
		return(NULL);
	storage = 0;
	storage = read_until_newline(fd, storage);
	line = extract_line(storage);
	storage = update_storage(storage, line);
	return(line);
}

#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
}
