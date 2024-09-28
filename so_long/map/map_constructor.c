/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_constructor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarait.hernandez@novateva.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:52:28 by sarherna          #+#    #+#             */
/*   Updated: 2024/09/28 17:49:56 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	map_width(char **map)
{
	int	width;

	width = 0;
	while (map[0][width] != '\0' && map[0][width] != '\n' && map[0][width] != '\r')
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

t_map	*create_map(char **map_data)
{
	t_map	*new_map;
	
	new_map = (t_map *)malloc(sizeof(t_map));
	if (!new_map)
	    return (NULL);
		//ft_error("Allocation error.", NULL);
	new_map->map = map_data;
	new_map->width = map_width(map_data);
	new_map->height = map_height(map_data);
	new_map->collectibles_count = 0;
	new_map->start_x = -1;
	new_map->start_y = -1;
	new_map->end_x = -1;
	new_map->end_y = -1;
	return (new_map);
}
