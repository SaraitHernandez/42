/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:08:29 by sarherna          #+#    #+#             */
/*   Updated: 2024/09/26 17:35:33 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validator.h"

int	is_valid_map(t_map *map)
{
	int	exit_count;
	int	start_count;

	exit_count = 0;
	start_count = 0;
	int valid = has_valid_characters(map, &exit_count, &start_count);
	printf("valid characters: %d\n", valid);
	if (has_valid_characters(map, &exit_count, &start_count) == 0)
		return (0);
	if (exit_count != 1 || map->collectibles_count < 1 || start_count != 1)
		return (0);
	if (is_rectangular(map) == 0)
		return (0);
	if (is_enclosed_in_walls(map) == 0)
		return (0);
	if (has_valid_path(map) == 0)
		return (0);
	return (1);
}

int	has_valid_characters(t_map *map, int *exit_c, int *start_c)
{
	int	i;
	int	j;

	i = 0;
	printf("height %d\n", map->height);
	printf("width %d\n", map->width);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'E')
			{
				(*exit_c)++;
				map->end_x = j;
				map->end_y = i;
			}
			else if (map->map[i][j] == 'C')
				(map->collectibles_count)++;
			else if (map->map[i][j] == 'P')
			{
				(*start_c)++;
				map->start_x = j;
				map->start_y = i;
			}
			else if (map->map[i][j] != '0' && map->map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	printf("valid characters\n");
	return (1);
}

int	is_rectangular(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (!map->map[i] || map_width(&map->map[i]) != map->width)
			return (0);
		i++;
	}
	printf("rectangular\n");
	return (1);
}

int	is_enclosed_in_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			return (0);
		i++;
	}
	printf("enclosed in walls\n");
	return (1);
}

//me hace falta la funcion para liberar memoria
