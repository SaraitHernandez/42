/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:46:25 by sarherna          #+#    #+#             */
/*   Updated: 2024/10/08 14:23:20 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	count_rows(const char *filename)
{
	char	*line;
	int		row_count;
	int		fd;

	row_count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error("Error opening the file.", NULL);
	line = get_next_line(fd, 0);
	while (line != NULL)
	{
		row_count++;
		free(line);
		line = get_next_line(fd, 0);
	}
	close(fd);
	if (row_count <= 0)
		ft_error("The file is empty.", NULL);
	return (row_count);
}

char	**malloc_map_data(int file_rows)
{
	char	**map_data;

	map_data = malloc(sizeof(char *) * (file_rows + 1));
	if (!map_data)
		ft_error("Allocation error.", NULL);
	return (map_data);
}

char	**load_map(int fd, const char *filename)
{
	char	*line;
	int		row_count;
	char	**map_data;
	int		file_rows;

	file_rows = count_rows(filename);
	map_data = malloc_map_data(file_rows);
	row_count = 0;
	while (row_count < file_rows)
	{
		line = get_next_line(fd, 0);
		map_data[row_count] = ft_strdup(line);
		free(line);
		if (!map_data[row_count])
		{
			ft_error("String duplication error.", NULL);
			free_doble_array(map_data);
			close(fd);
		}
		row_count++;
	}
	line = get_next_line(fd, 1);
	map_data[row_count] = NULL;
	return (map_data);
}

t_map	*build_map(const char *filename)
{
	int		fd;
	char	**map_data;
	t_map	*map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error("Error opening the file.", NULL);
	map_data = load_map(fd, filename);
	close(fd);
	map = create_map(map_data);
	return (map);
}
