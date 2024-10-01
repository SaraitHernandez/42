/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_constructor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarait.hernandez@novateva.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:52:28 by sarherna          #+#    #+#             */
/*   Updated: 2024/10/01 14:42:51 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

int	map_width(char **map)
{
	int	width;

	width = 0;
	while (map[0][width] != '\0' && map[0][width] != '\n'
			&& map[0][width] != '\r')
		width++;
	return (width);
}

int	map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

int	start_end_coodinates(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'E')
			{
				map->end_x = j;
				map->end_y = i;
			}
			else if (map->map[i][j] == 'P')
			{
				map->start_x = j;
				map->start_y = i;
			}
			j++;
		}
		i++;
	}
	return (1);
}

t_map	*create_map(char **map_data)
{
	t_map	*new_map;

	new_map = (t_map *)malloc(sizeof(t_map));
	if (!new_map)
		ft_error("Allocation error.", NULL);
	new_map->map = map_data;
	new_map->width = map_width(map_data);
	new_map->height = map_height(map_data);
	start_end_coodinates(new_map);
	new_map->collectibles_count = 0;
	return (new_map);
}
