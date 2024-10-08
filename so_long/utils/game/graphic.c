/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:24:10 by sarherna          #+#    #+#             */
/*   Updated: 2024/10/08 10:28:21 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	render_img(t_game *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, img, x * 30, y * 30);
}

void	is_finished(t_game *data, int x, int y)
{
	if (data->collected == data->map->collectibles)
		render_img(data, data->img->start, x, y);
	else
		render_img(data, data->img->exit, x, y);
}

void	render_map(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			if (data->map->map[y][x] == '1')
				render_img(data, data->img->wall, x, y);
			else if (data->map->map[y][x] == '0')
				render_img(data, data->img->floor, x, y);
			else if (data->map->map[y][x] == 'C')
				render_img(data, data->img->collect, x, y);
			else if (data->map->map[y][x] == 'E')
				is_finished(data, x, y);
			else if (data->map->map[y][x] == 'P')
				render_img(data, data->img->player, x, y);
			x++;
		}
		y++;
	}
}

void	*load_file(t_game *data, char *filename)
{
	int		x;
	int		y;
	void	*p;

	p = mlx_xpm_file_to_image(data->mlx, filename, &x, &y);
	return (p);
}

void	load_sprites(t_game *data)
{
	data->img->floor = load_file(data, "assets/sprites/grass.xpm");
	data->img->wall = load_file(data, "assets/sprites/wall.xpm");
	data->img->exit = load_file(data, "assets/sprites/exit.xpm");
	data->img->start = load_file(data, "assets/sprites/start.xpm");
	data->img->collect = load_file(data, "assets/sprites/collectable.xpm");
	data->img->player = load_file(data, "assets/sprites/player.xpm");
}
