/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:49:01 by sarherna          #+#    #+#             */
/*   Updated: 2024/10/08 10:34:33 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_doble_array(char **arr)
{
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
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
}

void	free_visited_array(int **visited, int height)
{
	int	i;

	if (!visited)
		return ;
	i = 0;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

void	free_img(t_game *game)
{
	if (game->img)
	{
		if (game->img->wall)
			mlx_destroy_image(game->mlx, game->img->wall);
		if (game->img->floor)
			mlx_destroy_image(game->mlx, game->img->floor);
		if (game->img->collect)
			mlx_destroy_image(game->mlx, game->img->collect);
		if (game->img->exit)
			mlx_destroy_image(game->mlx, game->img->exit);
		if (game->img->start)
			mlx_destroy_image(game->mlx, game->img->start);
		if (game->img->player)
			mlx_destroy_image(game->mlx, game->img->player);
		free(game->img);
	}
}

void	free_game(t_game *game)
{
	if (game)
	{
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		free_img(game);
		mlx_destroy_display(game->mlx);
		free_map(game->map);
		free(game->mlx);
		free(game);
	}
}
