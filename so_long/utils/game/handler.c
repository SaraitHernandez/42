/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarherna <sarherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:07:45 by sarherna          #+#    #+#             */
/*   Updated: 2024/10/08 10:44:01 by sarherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

int	can_move(t_game *data, int new_x, int new_y)
{
	if (data->map->map[new_y][new_x] == '1')
		return (0);
	return (1);
}

void	move_player(t_game *data, int new_x, int new_y)
{
	if (can_move(data, new_x, new_y))
	{
		if (data->map->map[new_y][new_x] == 'C')
		{
			data->collected++;
			data->map->map[new_y][new_x] = '0';
		}
		if (data->map->map[new_y][new_x] == 'E'
			&& data->collected == data->map->collectibles)
		{
			printf("Congratulations! You won the game!\n");
			close_handler(data);
		}
		if (data->map->end_x == data->player_x
			&& data->map->end_y == data->player_y)
			data->map->map[data->player_y][data->player_x] = 'E';
		else
			data->map->map[data->player_y][data->player_x] = '0';
		data->map->map[new_y][new_x] = 'P';
		data->player_x = new_x;
		data->player_y = new_y;
		data->movements++;
		printf("Movements: %d\n", data->movements);
	}
	render_map(data);
}

int	key_handler(int keycode, t_game *data)
{
	if (keycode == 65307)
		close_handler(data);
	if (keycode == 'W' || keycode == 119)
		move_player(data, data->player_x, data->player_y - 1);
	else if (keycode == 'S' || keycode == 115)
		move_player(data, data->player_x, data->player_y + 1);
	else if (keycode == 'A' || keycode == 97)
		move_player(data, data->player_x - 1, data->player_y);
	else if (keycode == 'D' || keycode == 100)
		move_player(data, data->player_x + 1, data->player_y);
	return (0);
}

int	close_handler(t_game *data)
{
	free_game(data);
	exit(0);
	return (0);
}
