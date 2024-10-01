/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarait.hernandez@novateva.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:40:26 by sarherna          #+#    #+#             */
/*   Updated: 2024/10/01 17:18:11 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

int	has_valid_path(t_map *map)
{
	t_flood_fill_data	data;

	data.map = map;
	data.collectibles = 0;
	data.exit_count = 0;
	data.visited = create_visited_array(map);
	flood_fill(&data, map->start_x, map->start_y);
	free_doble_array(data.visited);
	return (data.collectibles == map->collectibles && data.exit_count > 0);
}

int	**create_visited_array(t_map *map)
{
	int	**visited;
	int	i;
	int	j;

	i = 0;
	visited = (int **)malloc(sizeof(int *) * map->height);
	while (i < map->height)
	{
		visited[i] = (int *)malloc(sizeof(int) * map->width);
		j = 0;
		while (j < map->width)
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
	return (visited);
}

void	flood_fill(t_flood_fill_data *data, int x, int y)
{
	if (x < 0 || x >= data->map->width || y < 0 || y >= data->map->height
		|| data->visited[y][x])
		return ;
	if (data->map->map[y][x] == '1')
		return ;
	data->visited[y][x] = 1;
	if (data->map->map[y][x] == 'C')
		data->collectibles++;
	else if (data->map->map[y][x] == 'E')
		data->exit_count++;
	flood_fill(data, x + 1, y);
	flood_fill(data, x - 1, y);
	flood_fill(data, x, y + 1);
	flood_fill(data, x, y - 1);
}
