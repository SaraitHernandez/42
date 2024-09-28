/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarait.hernandez@novateva.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:49:01 by sarherna          #+#    #+#             */
/*   Updated: 2024/09/27 16:59:00 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void free_doble_array(char **arr){
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_map(t_map *map)
{
	for (int i = 0; i < map->height; i++)
		free(map->map[i]);
	free(map->map);
	free(map);
}