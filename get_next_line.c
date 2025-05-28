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
	char	*old_storage;
	char	*tmp;
	int		bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	if (!storage)
		storage = ft_strdup("");
	while (!ft_strchr(storage, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buffer), NULL);
		buffer[bytes] = '\0';
		old_storage = storage;
		tmp = ft_strjoin(storage, buffer);
		free(old_storage);
		storage = tmp;
		if (bytes == 0)
			break ;
	}
	return (free(buffer), storage);
}

char	*extract_line(char *storage)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (!storage || !*storage)
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = storage[j];
		j++;
	}
	line[i] = '\0';
	return (line);
}

char	*update_storage(char *storage, char *line)
{
	size_t	len;
	char	*updated;

	len = ft_strlen(line);
	if (!storage || !line)
		return (NULL);
	if (len >= ft_strlen(storage))
		return (NULL);
	updated = ft_strndup(storage, len);
	return (updated);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = read_until_newline(fd, storage);
	if (!storage)
		return (NULL);
	line = extract_line(storage);
	tmp = update_storage(storage, line);
	free(storage);
	storage = tmp;
	if	(!line || (storage && *storage == '\0'))
	{
		free(storage);
		storage = NULL;
	}
	return (line);
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
