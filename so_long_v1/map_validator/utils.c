/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:52:28 by sarherna          #+#    #+#             */
/*   Updated: 2024/09/26 16:35:39 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validator.h"

int	map_width(char **map)
{
	int	width;

	width = 0;
	while (map[0][width] != '\0')
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

t_map	*create_map(char **map)
{
	t_map	*new_map;

	new_map = (t_map *)malloc(sizeof(t_map));
	if (!new_map)
		return (NULL);
	new_map->width = map_width(map);
	new_map->height = map_height(map);
	new_map->collectibles_count = 0;
	new_map->start_x = -1;
	new_map->start_y = -1;
	new_map->end_x = -1;
	new_map->end_y = -1;
	new_map->map = map;
	return (new_map);
}
