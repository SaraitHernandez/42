/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:24:10 by sarherna          #+#    #+#             */
/*   Updated: 2024/10/07 18:19:16 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

t_game	*game_constructor(t_map *map)
{
	t_game	*data;

	data = (t_game *)malloc(sizeof(t_game));
	data->mlx = NULL;
	data->win = NULL;
	data->movements = 0;
	data->collected = 0;
	data->map = map;
	data->player_x = map->start_x;
	data->player_y = map->start_y;
	data->img = (t_img *)malloc(sizeof(t_img));
	return (data);
}

void	init_game(t_game *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_error("Error initializing MLX", NULL);
	data->win = mlx_new_window(data->mlx, data->map->width * 30,
			data->map->height * 30, "so_long");
	if (!data->win)
		ft_error("Error creating window", NULL);
	load_sprites(data);
	render_map(data);
	mlx_key_hook(data->win, key_handler, data);
	mlx_hook(data->win, 17, 0, close_handler, data);
}
