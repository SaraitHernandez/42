/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:14:14 by sarherna          #+#    #+#             */
/*   Updated: 2024/07/12 20:12:12 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd, char *leftover);
static char	*extract_line(char **leftover);
char		*buffer_join(char *leftover, char *buffer);

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	leftover = read_file(fd, leftover);
	if (!leftover || *leftover == '\0')
	{
		free(leftover);
		leftover = NULL;
		return (NULL);
	}
	line = extract_line(&leftover);
	return (line);
}

static char	*read_file(int fd, char *leftover)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		if (!leftover)
			leftover = ft_strdup(buffer);
		else
			leftover = buffer_join(leftover, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (bytes_read == -1)
		return (NULL);
	return (leftover);
}

static char	*extract_line(char **leftover)
{
	char	*line;
	char	*new_leftover;
	char	*newline_pos;

	newline_pos = ft_strchr(*leftover, '\n');
	if (newline_pos)
	{
		line = ft_substr(*leftover, 0, newline_pos - *leftover + 1);
		new_leftover = ft_substr(newline_pos + 1, 0,
				ft_strlen(newline_pos + 1));
		free(*leftover);
		*leftover = new_leftover;
	}
	else
	{
		line = ft_strdup(*leftover);
		free(*leftover);
		*leftover = NULL;
	}
	return (line);
}

char	*buffer_join(char *leftover, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(leftover, buffer);
	free(leftover);
	return (temp);
}
