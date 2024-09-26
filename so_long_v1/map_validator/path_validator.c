/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:40:26 by sarherna          #+#    #+#             */
/*   Updated: 2024/09/26 15:46:43 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validator.h"

int	has_valid_path(t_map *map)
{
	int		collectibles_count;
	int		exit_count;
	int	**visited;

	visited = create_visited_array(map);
	collectibles_count = 0;
	exit_count = 0;
	flood_fill(map, map->start_x, map->start_y, visited, &collectibles_count, &exit_count);
	free_visited_array(visited, map->height);
	return (collectibles_count == map->collectibles_count && exit_count > 0);
}

int	**create_visited_array(t_map *map)
{
	int	**visited;

	visited = (int **)malloc(sizeof(int *) * map->height);
	for (int i = 0; i < map->height; i++)
	{
		visited[i] = (int *)malloc(sizeof(int) * map->width);
		for (int j = 0; j < map->width; j++)
			visited[i][j] = 0;
	}
	return (visited);
}

void	free_visited_array(int **visited, int height)
{
	for (int i = 0; i < height; i++)
		free(visited[i]);
	free(visited);
}

void	flood_fill(t_map *map, int x, int y, int **visited, int *collectibles_count, int *exit_count)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height || visited[y][x])
		return;
	if (map->map[y][x] == '1')
		return;
	visited[y][x] = 1;
	if (map->map[y][x] == 'C')
		(*collectibles_count)++;
	else if (map->map[y][x] == 'E')
		(*exit_count)++;
	flood_fill(map, x + 1, y, visited, collectibles_count, exit_count);
	flood_fill(map, x - 1, y, visited, collectibles_count, exit_count);
	flood_fill(map, x, y + 1, visited, collectibles_count, exit_count);
	flood_fill(map, x, y - 1, visited, collectibles_count, exit_count);
}
